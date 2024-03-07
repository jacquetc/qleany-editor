// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "project/project_dto.h"

#include "project/project_relation_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::Project;

class QLEANY_EDITOR_INTERACTOR_EXPORT ProjectSignals : public QObject
{
    Q_OBJECT
public:
    explicit ProjectSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

signals:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(ProjectDTO dto);
    void updated(ProjectDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(ProjectDTO dto);

    void relationInserted(ProjectRelationDTO dto);
    void relationRemoved(ProjectRelationDTO dto);

    void loadProjectChanged();
    void saveProjectChanged();
    void createProjectChanged();
    void closeProjectChanged();
};
} // namespace QleanyEditor::Interactor