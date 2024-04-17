// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "presenter_single/presenter_single_with_details_dto.h"

#include "presenter_single/presenter_single_dto.h"

#include "presenter_single/presenter_single_relation_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::PresenterSingle;

class QLEANY_EDITOR_INTERACTOR_EXPORT PresenterSingleSignals : public QObject
{
    Q_OBJECT
public:
    explicit PresenterSingleSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(PresenterSingleDTO dto);
    void updated(PresenterSingleDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(PresenterSingleDTO dto);
    void getWithDetailsReplied(PresenterSingleWithDetailsDTO dto);

    void relationInserted(PresenterSingleRelationDTO dto);
    void relationRemoved(PresenterSingleRelationDTO dto);
};
} // namespace QleanyEditor::Interactor