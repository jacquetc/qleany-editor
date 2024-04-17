// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "single_entity.h"
#include "entity/entity_interactor.h"
#include "event_dispatcher.h"

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Presenter;

SingleEntity::SingleEntity(QObject *parent)
    : QObject{parent}
{
    connect(EventDispatcher::instance()->entity(), &EntitySignals::removed, this, [this](QList<int> removedIds) {
        if (removedIds.contains(id())) {
            resetId();
        }
    });
    connect(EventDispatcher::instance()->entity(), &EntitySignals::updated, this, [this](EntityDTO dto) {
        if (dto.id() == id()) {
            if (m_id != dto.id()) {
                m_id = dto.id();
                Q_EMIT idChanged();
            }
            if (m_uuid != dto.uuid()) {
                m_uuid = dto.uuid();
                Q_EMIT uuidChanged();
            }
            if (m_creationDate != dto.creationDate()) {
                m_creationDate = dto.creationDate();
                Q_EMIT creationDateChanged();
            }
            if (m_updateDate != dto.updateDate()) {
                m_updateDate = dto.updateDate();
                Q_EMIT updateDateChanged();
            }
            if (m_name != dto.name()) {
                m_name = dto.name();
                Q_EMIT nameChanged();
            }
            if (m_onlyForHeritage != dto.onlyForHeritage()) {
                m_onlyForHeritage = dto.onlyForHeritage();
                Q_EMIT onlyForHeritageChanged();
            }
        }
    });
}

int SingleEntity::id() const
{
    return m_id;
}

void SingleEntity::setId(int newId)
{
    if (m_id == newId)
        return;
    m_id = newId;
    Q_EMIT idChanged();

    // clear
    if (m_id == 0) {
        m_uuid = QUuid{};
        Q_EMIT uuidChanged();

        m_creationDate = QDateTime{};
        Q_EMIT creationDateChanged();

        m_updateDate = QDateTime{};
        Q_EMIT updateDateChanged();

        m_name = QString{};
        Q_EMIT nameChanged();

        m_onlyForHeritage = bool{};
        Q_EMIT onlyForHeritageChanged();

    }

    // set
    else {
        Entity::EntityInteractor::instance()->get(m_id).then([this](const QleanyEditor::Contracts::DTO::Entity::EntityDTO &entity) {
            if (entity.isInvalid()) {
                qCritical() << Q_FUNC_INFO << "Invalid entityId";
                return;
            }

            m_uuid = entity.uuid();
            Q_EMIT uuidChanged();

            m_creationDate = entity.creationDate();
            Q_EMIT creationDateChanged();

            m_updateDate = entity.updateDate();
            Q_EMIT updateDateChanged();

            m_name = entity.name();
            Q_EMIT nameChanged();

            m_onlyForHeritage = entity.onlyForHeritage();
            Q_EMIT onlyForHeritageChanged();
        });
    }
}

void SingleEntity::resetId()
{
    setId(0);
}

QUuid SingleEntity::uuid() const
{
    return m_uuid;
}

void SingleEntity::setUuid(const QUuid &newUuid)
{
    if (m_uuid == newUuid)
        return;

    UpdateEntityDTO dto;
    dto.setId(id());
    dto.setUuid(newUuid);
    Entity::EntityInteractor::instance()->update(dto).then([this](const QleanyEditor::Contracts::DTO::Entity::EntityDTO &entity) {
        if (entity.isInvalid()) {
            qCritical() << Q_FUNC_INFO << "Invalid entityId";
            return;
        }
        m_uuid = entity.uuid();
        Q_EMIT uuidChanged();
    });
}

QDateTime SingleEntity::creationDate() const
{
    return m_creationDate;
}

void SingleEntity::setCreationDate(const QDateTime &newCreationDate)
{
    if (m_creationDate == newCreationDate)
        return;

    UpdateEntityDTO dto;
    dto.setId(id());
    dto.setCreationDate(newCreationDate);
    Entity::EntityInteractor::instance()->update(dto).then([this](const QleanyEditor::Contracts::DTO::Entity::EntityDTO &entity) {
        if (entity.isInvalid()) {
            qCritical() << Q_FUNC_INFO << "Invalid entityId";
            return;
        }
        m_creationDate = entity.creationDate();
        Q_EMIT creationDateChanged();
    });
}

QDateTime SingleEntity::updateDate() const
{
    return m_updateDate;
}

void SingleEntity::setUpdateDate(const QDateTime &newUpdateDate)
{
    if (m_updateDate == newUpdateDate)
        return;

    UpdateEntityDTO dto;
    dto.setId(id());
    dto.setUpdateDate(newUpdateDate);
    Entity::EntityInteractor::instance()->update(dto).then([this](const QleanyEditor::Contracts::DTO::Entity::EntityDTO &entity) {
        if (entity.isInvalid()) {
            qCritical() << Q_FUNC_INFO << "Invalid entityId";
            return;
        }
        m_updateDate = entity.updateDate();
        Q_EMIT updateDateChanged();
    });
}

QString SingleEntity::name() const
{
    return m_name;
}

void SingleEntity::setName(const QString &newName)
{
    if (m_name == newName)
        return;

    UpdateEntityDTO dto;
    dto.setId(id());
    dto.setName(newName);
    Entity::EntityInteractor::instance()->update(dto).then([this](const QleanyEditor::Contracts::DTO::Entity::EntityDTO &entity) {
        if (entity.isInvalid()) {
            qCritical() << Q_FUNC_INFO << "Invalid entityId";
            return;
        }
        m_name = entity.name();
        Q_EMIT nameChanged();
    });
}

bool SingleEntity::onlyForHeritage() const
{
    return m_onlyForHeritage;
}

void SingleEntity::setOnlyForHeritage(bool newOnlyForHeritage)
{
    if (m_onlyForHeritage == newOnlyForHeritage)
        return;

    UpdateEntityDTO dto;
    dto.setId(id());
    dto.setOnlyForHeritage(newOnlyForHeritage);
    Entity::EntityInteractor::instance()->update(dto).then([this](const QleanyEditor::Contracts::DTO::Entity::EntityDTO &entity) {
        if (entity.isInvalid()) {
            qCritical() << Q_FUNC_INFO << "Invalid entityId";
            return;
        }
        m_onlyForHeritage = entity.onlyForHeritage();
        Q_EMIT onlyForHeritageChanged();
    });
}
