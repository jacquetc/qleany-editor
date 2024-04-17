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
class QLEANY_EDITOR_PRESENTER_EXPORT SingleEntityField : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int itemId READ id WRITE setId RESET resetId NOTIFY idChanged FINAL)

    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid NOTIFY uuidChanged FINAL)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate NOTIFY creationDateChanged FINAL)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate NOTIFY updateDateChanged FINAL)
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged FINAL)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(bool ordered READ ordered WRITE setOrdered NOTIFY orderedChanged FINAL)
    Q_PROPERTY(bool strong READ strong WRITE setStrong NOTIFY strongChanged FINAL)

public:
    explicit SingleEntityField(QObject *parent = nullptr);

    int id() const;
    void setId(int newId);
    void resetId();

    QUuid uuid() const;
    void setUuid(const QUuid &newUuid);

    QDateTime creationDate() const;
    void setCreationDate(const QDateTime &newCreationDate);

    QDateTime updateDate() const;
    void setUpdateDate(const QDateTime &newUpdateDate);

    QString type() const;
    void setType(const QString &newType);

    QString name() const;
    void setName(const QString &newName);

    bool ordered() const;
    void setOrdered(bool newOrdered);

    bool strong() const;
    void setStrong(bool newStrong);

Q_SIGNALS:

    void idChanged();

    void uuidChanged();
    void creationDateChanged();
    void updateDateChanged();
    void typeChanged();
    void nameChanged();
    void orderedChanged();
    void strongChanged();

private:
    int m_id;

    QUuid m_uuid;
    QDateTime m_creationDate;
    QDateTime m_updateDate;
    QString m_type;
    QString m_name;
    bool m_ordered;
    bool m_strong;
};

} // namespace QleanyEditor::Presenter