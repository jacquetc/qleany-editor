// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_presenter_export.h"
#include <QObject>

#include <QDateTime>

#include <QDateTime>

#include <QUuid>

namespace QleanyEditor::Presenter
{
class QLEANY_EDITOR_PRESENTER_EXPORT SingleProject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int itemId READ id WRITE setId RESET resetId NOTIFY idChanged FINAL)

    Q_PROPERTY(QUuid uuid READ uuid NOTIFY uuidChanged FINAL)
    Q_PROPERTY(QDateTime creationDate READ creationDate NOTIFY creationDateChanged FINAL)
    Q_PROPERTY(QDateTime updateDate READ updateDate NOTIFY updateDateChanged FINAL)
    Q_PROPERTY(QString fileName READ fileName NOTIFY fileNameChanged FINAL)

public:
    explicit SingleProject(QObject *parent = nullptr);

    int id() const;
    void setId(int newId);
    void resetId();

    QUuid uuid() const;

    QDateTime creationDate() const;

    QDateTime updateDate() const;

    QString fileName() const;

Q_SIGNALS:

    void idChanged();

    void uuidChanged();
    void creationDateChanged();
    void updateDateChanged();
    void fileNameChanged();

private:
    int m_id;

    QUuid m_uuid;
    QDateTime m_creationDate;
    QDateTime m_updateDate;
    QString m_fileName;
};

} // namespace QleanyEditor::Presenter