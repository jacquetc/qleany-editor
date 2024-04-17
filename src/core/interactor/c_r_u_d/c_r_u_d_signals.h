// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "c_r_u_d/c_r_u_d_with_details_dto.h"

#include "c_r_u_d/c_r_u_d_dto.h"

#include "c_r_u_d/c_r_u_d_relation_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::CRUD;

class QLEANY_EDITOR_INTERACTOR_EXPORT CRUDSignals : public QObject
{
    Q_OBJECT
public:
    explicit CRUDSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(CRUDDTO dto);
    void updated(CRUDDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(CRUDDTO dto);
    void getWithDetailsReplied(CRUDWithDetailsDTO dto);

    void relationInserted(CRUDRelationDTO dto);
    void relationRemoved(CRUDRelationDTO dto);
};
} // namespace QleanyEditor::Interactor