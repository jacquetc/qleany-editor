// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o/create_custom_d_t_o_dto.h"
#include "custom_d_t_o/custom_d_t_o_dto.h"
#include "custom_d_t_o/custom_d_t_o_with_details_dto.h"
#include "custom_d_t_o/update_custom_d_t_o_dto.h"
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
using namespace QleanyEditor::Contracts::DTO::CustomDTO;

namespace QleanyEditor::Interactor::CustomDTO
{

class QLEANY_EDITOR_INTERACTOR_EXPORT CustomDTOInteractor : public QObject
{
    Q_OBJECT
public:
    explicit CustomDTOInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                 ThreadedUndoRedoSystem *undo_redo_system,
                                 QSharedPointer<EventDispatcher> eventDispatcher);

    static CustomDTOInteractor *instance();

    Q_INVOKABLE QCoro::Task<CustomDTODTO> get(int id) const;

    Q_INVOKABLE QCoro::Task<CustomDTOWithDetailsDTO> getWithDetails(int id) const;

    Q_INVOKABLE static Contracts::DTO::CustomDTO::CreateCustomDTODTO getCreateDTO();

    Q_INVOKABLE static Contracts::DTO::CustomDTO::UpdateCustomDTODTO getUpdateDTO();

public Q_SLOTS:

    QCoro::Task<CustomDTODTO> create(const CreateCustomDTODTO &dto);

    QCoro::Task<CustomDTODTO> update(const UpdateCustomDTODTO &dto);

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<CustomDTOInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    CustomDTOInteractor() = delete;
    CustomDTOInteractor(const CustomDTOInteractor &) = delete;
    CustomDTOInteractor &operator=(const CustomDTOInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::CustomDTO