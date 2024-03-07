#pragma once
#include "single_global_component.h"
#include <QQmlEngine>

struct ForeignSingleGlobalComponent {
    Q_GADGET
    QML_FOREIGN(QleanyEditor::Presenter::SingleGlobalComponent)
    QML_NAMED_ELEMENT(SingleGlobalComponent)
};