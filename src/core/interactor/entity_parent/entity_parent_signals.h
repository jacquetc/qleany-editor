// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "entity_parent/entity_parent_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::EntityParent;

class QLEANY_EDITOR_INTERACTOR_EXPORT EntityParentSignals : public QObject
{
    Q_OBJECT
public:
    explicit EntityParentSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(EntityParentDTO dto);
    void updated(EntityParentDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(EntityParentDTO dto);
};
} // namespace QleanyEditor::Interactor