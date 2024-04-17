// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "presenter_component/presenter_component_with_details_dto.h"

#include "presenter_component/presenter_component_dto.h"

#include "presenter_component/presenter_component_relation_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::PresenterComponent;

class QLEANY_EDITOR_INTERACTOR_EXPORT PresenterComponentSignals : public QObject
{
    Q_OBJECT
public:
    explicit PresenterComponentSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(PresenterComponentDTO dto);
    void updated(PresenterComponentDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(PresenterComponentDTO dto);
    void getWithDetailsReplied(PresenterComponentWithDetailsDTO dto);

    void relationInserted(PresenterComponentRelationDTO dto);
    void relationRemoved(PresenterComponentRelationDTO dto);
};
} // namespace QleanyEditor::Interactor