// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "c_r_u_d.h"
#include "qleany_editor_contracts_export.h"
#include <QObject>
#include <qleany/common/result.h>
#include <qleany/contracts/repository/interface_generic_repository.h>
#include <qleany/contracts/repository/interface_repository.h>

using namespace Qleany;

namespace QleanyEditor::Contracts::Repository
{

class QLEANY_EDITOR_CONTRACTS_EXPORT InterfaceCRUDRepository
    : public virtual Qleany::Contracts::Repository::InterfaceGenericRepository<QleanyEditor::Entities::CRUD>,
      public Qleany::Contracts::Repository::InterfaceRepository
{
public:
    virtual ~InterfaceCRUDRepository()
    {
    }

    virtual Result<QleanyEditor::Entities::CRUD> update(QleanyEditor::Entities::CRUD &&entity) override = 0;
    virtual Result<QleanyEditor::Entities::CRUD> getWithDetails(int entityId) = 0;

    virtual QleanyEditor::Entities::CRUD::EntityMappableWithLoader fetchEntityMappableWithLoader() = 0;

    virtual Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) = 0;
    virtual Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) = 0;
};
} // namespace QleanyEditor::Contracts::Repository