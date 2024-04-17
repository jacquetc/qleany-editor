// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "entity/entity_dto.h"
#include "qleany_editor_presenter_export.h"
#include <QAbstractListModel>

using namespace QleanyEditor::Contracts::DTO::Entity;

namespace QleanyEditor::Presenter
{
class QLEANY_EDITOR_PRESENTER_EXPORT EntityListModelFromEntityComponentEntities : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int entityComponentId READ entityComponentId WRITE setEntityComponentId RESET resetEntityComponentId NOTIFY entityComponentIdChanged FINAL)

public:
    enum Roles {

        IdRole = Qt::UserRole + 0,
        UuidRole = Qt::UserRole + 1,
        CreationDateRole = Qt::UserRole + 2,
        UpdateDateRole = Qt::UserRole + 3,
        NameRole = Qt::UserRole + 4,
        OnlyForHeritageRole = Qt::UserRole + 5
    };
    Q_ENUM(Roles)

    explicit EntityListModelFromEntityComponentEntities(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    int entityComponentId() const;
    void setEntityComponentId(int newEntityComponentId);
    void resetEntityComponentId();

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    QHash<int, QByteArray> roleNames() const override;

Q_SIGNALS:
    void entityComponentIdChanged();

private:
    void populate();

    QList<EntityDTO> m_entityList;
    QList<int> m_entityIdList;
    int m_entityComponentId = 0;
};

} // namespace QleanyEditor::Presenter