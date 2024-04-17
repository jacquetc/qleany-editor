// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "custom_query/custom_query_with_details_dto.h"

#include "custom_query/custom_query_dto.h"

#include "custom_query/custom_query_relation_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::CustomQuery;

class QLEANY_EDITOR_INTERACTOR_EXPORT CustomQuerySignals : public QObject
{
    Q_OBJECT
public:
    explicit CustomQuerySignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(CustomQueryDTO dto);
    void updated(CustomQueryDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(CustomQueryDTO dto);
    void getWithDetailsReplied(CustomQueryWithDetailsDTO dto);

    void relationInserted(CustomQueryRelationDTO dto);
    void relationRemoved(CustomQueryRelationDTO dto);
};
} // namespace QleanyEditor::Interactor