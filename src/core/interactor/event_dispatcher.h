#pragma once

#include "error_signals.h"
#include "progress_signals.h"
#include "qleany_editor_interactor_export.h"

#include "root/root_signals.h"

#include "recent_project/recent_project_signals.h"

#include "project/project_signals.h"

#include "global_component/global_component_signals.h"

#include "entity_component/entity_component_signals.h"

#include "entity/entity_signals.h"

#include <QObject>
#include <QPointer>

namespace QleanyEditor::Interactor
{
class QLEANY_EDITOR_INTERACTOR_EXPORT EventDispatcher : public QObject
{
    Q_OBJECT
public:
    explicit EventDispatcher();
    static EventDispatcher *instance();

    Q_INVOKABLE ErrorSignals *error() const;
    Q_INVOKABLE ProgressSignals *progress() const;

    Q_INVOKABLE RootSignals *root() const;

    Q_INVOKABLE RecentProjectSignals *recentProject() const;

    Q_INVOKABLE ProjectSignals *project() const;

    Q_INVOKABLE GlobalComponentSignals *globalComponent() const;

    Q_INVOKABLE EntityComponentSignals *entityComponent() const;

    Q_INVOKABLE EntitySignals *entity() const;

private:
    static QPointer<EventDispatcher> s_instance;
    ErrorSignals *m_errorSignals;
    ProgressSignals *m_progressSignals;

    RootSignals *m_rootSignals;

    RecentProjectSignals *m_recentProjectSignals;

    ProjectSignals *m_projectSignals;

    GlobalComponentSignals *m_globalComponentSignals;

    EntityComponentSignals *m_entityComponentSignals;

    EntitySignals *m_entitySignals;

    EventDispatcher(const EventDispatcher &) = delete;
    EventDispatcher &operator=(const EventDispatcher &) = delete;
};
} // namespace QleanyEditor::Interactor