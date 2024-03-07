#pragma once
#include "single_project.h"
#include <QQmlEngine>

struct ForeignSingleProject {
    Q_GADGET
    QML_FOREIGN(QleanyEditor::Presenter::SingleProject)
    QML_NAMED_ELEMENT(SingleProject)
};