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

#include "entity_field/entity_field_signals.h"

#include "entity_parent/entity_parent_signals.h"

#include "repository_component/repository_component_signals.h"

#include "repository/repository_signals.h"

#include "interactor_component/interactor_component_signals.h"

#include "application_component/application_component_signals.h"

#include "application_feature/application_feature_signals.h"

#include "c_r_u_d/c_r_u_d_signals.h"

#include "custom_command/custom_command_signals.h"

#include "custom_d_t_o/custom_d_t_o_signals.h"

#include "custom_d_t_o_field/custom_d_t_o_field_signals.h"

#include "custom_query/custom_query_signals.h"

#include "d_t_o_component/d_t_o_component_signals.h"

#include "c_q_r_s_component/c_q_r_s_component_signals.h"

#include "contracts_component/contracts_component_signals.h"

#include "presenter_component/presenter_component_signals.h"

#include "presenter_single/presenter_single_signals.h"

#include "presenter_list_model/presenter_list_model_signals.h"

#include "front_end_component/front_end_component_signals.h"

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

    Q_INVOKABLE EntityFieldSignals *entityField() const;

    Q_INVOKABLE EntityParentSignals *entityParent() const;

    Q_INVOKABLE RepositoryComponentSignals *repositoryComponent() const;

    Q_INVOKABLE RepositorySignals *repository() const;

    Q_INVOKABLE InteractorComponentSignals *interactorComponent() const;

    Q_INVOKABLE ApplicationComponentSignals *applicationComponent() const;

    Q_INVOKABLE ApplicationFeatureSignals *applicationFeature() const;

    Q_INVOKABLE CRUDSignals *cRUD() const;

    Q_INVOKABLE CustomCommandSignals *customCommand() const;

    Q_INVOKABLE CustomDTOSignals *customDTO() const;

    Q_INVOKABLE CustomDTOFieldSignals *customDTOField() const;

    Q_INVOKABLE CustomQuerySignals *customQuery() const;

    Q_INVOKABLE DTOComponentSignals *dTOComponent() const;

    Q_INVOKABLE CQRSComponentSignals *cQRSComponent() const;

    Q_INVOKABLE ContractsComponentSignals *contractsComponent() const;

    Q_INVOKABLE PresenterComponentSignals *presenterComponent() const;

    Q_INVOKABLE PresenterSingleSignals *presenterSingle() const;

    Q_INVOKABLE PresenterListModelSignals *presenterListModel() const;

    Q_INVOKABLE FrontEndComponentSignals *frontEndComponent() const;

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

    EntityFieldSignals *m_entityFieldSignals;

    EntityParentSignals *m_entityParentSignals;

    RepositoryComponentSignals *m_repositoryComponentSignals;

    RepositorySignals *m_repositorySignals;

    InteractorComponentSignals *m_interactorComponentSignals;

    ApplicationComponentSignals *m_applicationComponentSignals;

    ApplicationFeatureSignals *m_applicationFeatureSignals;

    CRUDSignals *m_cRUDSignals;

    CustomCommandSignals *m_customCommandSignals;

    CustomDTOSignals *m_customDTOSignals;

    CustomDTOFieldSignals *m_customDTOFieldSignals;

    CustomQuerySignals *m_customQuerySignals;

    DTOComponentSignals *m_dTOComponentSignals;

    CQRSComponentSignals *m_cQRSComponentSignals;

    ContractsComponentSignals *m_contractsComponentSignals;

    PresenterComponentSignals *m_presenterComponentSignals;

    PresenterSingleSignals *m_presenterSingleSignals;

    PresenterListModelSignals *m_presenterListModelSignals;

    FrontEndComponentSignals *m_frontEndComponentSignals;

    EventDispatcher(const EventDispatcher &) = delete;
    EventDispatcher &operator=(const EventDispatcher &) = delete;
};
} // namespace QleanyEditor::Interactor