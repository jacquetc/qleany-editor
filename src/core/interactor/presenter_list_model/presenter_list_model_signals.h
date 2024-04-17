// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "presenter_list_model/presenter_list_model_with_details_dto.h"

#include "presenter_list_model/presenter_list_model_dto.h"

#include "presenter_list_model/presenter_list_model_relation_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::PresenterListModel;

class QLEANY_EDITOR_INTERACTOR_EXPORT PresenterListModelSignals : public QObject
{
    Q_OBJECT
public:
    explicit PresenterListModelSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(PresenterListModelDTO dto);
    void updated(PresenterListModelDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(PresenterListModelDTO dto);
    void getWithDetailsReplied(PresenterListModelWithDetailsDTO dto);

    void relationInserted(PresenterListModelRelationDTO dto);
    void relationRemoved(PresenterListModelRelationDTO dto);
};
} // namespace QleanyEditor::Interactor