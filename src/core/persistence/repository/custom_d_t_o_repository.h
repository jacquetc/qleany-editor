// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o.h"
#include "qleany_editor_persistence_export.h"
#include "repository/interface_custom_d_t_o_field_repository.h"
#include "repository/interface_custom_d_t_o_repository.h"
#include <QReadWriteLock>
#include <qleany/contracts/database/interface_database_table_group.h>
#include <qleany/repository/generic_repository.h>

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Contracts::Repository;
using namespace Qleany::Contracts::Database;

namespace QleanyEditor::Persistence::Repository
{

class QLEANY_EDITOR_PERSISTENCE_EXPORT CustomDTORepository final : public Qleany::Repository::GenericRepository<QleanyEditor::Entities::CustomDTO>,
                                                                   public QleanyEditor::Contracts::Repository::InterfaceCustomDTORepository
{
public:
    explicit CustomDTORepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::CustomDTO> *customDTODatabase,
                                 InterfaceCustomDTOFieldRepository *customDTOFieldRepository);

    SignalHolder *signalHolder() override;

    Result<QleanyEditor::Entities::CustomDTO> update(QleanyEditor::Entities::CustomDTO &&entity) override;
    Result<QleanyEditor::Entities::CustomDTO> getWithDetails(int entityId) override;

    QleanyEditor::Entities::CustomDTO::FieldsLoader fetchFieldsLoader() override;

    Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) override;
    Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) override;

private:
    InterfaceCustomDTOFieldRepository *m_customDTOFieldRepository;
    QScopedPointer<SignalHolder> m_signalHolder;
    QReadWriteLock m_lock;
};

} // namespace QleanyEditor::Repository