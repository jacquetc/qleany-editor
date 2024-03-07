#pragma once

#include "qleany_editor_interactor_export.h"
#include <QObject>
#include <qleany/common/error.h>

namespace QleanyEditor::Interactor
{

class QLEANY_EDITOR_INTERACTOR_EXPORT ErrorSignals : public QObject
{
    Q_OBJECT
public:
    explicit ErrorSignals(QObject *parent = nullptr)
        : QObject{parent}
    {
    }

signals:
    void warningSent(const Qleany::Error &error);
    void errorSent(const Qleany::Error &error);
};
} // namespace QleanyEditor::Interactor