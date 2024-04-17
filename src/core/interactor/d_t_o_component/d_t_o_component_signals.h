// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "d_t_o_component/d_t_o_component_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::DTOComponent;

class QLEANY_EDITOR_INTERACTOR_EXPORT DTOComponentSignals : public QObject
{
    Q_OBJECT
public:
    explicit DTOComponentSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(DTOComponentDTO dto);
    void updated(DTOComponentDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(DTOComponentDTO dto);
};
} // namespace QleanyEditor::Interactor