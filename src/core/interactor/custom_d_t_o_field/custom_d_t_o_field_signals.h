// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "custom_d_t_o_field/custom_d_t_o_field_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::CustomDTOField;

class QLEANY_EDITOR_INTERACTOR_EXPORT CustomDTOFieldSignals : public QObject
{
    Q_OBJECT
public:
    explicit CustomDTOFieldSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(CustomDTOFieldDTO dto);
    void updated(CustomDTOFieldDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(CustomDTOFieldDTO dto);
};
} // namespace QleanyEditor::Interactor