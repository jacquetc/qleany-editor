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
class QLEANY_EDITOR_PRESENTER_EXPORT SingleGlobalComponent : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int itemId READ id WRITE setId RESET resetId NOTIFY idChanged FINAL)

    Q_PROPERTY(QUuid uuid READ uuid WRITE setUuid NOTIFY uuidChanged FINAL)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate NOTIFY creationDateChanged FINAL)
    Q_PROPERTY(QDateTime updateDate READ updateDate WRITE setUpdateDate NOTIFY updateDateChanged FINAL)
    Q_PROPERTY(QString applicationName READ applicationName WRITE setApplicationName NOTIFY applicationNameChanged FINAL)
    Q_PROPERTY(QString applicationCppDomainName READ applicationCppDomainName WRITE setApplicationCppDomainName NOTIFY applicationCppDomainNameChanged FINAL)
    Q_PROPERTY(QString organisationName READ organisationName WRITE setOrganisationName NOTIFY organisationNameChanged FINAL)
    Q_PROPERTY(QString organisationDomain READ organisationDomain WRITE setOrganisationDomain NOTIFY organisationDomainChanged FINAL)

public:
    explicit SingleGlobalComponent(QObject *parent = nullptr);

    int id() const;
    void setId(int newId);
    void resetId();

    QUuid uuid() const;
    void setUuid(const QUuid &newUuid);

    QDateTime creationDate() const;
    void setCreationDate(const QDateTime &newCreationDate);

    QDateTime updateDate() const;
    void setUpdateDate(const QDateTime &newUpdateDate);

    QString applicationName() const;
    void setApplicationName(const QString &newApplicationName);

    QString applicationCppDomainName() const;
    void setApplicationCppDomainName(const QString &newApplicationCppDomainName);

    QString organisationName() const;
    void setOrganisationName(const QString &newOrganisationName);

    QString organisationDomain() const;
    void setOrganisationDomain(const QString &newOrganisationDomain);

signals:

    void idChanged();

    void uuidChanged();
    void creationDateChanged();
    void updateDateChanged();
    void applicationNameChanged();
    void applicationCppDomainNameChanged();
    void organisationNameChanged();
    void organisationDomainChanged();

private:
    int m_id;

    QUuid m_uuid;
    QDateTime m_creationDate;
    QDateTime m_updateDate;
    QString m_applicationName;
    QString m_applicationCppDomainName;
    QString m_organisationName;
    QString m_organisationDomain;
};

} // namespace QleanyEditor::Presenter