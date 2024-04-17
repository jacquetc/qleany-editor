// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "application_component/application_component_with_details_dto.h"

#include "application_component/application_component_dto.h"

#include "application_component/application_component_relation_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::ApplicationComponent;

class QLEANY_EDITOR_INTERACTOR_EXPORT ApplicationComponentSignals : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationComponentSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(ApplicationComponentDTO dto);
    void updated(ApplicationComponentDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(ApplicationComponentDTO dto);
    void getWithDetailsReplied(ApplicationComponentWithDetailsDTO dto);

    void relationInserted(ApplicationComponentRelationDTO dto);
    void relationRemoved(ApplicationComponentRelationDTO dto);
};
} // namespace QleanyEditor::Interactor