// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "contracts_component/contracts_component_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::ContractsComponent;

class QLEANY_EDITOR_INTERACTOR_EXPORT ContractsComponentSignals : public QObject
{
    Q_OBJECT
public:
    explicit ContractsComponentSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(ContractsComponentDTO dto);
    void updated(ContractsComponentDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(ContractsComponentDTO dto);
};
} // namespace QleanyEditor::Interactor