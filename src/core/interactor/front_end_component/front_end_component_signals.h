// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "front_end_component/front_end_component_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::FrontEndComponent;

class QLEANY_EDITOR_INTERACTOR_EXPORT FrontEndComponentSignals : public QObject
{
    Q_OBJECT
public:
    explicit FrontEndComponentSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(FrontEndComponentDTO dto);
    void updated(FrontEndComponentDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(FrontEndComponentDTO dto);
    void getAllReplied(QList<FrontEndComponentDTO> dtoList);
};
} // namespace QleanyEditor::Interactor