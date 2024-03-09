// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "entity/entity_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::Entity;

class QLEANY_EDITOR_INTERACTOR_EXPORT EntitySignals : public QObject
{
    Q_OBJECT
public:
    explicit EntitySignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(EntityDTO dto);
    void updated(EntityDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(EntityDTO dto);
};
} // namespace QleanyEditor::Interactor