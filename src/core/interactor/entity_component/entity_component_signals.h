// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "entity_component/entity_component_with_details_dto.h"

#include "entity_component/entity_component_dto.h"

#include "entity_component/entity_component_relation_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::EntityComponent;

class QLEANY_EDITOR_INTERACTOR_EXPORT EntityComponentSignals : public QObject
{
    Q_OBJECT
public:
    explicit EntityComponentSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

signals:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(EntityComponentDTO dto);
    void updated(EntityComponentDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(EntityComponentDTO dto);
    void getWithDetailsReplied(EntityComponentWithDetailsDTO dto);

    void relationInserted(EntityComponentRelationDTO dto);
    void relationRemoved(EntityComponentRelationDTO dto);
};
} // namespace QleanyEditor::Interactor