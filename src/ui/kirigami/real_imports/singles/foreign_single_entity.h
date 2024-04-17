#pragma once
#include "single_entity.h"
#include <QQmlEngine>

struct ForeignSingleEntity {
    Q_GADGET
    QML_FOREIGN(QleanyEditor::Presenter::SingleEntity)
    QML_NAMED_ELEMENT(SingleEntity)
};