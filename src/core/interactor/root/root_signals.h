// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "root/root_dto.h"

#include "root/root_relation_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::Root;

class QLEANY_EDITOR_INTERACTOR_EXPORT RootSignals : public QObject
{
    Q_OBJECT
public:
    explicit RootSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

signals:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(RootDTO dto);
    void updated(RootDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(RootDTO dto);

    void relationInserted(RootRelationDTO dto);
    void relationRemoved(RootRelationDTO dto);
};
} // namespace QleanyEditor::Interactor