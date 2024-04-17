// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "custom_command/custom_command_with_details_dto.h"

#include "custom_command/custom_command_dto.h"

#include "custom_command/custom_command_relation_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::CustomCommand;

class QLEANY_EDITOR_INTERACTOR_EXPORT CustomCommandSignals : public QObject
{
    Q_OBJECT
public:
    explicit CustomCommandSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(CustomCommandDTO dto);
    void updated(CustomCommandDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(CustomCommandDTO dto);
    void getWithDetailsReplied(CustomCommandWithDetailsDTO dto);

    void relationInserted(CustomCommandRelationDTO dto);
    void relationRemoved(CustomCommandRelationDTO dto);
};
} // namespace QleanyEditor::Interactor