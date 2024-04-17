// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "application_feature/application_feature_dto.h"
#include "application_feature/application_feature_with_details_dto.h"
#include "application_feature/create_application_feature_dto.h"
#include "application_feature/update_application_feature_dto.h"
#include "event_dispatcher.h"
#include "qleany_editor_interactor_export.h"
#include <qleany/contracts/repository/interface_repository_provider.h>

#include <QCoroTask>
#include <QObject>
#include <QPointer>
#include <QSharedPointer>
#include <qleany/tools/undo_redo/threaded_undo_redo_system.h>

using namespace Qleany::Contracts::Repository;
using namespace Qleany::Tools::UndoRedo;
using namespace QleanyEditor::Contracts::DTO::ApplicationFeature;

namespace QleanyEditor::Interactor::ApplicationFeature
{

class QLEANY_EDITOR_INTERACTOR_EXPORT ApplicationFeatureInteractor : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationFeatureInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                          ThreadedUndoRedoSystem *undo_redo_system,
                                          QSharedPointer<EventDispatcher> eventDispatcher);

    static ApplicationFeatureInteractor *instance();

    Q_INVOKABLE QCoro::Task<ApplicationFeatureDTO> get(int id) const;

    Q_INVOKABLE QCoro::Task<ApplicationFeatureWithDetailsDTO> getWithDetails(int id) const;

    Q_INVOKABLE static Contracts::DTO::ApplicationFeature::CreateApplicationFeatureDTO getCreateDTO();

    Q_INVOKABLE static Contracts::DTO::ApplicationFeature::UpdateApplicationFeatureDTO getUpdateDTO();

public Q_SLOTS:

    QCoro::Task<ApplicationFeatureDTO> create(const CreateApplicationFeatureDTO &dto);

    QCoro::Task<ApplicationFeatureDTO> update(const UpdateApplicationFeatureDTO &dto);

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<ApplicationFeatureInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    ApplicationFeatureInteractor() = delete;
    ApplicationFeatureInteractor(const ApplicationFeatureInteractor &) = delete;
    ApplicationFeatureInteractor &operator=(const ApplicationFeatureInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::ApplicationFeature