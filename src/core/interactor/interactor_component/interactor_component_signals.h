// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "interactor_component/interactor_component_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::InteractorComponent;

class QLEANY_EDITOR_INTERACTOR_EXPORT InteractorComponentSignals : public QObject
{
    Q_OBJECT
public:
    explicit InteractorComponentSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(InteractorComponentDTO dto);
    void updated(InteractorComponentDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(InteractorComponentDTO dto);
};
} // namespace QleanyEditor::Interactor