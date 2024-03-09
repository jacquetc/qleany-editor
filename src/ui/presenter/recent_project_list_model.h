// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_presenter_export.h"
#include "recent_project/recent_project_dto.h"
#include <QAbstractListModel>

using namespace QleanyEditor::Contracts::DTO::RecentProject;

namespace QleanyEditor::Presenter
{
class QLEANY_EDITOR_PRESENTER_EXPORT RecentProjectListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {

        IdRole = Qt::UserRole + 0,
        UuidRole = Qt::UserRole + 1,
        CreationDateRole = Qt::UserRole + 2,
        UpdateDateRole = Qt::UserRole + 3,
        FileNameRole = Qt::UserRole + 4,
        RootPathRole = Qt::UserRole + 5
    };
    Q_ENUM(Roles)

    explicit RecentProjectListModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    QHash<int, QByteArray> roleNames() const override;

Q_SIGNALS:

private:
    void populate();

    QList<RecentProjectDTO> m_recentProjectList;
    QList<int> m_recentProjectIdList;
};

} // namespace QleanyEditor::Presenter