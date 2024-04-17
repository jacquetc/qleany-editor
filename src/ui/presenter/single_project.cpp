// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#include "single_project.h"
#include "event_dispatcher.h"
#include "project/project_interactor.h"

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Presenter;

SingleProject::SingleProject(QObject *parent)
    : QObject{parent}
{
    connect(EventDispatcher::instance()->project(), &ProjectSignals::removed, this, [this](QList<int> removedIds) {
        if (removedIds.contains(id())) {
            resetId();
        }
    });
    connect(EventDispatcher::instance()->project(), &ProjectSignals::updated, this, [this](ProjectDTO dto) {
        if (dto.id() == id()) {
            if (m_id != dto.id()) {
                m_id = dto.id();
                Q_EMIT idChanged();
            }
            if (m_uuid != dto.uuid()) {
                m_uuid = dto.uuid();
                Q_EMIT uuidChanged();
            }
            if (m_creationDate != dto.creationDate()) {
                m_creationDate = dto.creationDate();
                Q_EMIT creationDateChanged();
            }
            if (m_updateDate != dto.updateDate()) {
                m_updateDate = dto.updateDate();
                Q_EMIT updateDateChanged();
            }
            if (m_fileName != dto.fileName()) {
                m_fileName = dto.fileName();
                Q_EMIT fileNameChanged();
            }
            if (m_rootPath != dto.rootPath()) {
                m_rootPath = dto.rootPath();
                Q_EMIT rootPathChanged();
            }
        }
    });
}

int SingleProject::id() const
{
    return m_id;
}

void SingleProject::setId(int newId)
{
    if (m_id == newId)
        return;
    m_id = newId;
    Q_EMIT idChanged();

    // clear
    if (m_id == 0) {
        m_uuid = QUuid{};
        Q_EMIT uuidChanged();

        m_creationDate = QDateTime{};
        Q_EMIT creationDateChanged();

        m_updateDate = QDateTime{};
        Q_EMIT updateDateChanged();

        m_fileName = QString{};
        Q_EMIT fileNameChanged();

        m_rootPath = QString{};
        Q_EMIT rootPathChanged();

    }

    // set
    else {
        Project::ProjectInteractor::instance()->get(m_id).then([this](const QleanyEditor::Contracts::DTO::Project::ProjectDTO &project) {
            if (project.isInvalid()) {
                qCritical() << Q_FUNC_INFO << "Invalid projectId";
                return;
            }

            m_uuid = project.uuid();
            Q_EMIT uuidChanged();

            m_creationDate = project.creationDate();
            Q_EMIT creationDateChanged();

            m_updateDate = project.updateDate();
            Q_EMIT updateDateChanged();

            m_fileName = project.fileName();
            Q_EMIT fileNameChanged();

            m_rootPath = project.rootPath();
            Q_EMIT rootPathChanged();
        });
    }
}

void SingleProject::resetId()
{
    setId(0);
}

QUuid SingleProject::uuid() const
{
    return m_uuid;
}

QDateTime SingleProject::creationDate() const
{
    return m_creationDate;
}

QDateTime SingleProject::updateDate() const
{
    return m_updateDate;
}

QString SingleProject::fileName() const
{
    return m_fileName;
}

QString SingleProject::rootPath() const
{
    return m_rootPath;
}
