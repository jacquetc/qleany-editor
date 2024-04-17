// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "entity_field/entity_field_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::EntityField;

class QLEANY_EDITOR_INTERACTOR_EXPORT EntityFieldSignals : public QObject
{
    Q_OBJECT
public:
    explicit EntityFieldSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(EntityFieldDTO dto);
    void updated(EntityFieldDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(EntityFieldDTO dto);
};
} // namespace QleanyEditor::Interactor