// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_command.h"
#include "qleany_editor_persistence_export.h"
#include "repository/interface_custom_command_repository.h"
#include "repository/interface_custom_d_t_o_repository.h"
#include "repository/interface_entity_repository.h"
#include <QReadWriteLock>
#include <qleany/contracts/database/interface_database_table_group.h>
#include <qleany/repository/generic_repository.h>

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Contracts::Repository;
using namespace Qleany::Contracts::Database;

namespace QleanyEditor::Persistence::Repository
{

class QLEANY_EDITOR_PERSISTENCE_EXPORT CustomCommandRepository final : public Qleany::Repository::GenericRepository<QleanyEditor::Entities::CustomCommand>,
                                                                       public QleanyEditor::Contracts::Repository::InterfaceCustomCommandRepository
{
public:
    explicit CustomCommandRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::CustomCommand> *customCommandDatabase,
                                     InterfaceCustomDTORepository *customDTORepository,
                                     InterfaceEntityRepository *entityRepository);

    SignalHolder *signalHolder() override;

    Result<QleanyEditor::Entities::CustomCommand> update(QleanyEditor::Entities::CustomCommand &&entity) override;
    Result<QleanyEditor::Entities::CustomCommand> getWithDetails(int entityId) override;

    QleanyEditor::Entities::CustomCommand::DtoInLoader fetchDtoInLoader() override;

    QleanyEditor::Entities::CustomCommand::DtoOutLoader fetchDtoOutLoader() override;

    QleanyEditor::Entities::CustomCommand::EntitiesLoader fetchEntitiesLoader() override;

    Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) override;
    Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) override;

private:
    InterfaceCustomDTORepository *m_customDTORepository;
    InterfaceEntityRepository *m_entityRepository;
    QScopedPointer<SignalHolder> m_signalHolder;
    QReadWriteLock m_lock;
};

} // namespace QleanyEditor::Repository