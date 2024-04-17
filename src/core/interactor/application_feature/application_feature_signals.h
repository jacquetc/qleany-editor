// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "application_feature/application_feature_with_details_dto.h"

#include "application_feature/application_feature_dto.h"

#include "application_feature/application_feature_relation_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::ApplicationFeature;

class QLEANY_EDITOR_INTERACTOR_EXPORT ApplicationFeatureSignals : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationFeatureSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(ApplicationFeatureDTO dto);
    void updated(ApplicationFeatureDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(ApplicationFeatureDTO dto);
    void getWithDetailsReplied(ApplicationFeatureWithDetailsDTO dto);

    void relationInserted(ApplicationFeatureRelationDTO dto);
    void relationRemoved(ApplicationFeatureRelationDTO dto);
};
} // namespace QleanyEditor::Interactor