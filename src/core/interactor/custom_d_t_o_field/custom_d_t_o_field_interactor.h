// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o_field/create_custom_d_t_o_field_dto.h"
#include "custom_d_t_o_field/custom_d_t_o_field_dto.h"
#include "custom_d_t_o_field/update_custom_d_t_o_field_dto.h"
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
using namespace QleanyEditor::Contracts::DTO::CustomDTOField;

namespace QleanyEditor::Interactor::CustomDTOField
{

class QLEANY_EDITOR_INTERACTOR_EXPORT CustomDTOFieldInteractor : public QObject
{
    Q_OBJECT
public:
    explicit CustomDTOFieldInteractor(InterfaceRepositoryProvider *repositoryProvider,
                                      ThreadedUndoRedoSystem *undo_redo_system,
                                      QSharedPointer<EventDispatcher> eventDispatcher);

    static CustomDTOFieldInteractor *instance();

    Q_INVOKABLE QCoro::Task<CustomDTOFieldDTO> get(int id) const;

    Q_INVOKABLE static Contracts::DTO::CustomDTOField::CreateCustomDTOFieldDTO getCreateDTO();

    Q_INVOKABLE static Contracts::DTO::CustomDTOField::UpdateCustomDTOFieldDTO getUpdateDTO();

public Q_SLOTS:

    QCoro::Task<CustomDTOFieldDTO> create(const CreateCustomDTOFieldDTO &dto);

    QCoro::Task<CustomDTOFieldDTO> update(const UpdateCustomDTOFieldDTO &dto);

    QCoro::Task<bool> remove(int id);

private:
    static QPointer<CustomDTOFieldInteractor> s_instance;
    InterfaceRepositoryProvider *m_repositoryProvider;
    ThreadedUndoRedoSystem *m_undo_redo_system;
    QSharedPointer<EventDispatcher> m_eventDispatcher;
    CustomDTOFieldInteractor() = delete;
    CustomDTOFieldInteractor(const CustomDTOFieldInteractor &) = delete;
    CustomDTOFieldInteractor &operator=(const CustomDTOFieldInteractor &) = delete;
};

} // namespace QleanyEditor::Interactor::CustomDTOField