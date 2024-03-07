#include "recent_project_list_model.h"
#include "event_dispatcher.h"
#include "recent_project/recent_project_interactor.h"
#include <QCoroTask>

using namespace QleanyEditor::Interactor;
using namespace QleanyEditor::Presenter;

RecentProjectListModel::RecentProjectListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    connect(EventDispatcher::instance()->recentProject(), &RecentProjectSignals::created, this, [this](RecentProjectDTO dto) {
        beginInsertRows(QModelIndex(), m_recentProjectList.size(), m_recentProjectList.size());
        m_recentProjectList.append(dto);
        m_recentProjectIdList.append(dto.id());
        endInsertRows();
    });

    connect(EventDispatcher::instance()->recentProject(), &RecentProjectSignals::removed, this, [this](QList<int> ids) {
        for (int i = 0; i < ids.size(); ++i) {
            for (int j = 0; j < m_recentProjectList.size(); ++j) {
                if (m_recentProjectList.at(j).id() == ids.at(i)) {
                    beginRemoveRows(QModelIndex(), j, j);
                    m_recentProjectList.removeAt(j);
                    m_recentProjectIdList.removeAt(j);
                    endRemoveRows();
                    break;
                }
            }
        }
    });

    connect(EventDispatcher::instance()->recentProject(), &RecentProjectSignals::updated, this, [this](RecentProjectDTO dto) {
        for (int i = 0; i < m_recentProjectList.size(); ++i) {
            if (m_recentProjectList.at(i).id() == dto.id()) {
                m_recentProjectList[i] = dto;
                m_recentProjectIdList[i] = dto.id();
                emit dataChanged(index(i), index(i));
                break;
            }
        }
    });

    populate();
}

QVariant RecentProjectListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}

int RecentProjectListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return m_recentProjectList.count();
}

QVariant RecentProjectListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();
    if (row >= m_recentProjectList.size())
        return QVariant();

    const RecentProjectDTO &recentProject = m_recentProjectList.at(index.row());

    if (role == Qt::DisplayRole) {
        return recentProject.rootPath();
    }
    if (role == Qt::EditRole) {
        return recentProject.rootPath();
    }

    else if (role == IdRole)
        return recentProject.id();
    else if (role == UuidRole)
        return recentProject.uuid();
    else if (role == CreationDateRole)
        return recentProject.creationDate();
    else if (role == UpdateDateRole)
        return recentProject.updateDate();
    else if (role == FileNameRole)
        return recentProject.fileName();
    else if (role == RootPathRole)
        return recentProject.rootPath();

    return QVariant();
}

Qt::ItemFlags RecentProjectListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index);
}

void RecentProjectListModel::populate()
{
    beginResetModel();
    m_recentProjectList.clear();
    m_recentProjectIdList.clear();
    endResetModel();

    auto task = RecentProject::RecentProjectInteractor::instance()->getAll();
    QCoro::connect(std::move(task), this, [this](auto &&result) {
        const QList<QleanyEditor::Contracts::DTO::RecentProject::RecentProjectDTO> recentProjectList = result;
        for (const auto &recentProject : recentProjectList) {
            if (recentProject.isInvalid()) {
                qCritical() << Q_FUNC_INFO << "Invalid ";
                return;
            }
        }
        if (recentProjectList.isEmpty()) {
            return;
        }
        beginInsertRows(QModelIndex(), 0, recentProjectList.size() - 1);
        m_recentProjectList = recentProjectList;
        // fill m_recentProjectIdList
        for (const auto &recentProject : recentProjectList) {
            m_recentProjectIdList.append(recentProject.id());
        }

        endInsertRows();
    });
}

QHash<int, QByteArray> RecentProjectListModel::roleNames() const
{
    QHash<int, QByteArray> names;

    // renaming id to itemId to avoid conflict with QML's id
    names[IdRole] = "itemId";
    names[UuidRole] = "uuid";
    names[CreationDateRole] = "creationDate";
    names[UpdateDateRole] = "updateDate";
    names[FileNameRole] = "fileName";
    names[RootPathRole] = "rootPath";
    return names;
}