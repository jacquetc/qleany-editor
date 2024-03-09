#include "entity_list_model_from_entity_component_entities.h"
#include "entity/entity_interactor.h"
#include "entity_component/entity_component_interactor.h"
#include "event_dispatcher.h"
#include <QCoroTask>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Presenter;

EntityListModelFromEntityComponentEntities::EntityListModelFromEntityComponentEntities(QObject *parent)
    : QAbstractListModel(parent)
{
    connect(EventDispatcher::instance()->entityComponent(), &EntityComponentSignals::allRelationsInvalidated, this, [this](int entityComponentId) {
        if (entityComponentId == m_entityComponentId) {
            return;
        }
        auto task = EntityComponent::EntityComponentInteractor::instance()->getWithDetails(entityComponentId);
        QCoro::connect(std::move(task), this, [this, entityComponentId](auto &&entityComponentDetails) {
            if (entityComponentDetails.isInvalid()) {
                qCritical() << Q_FUNC_INFO << "Invalid entityComponentId";
                return;
            }
            QList<EntityDTO> newEntityList = entityComponentDetails.entities();
            QList<int> newEntityIdList;
            for (const auto &entity : newEntityList) {
                newEntityIdList.append(entity.id());
            }

            // first, add the missing entities
            for (const auto &entity : newEntityList) {
                if (!m_entityIdList.contains(entity.id())) {
                    // add the entity
                    int row = m_entityList.size();
                    beginInsertRows(QModelIndex(), row, row);
                    m_entityList.append(entity);
                    m_entityIdList.append(entity.id());
                    endInsertRows();
                }
            }

            // then, remove the entityList that are not in the new list

            for (int i = m_entityList.size() - 1; i >= 0; --i) {
                if (!newEntityIdList.contains(m_entityList[i].id())) {
                    // remove the entity
                    beginRemoveRows(QModelIndex(), i, i);
                    m_entityList.removeAt(i);
                    m_entityIdList.removeAt(i);
                    endRemoveRows();
                }
            }
            // then, move the current ones so the list is in the same order as the new list

            for (int i = 0; i < m_entityList.size(); ++i) {
                if (m_entityIdList[i] != newEntityList[i].id()) {
                    // move the entity
                    int row = newEntityList.indexOf(m_entityList[i]);
                    beginMoveRows(QModelIndex(), i, i, QModelIndex(), row);
                    m_entityList.move(i, row);
                    m_entityIdList.move(i, row);
                    endMoveRows();
                }
            }

            // finally, update those that are in both lists if the updateDateDate has changed

            for (int i = 0; i < m_entityList.size(); ++i) {
                if (m_entityList[i].updateDate() != newEntityList[i].updateDate()) {
                    // update the entity
                    m_entityList[i] = newEntityList[i];
                    QModelIndex topLeft = index(i, 0);
                    QModelIndex bottomRight = index(i, 0);
                    Q_EMIT dataChanged(topLeft, bottomRight);
                }
            }

            return;
        });

        populate();
    });

    connect(EventDispatcher::instance()->entityComponent(), &EntityComponentSignals::relationRemoved, this, [this](EntityComponentRelationDTO dto) {
        if (dto.relationField() != EntityComponentRelationDTO::RelationField::Entities) {
            return;
        }

        // remove the entity list
        QList<int> relatedIds = dto.relatedIds();

        for (int id : relatedIds) {
            if (!m_entityIdList.contains(id)) {
                continue;
            }

            int index = m_entityIdList.indexOf(id);
            if (index != -1) {
                beginRemoveRows(QModelIndex(), index, index);
                m_entityList.removeAt(index);
                m_entityIdList.removeAt(index);
                endRemoveRows();
            }
        }
    });

    connect(EventDispatcher::instance()->entityComponent(), &EntityComponentSignals::relationInserted, this, [this](EntityComponentRelationDTO dto) {
        if (dto.id() != m_entityComponentId || dto.relationField() != EntityComponentRelationDTO::RelationField::Entities) {
            return;
        }

        int position = dto.position();

        // reverse dto.relatedIds()
        QList<int> relatedIds = dto.relatedIds();
        std::reverse(relatedIds.begin(), relatedIds.end());

        // fetch entity list from interactor
        for (int entityId : relatedIds) {
            Entity::EntityInteractor::instance()->get(entityId).then([this, entityId, position](EntityDTO entity) {
                // add entity to this model
                if (!m_entityIdList.contains(entityId)) {
                    beginInsertRows(QModelIndex(), position, position);
                    m_entityList.insert(position, entity);
                    m_entityIdList.insert(position, entityId);
                    endInsertRows();
                }
            });
        }
    });

    connect(EventDispatcher::instance()->entity(), &EntitySignals::updated, this, [this](EntityDTO dto) {
        for (int i = 0; i < m_entityList.size(); ++i) {
            if (m_entityIdList.at(i) == dto.id()) {
                m_entityList[i] = dto;
                m_entityIdList[i] = dto.id();
                Q_EMIT dataChanged(index(i), index(i));
                break;
            }
        }
    });
}

QVariant EntityListModelFromEntityComponentEntities::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}

int EntityListModelFromEntityComponentEntities::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return m_entityList.count();
}

QVariant EntityListModelFromEntityComponentEntities::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();
    if (row >= m_entityList.size())
        return QVariant();

    const EntityDTO &entity = m_entityList.at(index.row());

    if (role == Qt::DisplayRole) {
        return entity.name();
    }
    if (role == Qt::EditRole) {
        return entity.name();
    }

    else if (role == IdRole)
        return entity.id();
    else if (role == UuidRole)
        return entity.uuid();
    else if (role == CreationDateRole)
        return entity.creationDate();
    else if (role == UpdateDateRole)
        return entity.updateDate();
    else if (role == NameRole)
        return entity.name();

    return QVariant();
}

