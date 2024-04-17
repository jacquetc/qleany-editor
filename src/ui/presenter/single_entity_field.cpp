// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "single_entity_field.h"
#include "entity_field/entity_field_interactor.h"
#include "event_dispatcher.h"

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Presenter;

SingleEntityField::SingleEntityField(QObject *parent)
    : QObject{parent}
{
    connect(EventDispatcher::instance()->entityField(), &EntityFieldSignals::removed, this, [this](QList<int> removedIds) {
        if (removedIds.contains(id())) {
            resetId();
        }
    });
    connect(EventDispatcher::instance()->entityField(), &EntityFieldSignals::updated, this, [this](EntityFieldDTO dto) {
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
            if (m_type != dto.type()) {
                m_type = dto.type();
                Q_EMIT typeChanged();
            }
            if (m_name != dto.name()) {
                m_name = dto.name();
                Q_EMIT nameChanged();
            }
            if (m_ordered != dto.ordered()) {
                m_ordered = dto.ordered();
                Q_EMIT orderedChanged();
            }
            if (m_strong != dto.strong()) {
                m_strong = dto.strong();
                Q_EMIT strongChanged();
            }
        }
    });
}

int SingleEntityField::id() const
{
    return m_id;
}

void SingleEntityField::setId(int newId)
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

        m_type = QString{};
        Q_EMIT typeChanged();

        m_name = QString{};
        Q_EMIT nameChanged();

        m_ordered = bool{};
        Q_EMIT orderedChanged();

        m_strong = bool{};
        Q_EMIT strongChanged();

    }

    // set
    else {
        EntityField::EntityFieldInteractor::instance()->get(m_id).then([this](const QleanyEditor::Contracts::DTO::EntityField::EntityFieldDTO &entityField) {
            if (entityField.isInvalid()) {
                qCritical() << Q_FUNC_INFO << "Invalid entityFieldId";
                return;
            }

            m_uuid = entityField.uuid();
            Q_EMIT uuidChanged();

            m_creationDate = entityField.creationDate();
            Q_EMIT creationDateChanged();

            m_updateDate = entityField.updateDate();
            Q_EMIT updateDateChanged();

            m_type = entityField.type();
            Q_EMIT typeChanged();

            m_name = entityField.name();
            Q_EMIT nameChanged();

            m_ordered = entityField.ordered();
            Q_EMIT orderedChanged();

            m_strong = entityField.strong();
            Q_EMIT strongChanged();
        });
    }
}

void SingleEntityField::resetId()
{
    setId(0);
}

QUuid SingleEntityField::uuid() const
{
    return m_uuid;
}

void SingleEntityField::setUuid(const QUuid &newUuid)
{
    if (m_uuid == newUuid)
        return;

    UpdateEntityFieldDTO dto;
    dto.setId(id());
    dto.setUuid(newUuid);
    EntityField::EntityFieldInteractor::instance()->update(dto).then([this](const QleanyEditor::Contracts::DTO::EntityField::EntityFieldDTO &entityField) {
        if (entityField.isInvalid()) {
            qCritical() << Q_FUNC_INFO << "Invalid entityFieldId";
            return;
        }
        m_uuid = entityField.uuid();
        Q_EMIT uuidChanged();
    });
}

QDateTime SingleEntityField::creationDate() const
{
    return m_creationDate;
}

void SingleEntityField::setCreationDate(const QDateTime &newCreationDate)
{
    if (m_creationDate == newCreationDate)
        return;

    UpdateEntityFieldDTO dto;
    dto.setId(id());
    dto.setCreationDate(newCreationDate);
    EntityField::EntityFieldInteractor::instance()->update(dto).then([this](const QleanyEditor::Contracts::DTO::EntityField::EntityFieldDTO &entityField) {
        if (entityField.isInvalid()) {
            qCritical() << Q_FUNC_INFO << "Invalid entityFieldId";
            return;
        }
        m_creationDate = entityField.creationDate();
        Q_EMIT creationDateChanged();
    });
}

QDateTime SingleEntityField::updateDate() const
{
    return m_updateDate;
}

void SingleEntityField::setUpdateDate(const QDateTime &newUpdateDate)
{
    if (m_updateDate == newUpdateDate)
        return;

    UpdateEntityFieldDTO dto;
    dto.setId(id());
    dto.setUpdateDate(newUpdateDate);
    EntityField::EntityFieldInteractor::instance()->update(dto).then([this](const QleanyEditor::Contracts::DTO::EntityField::EntityFieldDTO &entityField) {
        if (entityField.isInvalid()) {
            qCritical() << Q_FUNC_INFO << "Invalid entityFieldId";
            return;
        }
        m_updateDate = entityField.updateDate();
        Q_EMIT updateDateChanged();
    });
}

QString SingleEntityField::type() const
{
    return m_type;
}

void SingleEntityField::setType(const QString &newType)
{
    if (m_type == newType)
        return;

    UpdateEntityFieldDTO dto;
    dto.setId(id());
    dto.setType(newType);
    EntityField::EntityFieldInteractor::instance()->update(dto).then([this](const QleanyEditor::Contracts::DTO::EntityField::EntityFieldDTO &entityField) {
        if (entityField.isInvalid()) {
            qCritical() << Q_FUNC_INFO << "Invalid entityFieldId";
            return;
        }
        m_type = entityField.type();
        Q_EMIT typeChanged();
    });
}

QString SingleEntityField::name() const
{
    return m_name;
}

void SingleEntityField::setName(const QString &newName)
{
    if (m_name == newName)
        return;

    UpdateEntityFieldDTO dto;
    dto.setId(id());
    dto.setName(newName);
    EntityField::EntityFieldInteractor::instance()->update(dto).then([this](const QleanyEditor::Contracts::DTO::EntityField::EntityFieldDTO &entityField) {
        if (entityField.isInvalid()) {
            qCritical() << Q_FUNC_INFO << "Invalid entityFieldId";
            return;
        }
        m_name = entityField.name();
        Q_EMIT nameChanged();
    });
}

bool SingleEntityField::ordered() const
{
    return m_ordered;
}

void SingleEntityField::setOrdered(bool newOrdered)
{
    if (m_ordered == newOrdered)
        return;

    UpdateEntityFieldDTO dto;
    dto.setId(id());
    dto.setOrdered(newOrdered);
    EntityField::EntityFieldInteractor::instance()->update(dto).then([this](const QleanyEditor::Contracts::DTO::EntityField::EntityFieldDTO &entityField) {
        if (entityField.isInvalid()) {
            qCritical() << Q_FUNC_INFO << "Invalid entityFieldId";
            return;
        }
        m_ordered = entityField.ordered();
        Q_EMIT orderedChanged();
    });
}

bool SingleEntityField::strong() const
{
    return m_strong;
}

void SingleEntityField::setStrong(bool newStrong)
{
    if (m_strong == newStrong)
        return;

    UpdateEntityFieldDTO dto;
    dto.setId(id());
    dto.setStrong(newStrong);
    EntityField::EntityFieldInteractor::instance()->update(dto).then([this](const QleanyEditor::Contracts::DTO::EntityField::EntityFieldDTO &entityField) {
        if (entityField.isInvalid()) {
            qCritical() << Q_FUNC_INFO << "Invalid entityFieldId";
            return;
        }
        m_strong = entityField.strong();
        Q_EMIT strongChanged();
    });
}
