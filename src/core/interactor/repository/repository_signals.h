// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "repository/repository_with_details_dto.h"

#include "repository/repository_dto.h"

#include "repository/repository_relation_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::Repository;

class QLEANY_EDITOR_INTERACTOR_EXPORT RepositorySignals : public QObject
{
    Q_OBJECT
public:
    explicit RepositorySignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(RepositoryDTO dto);
    void updated(RepositoryDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(RepositoryDTO dto);
    void getWithDetailsReplied(RepositoryWithDetailsDTO dto);
    void getAllReplied(QList<RepositoryDTO> dtoList);

    void relationInserted(RepositoryRelationDTO dto);
    void relationRemoved(RepositoryRelationDTO dto);
};
} // namespace QleanyEditor::Interactor