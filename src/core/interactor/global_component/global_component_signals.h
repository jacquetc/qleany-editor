// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "global_component/global_component_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::GlobalComponent;

class QLEANY_EDITOR_INTERACTOR_EXPORT GlobalComponentSignals : public QObject
{
    Q_OBJECT
public:
    explicit GlobalComponentSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

signals:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(GlobalComponentDTO dto);
    void updated(GlobalComponentDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(GlobalComponentDTO dto);
};
} // namespace QleanyEditor::Interactor