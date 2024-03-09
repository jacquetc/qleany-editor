// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "single_global_component.h"
#include "event_dispatcher.h"
#include "global_component/global_component_interactor.h"

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Presenter;

SingleGlobalComponent::SingleGlobalComponent(QObject *parent)
    : QObject{parent}
{
    connect(EventDispatcher::instance()->globalComponent(), &GlobalComponentSignals::removed, this, [this](QList<int> removedIds) {
        if (removedIds.contains(id())) {
            resetId();
        }
    });
    connect(EventDispatcher::instance()->globalComponent(), &GlobalComponentSignals::updated, this, [this](GlobalComponentDTO dto) {
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
            if (m_applicationName != dto.applicationName()) {
                m_applicationName = dto.applicationName();
                Q_EMIT applicationNameChanged();
            }
            if (m_applicationCppDomainName != dto.applicationCppDomainName()) {
                m_applicationCppDomainName = dto.applicationCppDomainName();
                Q_EMIT applicationCppDomainNameChanged();
            }
            if (m_organisationName != dto.organisationName()) {
                m_organisationName = dto.organisationName();
                Q_EMIT organisationNameChanged();
            }
            if (m_organisationDomain != dto.organisationDomain()) {
                m_organisationDomain = dto.organisationDomain();
                Q_EMIT organisationDomainChanged();
            }
        }
    });
}

int SingleGlobalComponent::id() const
{
    return m_id;
}

void SingleGlobalComponent::setId(int newId)
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

        m_applicationName = QString{};
        Q_EMIT applicationNameChanged();

        m_applicationCppDomainName = QString{};
        Q_EMIT applicationCppDomainNameChanged();

        m_organisationName = QString{};
        Q_EMIT organisationNameChanged();

        m_organisationDomain = QString{};
        Q_EMIT organisationDomainChanged();

    }

    // set
    else {
        GlobalComponent::GlobalComponentInteractor::instance()->get(m_id).then(
            [this](const QleanyEditor::Contracts::DTO::GlobalComponent::GlobalComponentDTO &globalComponent) {
                if (globalComponent.isInvalid()) {
                    qCritical() << Q_FUNC_INFO << "Invalid globalComponentId";
                    return;
                }

                m_uuid = globalComponent.uuid();
                Q_EMIT uuidChanged();

                m_creationDate = globalComponent.creationDate();
                Q_EMIT creationDateChanged();

                m_updateDate = globalComponent.updateDate();
                Q_EMIT updateDateChanged();

                m_applicationName = globalComponent.applicationName();
                Q_EMIT applicationNameChanged();

                m_applicationCppDomainName = globalComponent.applicationCppDomainName();
                Q_EMIT applicationCppDomainNameChanged();

                m_organisationName = globalComponent.organisationName();
                Q_EMIT organisationNameChanged();

                m_organisationDomain = globalComponent.organisationDomain();
                Q_EMIT organisationDomainChanged();
            });
    }
}

void SingleGlobalComponent::resetId()
{
    setId(0);
}

QUuid SingleGlobalComponent::uuid() const
{
    return m_uuid;
}

void SingleGlobalComponent::setUuid(const QUuid &newUuid)
{
    if (m_uuid == newUuid)
        return;

    UpdateGlobalComponentDTO dto;
    dto.setId(id());
    dto.setUuid(newUuid);
    GlobalComponent::GlobalComponentInteractor::instance()->update(dto).then(
        [this](const QleanyEditor::Contracts::DTO::GlobalComponent::GlobalComponentDTO &globalComponent) {
            if (globalComponent.isInvalid()) {
                qCritical() << Q_FUNC_INFO << "Invalid globalComponentId";
                return;
            }
            m_uuid = globalComponent.uuid();
            Q_EMIT uuidChanged();
        });
}

QDateTime SingleGlobalComponent::creationDate() const
{
    return m_creationDate;
}

void SingleGlobalComponent::setCreationDate(const QDateTime &newCreationDate)
{
    if (m_creationDate == newCreationDate)
        return;

    UpdateGlobalComponentDTO dto;
    dto.setId(id());
    dto.setCreationDate(newCreationDate);
    GlobalComponent::GlobalComponentInteractor::instance()->update(dto).then(
        [this](const QleanyEditor::Contracts::DTO::GlobalComponent::GlobalComponentDTO &globalComponent) {
            if (globalComponent.isInvalid()) {
                qCritical() << Q_FUNC_INFO << "Invalid globalComponentId";
                return;
            }
            m_creationDate = globalComponent.creationDate();
            Q_EMIT creationDateChanged();
        });
}

