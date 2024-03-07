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
                emit idChanged();
            }
            if (m_uuid != dto.uuid()) {
                m_uuid = dto.uuid();
                emit uuidChanged();
            }
            if (m_creationDate != dto.creationDate()) {
                m_creationDate = dto.creationDate();
                emit creationDateChanged();
            }
            if (m_updateDate != dto.updateDate()) {
                m_updateDate = dto.updateDate();
                emit updateDateChanged();
            }
            if (m_fileName != dto.fileName()) {
                m_fileName = dto.fileName();
                emit fileNameChanged();
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
    emit idChanged();

    // clear
    if (m_id == 0) {
        m_uuid = QUuid{};
        emit uuidChanged();

        m_creationDate = QDateTime{};
        emit creationDateChanged();

        m_updateDate = QDateTime{};
        emit updateDateChanged();

        m_fileName = QString{};
        emit fileNameChanged();

    }

    // set
    else {
        Project::ProjectInteractor::instance()->get(m_id).then([this](const QleanyEditor::Contracts::DTO::Project::ProjectDTO &project) {
            if (project.isInvalid()) {
                qCritical() << Q_FUNC_INFO << "Invalid projectId";
                return;
            }

            m_uuid = project.uuid();
            emit uuidChanged();

            m_creationDate = project.creationDate();
            emit creationDateChanged();

            m_updateDate = project.updateDate();
            emit updateDateChanged();

            m_fileName = project.fileName();
            emit fileNameChanged();
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
