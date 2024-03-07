// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "common_parent.h"
#include "entity.h"
#include "entity_component.h"
#include "global_component.h"
#include "project.h"
#include "recent_project.h"
#include "root.h"

#include <QObject>

namespace QleanyEditor::Entities
{

class EntitiesRegistration : public QObject
{
    Q_OBJECT
public:
    explicit EntitiesRegistration(QObject *parent)
        : QObject(parent)
    {
        qRegisterMetaType<QleanyEditor::Entities::CommonParent>("QleanyEditor::Entities::CommonParent");
        qRegisterMetaType<QleanyEditor::Entities::Root>("QleanyEditor::Entities::Root");
        qRegisterMetaType<QleanyEditor::Entities::RecentProject>("QleanyEditor::Entities::RecentProject");
        qRegisterMetaType<QleanyEditor::Entities::Project>("QleanyEditor::Entities::Project");
        qRegisterMetaType<QleanyEditor::Entities::GlobalComponent>("QleanyEditor::Entities::GlobalComponent");
        qRegisterMetaType<QleanyEditor::Entities::EntityComponent>("QleanyEditor::Entities::EntityComponent");
        qRegisterMetaType<QleanyEditor::Entities::Entity>("QleanyEditor::Entities::Entity");
    }
};

} // namespace QleanyEditor::Entities