QDateTime SingleGlobalComponent::updateDate() const
{
    return m_updateDate;
}

void SingleGlobalComponent::setUpdateDate(const QDateTime &newUpdateDate)
{
    if (m_updateDate == newUpdateDate)
        return;

    UpdateGlobalComponentDTO dto;
    dto.setId(id());
    dto.setUpdateDate(newUpdateDate);
    GlobalComponent::GlobalComponentInteractor::instance()->update(dto).then(
        [this](const QleanyEditor::Contracts::DTO::GlobalComponent::GlobalComponentDTO &globalComponent) {
            if (globalComponent.isInvalid()) {
                qCritical() << Q_FUNC_INFO << "Invalid globalComponentId";
                return;
            }
            m_updateDate = globalComponent.updateDate();
            Q_EMIT updateDateChanged();
        });
}

QString SingleGlobalComponent::applicationName() const
{
    return m_applicationName;
}

void SingleGlobalComponent::setApplicationName(const QString &newApplicationName)
{
    if (m_applicationName == newApplicationName)
        return;

    UpdateGlobalComponentDTO dto;
    dto.setId(id());
    dto.setApplicationName(newApplicationName);
    GlobalComponent::GlobalComponentInteractor::instance()->update(dto).then(
        [this](const QleanyEditor::Contracts::DTO::GlobalComponent::GlobalComponentDTO &globalComponent) {
            if (globalComponent.isInvalid()) {
                qCritical() << Q_FUNC_INFO << "Invalid globalComponentId";
                return;
            }
            m_applicationName = globalComponent.applicationName();
            Q_EMIT applicationNameChanged();
        });
}

QString SingleGlobalComponent::applicationCppDomainName() const
{
    return m_applicationCppDomainName;
}

void SingleGlobalComponent::setApplicationCppDomainName(const QString &newApplicationCppDomainName)
{
    if (m_applicationCppDomainName == newApplicationCppDomainName)
        return;

    UpdateGlobalComponentDTO dto;
    dto.setId(id());
    dto.setApplicationCppDomainName(newApplicationCppDomainName);
    GlobalComponent::GlobalComponentInteractor::instance()->update(dto).then(
        [this](const QleanyEditor::Contracts::DTO::GlobalComponent::GlobalComponentDTO &globalComponent) {
            if (globalComponent.isInvalid()) {
                qCritical() << Q_FUNC_INFO << "Invalid globalComponentId";
                return;
            }
            m_applicationCppDomainName = globalComponent.applicationCppDomainName();
            Q_EMIT applicationCppDomainNameChanged();
        });
}

QString SingleGlobalComponent::organisationName() const
{
    return m_organisationName;
}

void SingleGlobalComponent::setOrganisationName(const QString &newOrganisationName)
{
    if (m_organisationName == newOrganisationName)
        return;

    UpdateGlobalComponentDTO dto;
    dto.setId(id());
    dto.setOrganisationName(newOrganisationName);
    GlobalComponent::GlobalComponentInteractor::instance()->update(dto).then(
        [this](const QleanyEditor::Contracts::DTO::GlobalComponent::GlobalComponentDTO &globalComponent) {
            if (globalComponent.isInvalid()) {
                qCritical() << Q_FUNC_INFO << "Invalid globalComponentId";
                return;
            }
            m_organisationName = globalComponent.organisationName();
            Q_EMIT organisationNameChanged();
        });
}

QString SingleGlobalComponent::organisationDomain() const
{
    return m_organisationDomain;
}

void SingleGlobalComponent::setOrganisationDomain(const QString &newOrganisationDomain)
{
    if (m_organisationDomain == newOrganisationDomain)
        return;

    UpdateGlobalComponentDTO dto;
    dto.setId(id());
    dto.setOrganisationDomain(newOrganisationDomain);
    GlobalComponent::GlobalComponentInteractor::instance()->update(dto).then(
        [this](const QleanyEditor::Contracts::DTO::GlobalComponent::GlobalComponentDTO &globalComponent) {
            if (globalComponent.isInvalid()) {
                qCritical() << Q_FUNC_INFO << "Invalid globalComponentId";
                return;
            }
            m_organisationDomain = globalComponent.organisationDomain();
            Q_EMIT organisationDomainChanged();
        });
}