Qt::ItemFlags EntityListModelFromEntityComponentEntities::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}

bool EntityListModelFromEntityComponentEntities::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
        return false;

    int row = index.row();
    if (row >= m_entityList.size())
        return false;

    else if (role == Qt::EditRole) {
        return this->setData(index, value, NameRole);
    }

    else if (role == IdRole) {
        if (value.canConvert<int>() == false) {
            qCritical() << "Cannot convert value to int";
            return false;
        }

        const EntityDTO &entity = m_entityList[row];

        UpdateEntityDTO dto;
        dto.setId(entity.id());
        dto.setId(value.value<int>());

        Entity::EntityInteractor::instance()->update(dto).then([this, index, role](auto &&result) {
            if (result.isInvalid()) {
                qCritical() << Q_FUNC_INFO << "Invalid entityComponent";
                return false;
            }
            Q_EMIT dataChanged(index, index, {role});
            return true;
        });

        return true;
    } else if (role == UuidRole) {
        if (value.canConvert<QUuid>() == false) {
            qCritical() << "Cannot convert value to QUuid";
            return false;
        }

        const EntityDTO &entity = m_entityList[row];

        UpdateEntityDTO dto;
        dto.setId(entity.id());
        dto.setUuid(value.value<QUuid>());

        Entity::EntityInteractor::instance()->update(dto).then([this, index, role](auto &&result) {
            if (result.isInvalid()) {
                qCritical() << Q_FUNC_INFO << "Invalid entityComponent";
                return false;
            }
            Q_EMIT dataChanged(index, index, {role});
            return true;
        });

        return true;
    } else if (role == CreationDateRole) {
        if (value.canConvert<QDateTime>() == false) {
            qCritical() << "Cannot convert value to QDateTime";
            return false;
        }

        const EntityDTO &entity = m_entityList[row];

        UpdateEntityDTO dto;
        dto.setId(entity.id());
        dto.setCreationDate(value.value<QDateTime>());

        Entity::EntityInteractor::instance()->update(dto).then([this, index, role](auto &&result) {
            if (result.isInvalid()) {
                qCritical() << Q_FUNC_INFO << "Invalid entityComponent";
                return false;
            }
            Q_EMIT dataChanged(index, index, {role});
            return true;
        });

        return true;
    } else if (role == UpdateDateRole) {
        if (value.canConvert<QDateTime>() == false) {
            qCritical() << "Cannot convert value to QDateTime";
            return false;
        }

        const EntityDTO &entity = m_entityList[row];

        UpdateEntityDTO dto;
        dto.setId(entity.id());
        dto.setUpdateDate(value.value<QDateTime>());

        Entity::EntityInteractor::instance()->update(dto).then([this, index, role](auto &&result) {
            if (result.isInvalid()) {
                qCritical() << Q_FUNC_INFO << "Invalid entityComponent";
                return false;
            }
            Q_EMIT dataChanged(index, index, {role});
            return true;
        });

        return true;
    } else if (role == NameRole) {
        if (value.canConvert<QString>() == false) {
            qCritical() << "Cannot convert value to QString";
            return false;
        }

        const EntityDTO &entity = m_entityList[row];

        UpdateEntityDTO dto;
        dto.setId(entity.id());
        dto.setName(value.value<QString>());

        Entity::EntityInteractor::instance()->update(dto).then([this, index, role](auto &&result) {
            if (result.isInvalid()) {
                qCritical() << Q_FUNC_INFO << "Invalid entityComponent";
                return false;
            }
            Q_EMIT dataChanged(index, index, {role});
            return true;
        });

        return true;
    }

    return false;
}

void EntityListModelFromEntityComponentEntities::populate()
{
    if (m_entityComponentId == 0)
        return;
    beginResetModel();
    m_entityList.clear();
    m_entityIdList.clear();
    endResetModel();

    auto task = EntityComponent::EntityComponentInteractor::instance()->getWithDetails(m_entityComponentId);
    QCoro::connect(std::move(task), this, [this](auto &&result) {
        const QList<QleanyEditor::Contracts::DTO::Entity::EntityDTO> entityList = result.entities();
        for (const auto &entity : entityList) {
            if (entity.isInvalid()) {
                qCritical() << Q_FUNC_INFO << "Invalid entity";
                return;
            }
        }
        if (entityList.isEmpty()) {
            return;
        }
        beginInsertRows(QModelIndex(), 0, entityList.size() - 1);
        m_entityList = entityList;
        // fill m_entityIdList
        for (const auto &entity : entityList) {
            m_entityIdList.append(entity.id());
        }

        endInsertRows();
    });
}

int EntityListModelFromEntityComponentEntities::entityComponentId() const
{
    return m_entityComponentId;
}

void EntityListModelFromEntityComponentEntities::setEntityComponentId(int newEntityComponentId)
{
    if (m_entityComponentId == newEntityComponentId)
        return;
    m_entityComponentId = newEntityComponentId;

    if (m_entityComponentId == 0) {
        beginResetModel();
        m_entityList.clear();
        m_entityIdList.clear();
        endResetModel();
    } else {
        populate();
    }
    Q_EMIT entityComponentIdChanged();
}

void EntityListModelFromEntityComponentEntities::resetEntityComponentId()
{
    setEntityComponentId(0);
}

QHash<int, QByteArray> EntityListModelFromEntityComponentEntities::roleNames() const
{
    QHash<int, QByteArray> names;

    // renaming id to itemId to avoid conflict with QML's id
    names[IdRole] = "itemId";
    names[UuidRole] = "uuid";
    names[CreationDateRole] = "creationDate";
    names[UpdateDateRole] = "updateDate";
    names[NameRole] = "name";
    return names;
}