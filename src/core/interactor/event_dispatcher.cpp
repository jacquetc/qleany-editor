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

ErrorSignals *EventDispatcher::error() const
{
    return m_errorSignals;
}

ProgressSignals *EventDispatcher::progress() const
{
    return m_progressSignals;
}
