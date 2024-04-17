// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "custom_d_t_o/custom_d_t_o_with_details_dto.h"

#include "custom_d_t_o/custom_d_t_o_dto.h"

#include "custom_d_t_o/custom_d_t_o_relation_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::CustomDTO;

class QLEANY_EDITOR_INTERACTOR_EXPORT CustomDTOSignals : public QObject
{
    Q_OBJECT
public:
    explicit CustomDTOSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(CustomDTODTO dto);
    void updated(CustomDTODTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(CustomDTODTO dto);
    void getWithDetailsReplied(CustomDTOWithDetailsDTO dto);

    void relationInserted(CustomDTORelationDTO dto);
    void relationRemoved(CustomDTORelationDTO dto);
};
} // namespace QleanyEditor::Interactor