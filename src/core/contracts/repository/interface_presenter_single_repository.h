// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "presenter_single.h"
#include "qleany_editor_contracts_export.h"
#include <QObject>
#include <qleany/common/result.h>
#include <qleany/contracts/repository/interface_generic_repository.h>
#include <qleany/contracts/repository/interface_repository.h>

using namespace Qleany;

namespace QleanyEditor::Contracts::Repository
{

class QLEANY_EDITOR_CONTRACTS_EXPORT InterfacePresenterSingleRepository
    : public virtual Qleany::Contracts::Repository::InterfaceGenericRepository<QleanyEditor::Entities::PresenterSingle>,
      public Qleany::Contracts::Repository::InterfaceRepository
{
public:
    virtual ~InterfacePresenterSingleRepository()
    {
    }

    virtual Result<QleanyEditor::Entities::PresenterSingle> update(QleanyEditor::Entities::PresenterSingle &&entity) override = 0;
    virtual Result<QleanyEditor::Entities::PresenterSingle> getWithDetails(int entityId) = 0;

    virtual QleanyEditor::Entities::PresenterSingle::EntityLoader fetchEntityLoader() = 0;

    virtual Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) = 0;
    virtual Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) = 0;
};
} // namespace QleanyEditor::Contracts::Repository