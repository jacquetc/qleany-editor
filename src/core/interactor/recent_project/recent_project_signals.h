// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "recent_project/recent_project_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::RecentProject;

class QLEANY_EDITOR_INTERACTOR_EXPORT RecentProjectSignals : public QObject
{
    Q_OBJECT
public:
    explicit RecentProjectSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(RecentProjectDTO dto);
    void updated(RecentProjectDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(RecentProjectDTO dto);
    void getAllReplied(QList<RecentProjectDTO> dtoList);
};
} // namespace QleanyEditor::Interactor