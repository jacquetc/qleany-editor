// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_interactor_export.h"

#include "c_q_r_s_component/c_q_r_s_component_dto.h"

#include <QObject>

namespace QleanyEditor::Interactor
{

using namespace QleanyEditor::Contracts::DTO::CQRSComponent;

class QLEANY_EDITOR_INTERACTOR_EXPORT CQRSComponentSignals : public QObject
{
    Q_OBJECT
public:
    explicit CQRSComponentSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

Q_SIGNALS:
    void removed(QList<int> removedIds);
    void activeStatusChanged(QList<int> changedIds, bool isActive);
    void created(CQRSComponentDTO dto);
    void updated(CQRSComponentDTO dto);
    void allRelationsInvalidated(int id);
    void getReplied(CQRSComponentDTO dto);
};
} // namespace QleanyEditor::Interactor
