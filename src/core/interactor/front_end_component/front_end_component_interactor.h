// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "event_dispatcher.h"
#include "front_end_component/create_front_end_component_dto.h"
#include "front_end_component/front_end_component_dto.h"
#include "front_end_component/update_front_end_component_dto.h"
#include "qleany_editor_interactor_export.h"
#include <qleany/contracts/repository/interface_repository_provider.h>

#include <QCoroTask>
#include <QObject>
#include <QPointer>
#include <QSharedPointer>
#include <qleany/tools/undo_redo/threaded_undo_redo_system.h>

using namespace Qleany::Contracts::Repository;
using namespace Qleany::Tools::UndoRedo;
using namespace QleanyEditor::Contracts::DTO::FrontEndComponent;

namespace QleanyEditor::Interactor::FrontEndComponent
{

class QLEANY_EDITOR_INTERACTOR_EXPORT FrontEndComponentInteractor : public QObject
{
    Q_OBJECT
public:
    explicit FrontEndComponentInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                         ThreadedUndoRedoSystem *undo_redo_system,
                                         QSharedPointer<EventDispatcher> eventDispatcher);

    static FrontEndComponentInteractor *instance();

    Q_INVOKABLE QCoro::Task<FrontEndComponentDTO> get(int id) const;

    Q_INVOKABLE QCoro::Task<QList<FrontEndComponentDTO>> getAll() const;

    Q_INVOKABLE static Contracts::DTO::FrontEndComponent::CreateFrontEndComponentDTO getCreateDTO();

    Q_INVOKABLE static Contracts::DTO::FrontEndComponent::UpdateFrontEndComponentDTO getUpdateDTO();

public Q_SLOTS:

    QCoro::Task<FrontEndComponentDTO> create(const CreateFrontEndComponentDTO &dto);

    QCoro::Task<FrontEndComponentDTO> update(const UpdateFrontEndComponentDTO &dto);

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<FrontEndComponentInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    FrontEndComponentInteractor() = delete;
    FrontEndComponentInteractor(const FrontEndComponentInteractor &) = delete;
    FrontEndComponentInteractor &operator=(const FrontEndComponentInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::FrontEndComponent