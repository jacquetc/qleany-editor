#include "event_dispatcher.h"

using namespace QleanyEditor::Interactor;

QPointer<EventDispatcher> EventDispatcher::s_instance = nullptr;

EventDispatcher::EventDispatcher()
    : QObject{nullptr}
{
    m_errorSignals = new ErrorSignals(this);
    m_progressSignals = new ProgressSignals(this);

    m_rootSignals = new RootSignals(this);
    m_recentProjectSignals = new RecentProjectSignals(this);
    m_projectSignals = new ProjectSignals(this);
    m_globalComponentSignals = new GlobalComponentSignals(this);
    m_entityComponentSignals = new EntityComponentSignals(this);
    m_entitySignals = new EntitySignals(this);
    m_entityFieldSignals = new EntityFieldSignals(this);
    m_entityParentSignals = new EntityParentSignals(this);
    m_repositoryComponentSignals = new RepositoryComponentSignals(this);
    m_repositorySignals = new RepositorySignals(this);
    m_interactorComponentSignals = new InteractorComponentSignals(this);
    m_applicationComponentSignals = new ApplicationComponentSignals(this);
    m_applicationFeatureSignals = new ApplicationFeatureSignals(this);
    m_cRUDSignals = new CRUDSignals(this);
    m_customCommandSignals = new CustomCommandSignals(this);
    m_customDTOSignals = new CustomDTOSignals(this);
    m_customDTOFieldSignals = new CustomDTOFieldSignals(this);
    m_customQuerySignals = new CustomQuerySignals(this);
    m_dTOComponentSignals = new DTOComponentSignals(this);
    m_cQRSComponentSignals = new CQRSComponentSignals(this);
    m_contractsComponentSignals = new ContractsComponentSignals(this);
    m_presenterComponentSignals = new PresenterComponentSignals(this);
    m_presenterSingleSignals = new PresenterSingleSignals(this);
    m_presenterListModelSignals = new PresenterListModelSignals(this);
    m_frontEndComponentSignals = new FrontEndComponentSignals(this);

    s_instance = this;
}

EventDispatcher *EventDispatcher::instance()
{
    return s_instance;
}

RootSignals *EventDispatcher::root() const
{
    return m_rootSignals;
}

RecentProjectSignals *EventDispatcher::recentProject() const
{
    return m_recentProjectSignals;
}

ProjectSignals *EventDispatcher::project() const
{
    return m_projectSignals;
}

GlobalComponentSignals *EventDispatcher::globalComponent() const
{
    return m_globalComponentSignals;
}

EntityComponentSignals *EventDispatcher::entityComponent() const
{
    return m_entityComponentSignals;
}

EntitySignals *EventDispatcher::entity() const
{
    return m_entitySignals;
}

EntityFieldSignals *EventDispatcher::entityField() const
{
    return m_entityFieldSignals;
}

EntityParentSignals *EventDispatcher::entityParent() const
{
    return m_entityParentSignals;
}

RepositoryComponentSignals *EventDispatcher::repositoryComponent() const
{
    return m_repositoryComponentSignals;
}

RepositorySignals *EventDispatcher::repository() const
{
    return m_repositorySignals;
}

InteractorComponentSignals *EventDispatcher::interactorComponent() const
{
    return m_interactorComponentSignals;
}

ApplicationComponentSignals *EventDispatcher::applicationComponent() const
{
    return m_applicationComponentSignals;
}

ApplicationFeatureSignals *EventDispatcher::applicationFeature() const
{
    return m_applicationFeatureSignals;
}

CRUDSignals *EventDispatcher::cRUD() const
{
    return m_cRUDSignals;
}

CustomCommandSignals *EventDispatcher::customCommand() const
{
    return m_customCommandSignals;
}

CustomDTOSignals *EventDispatcher::customDTO() const
{
    return m_customDTOSignals;
}

CustomDTOFieldSignals *EventDispatcher::customDTOField() const
{
    return m_customDTOFieldSignals;
}

CustomQuerySignals *EventDispatcher::customQuery() const
{
    return m_customQuerySignals;
}

DTOComponentSignals *EventDispatcher::dTOComponent() const
{
    return m_dTOComponentSignals;
}

CQRSComponentSignals *EventDispatcher::cQRSComponent() const
{
    return m_cQRSComponentSignals;
}

ContractsComponentSignals *EventDispatcher::contractsComponent() const
{
    return m_contractsComponentSignals;
}

PresenterComponentSignals *EventDispatcher::presenterComponent() const
{
    return m_presenterComponentSignals;
}

PresenterSingleSignals *EventDispatcher::presenterSingle() const
{
    return m_presenterSingleSignals;
}

PresenterListModelSignals *EventDispatcher::presenterListModel() const
{
    return m_presenterListModelSignals;
}

FrontEndComponentSignals *EventDispatcher::frontEndComponent() const
{
    return m_frontEndComponentSignals;
}

ErrorSignals *EventDispatcher::error() const
{
    return m_errorSignals;
}

ProgressSignals *EventDispatcher::progress() const
{
    return m_progressSignals;
}
