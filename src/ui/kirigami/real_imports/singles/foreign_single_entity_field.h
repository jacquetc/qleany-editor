#pragma once
#include "single_entity_field.h"
#include <QQmlEngine>

struct ForeignSingleEntityField {
    Q_GADGET
    QML_FOREIGN(QleanyEditor::Presenter::SingleEntityField)
    QML_NAMED_ELEMENT(SingleEntityField)
};