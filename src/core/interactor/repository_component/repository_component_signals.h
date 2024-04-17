// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "repository_component/repository_component_with_details_dto.h"

#include "repository_component/repository_component_dto.h"

#include "repository_component/repository_component_relation_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::RepositoryComponent;

class QLEANY_EDITOR_INTERACTOR_EXPORT RepositoryComponentSignals : public QObject
{
    Q_OBJECT
public:
    explicit RepositoryComponentSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(RepositoryComponentDTO dto);
    void updated(RepositoryComponentDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(RepositoryComponentDTO dto);
    void getWithDetailsReplied(RepositoryComponentWithDetailsDTO dto);

    void relationInserted(RepositoryComponentRelationDTO dto);
    void relationRemoved(RepositoryComponentRelationDTO dto);
};
} // namespace QleanyEditor::Interactor