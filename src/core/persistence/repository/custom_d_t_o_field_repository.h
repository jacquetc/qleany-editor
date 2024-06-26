// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "custom_d_t_o_field.h"
#include "qleany_editor_persistence_export.h"
#include "repository/interface_custom_d_t_o_field_repository.h"
#include <QReadWriteLock>
#include <qleany/contracts/database/interface_database_table_group.h>
#include <qleany/repository/generic_repository.h>

using namespace Qleany;
using namespace Qleany::Contracts::Repository;
using namespace QleanyEditor::Contracts::Repository;
using namespace Qleany::Contracts::Database;

namespace QleanyEditor::Persistence::Repository
{

class QLEANY_EDITOR_PERSISTENCE_EXPORT CustomDTOFieldRepository final : public Qleany::Repository::GenericRepository<QleanyEditor::Entities::CustomDTOField>,
                                                                        public QleanyEditor::Contracts::Repository::InterfaceCustomDTOFieldRepository
{
public:
    explicit CustomDTOFieldRepository(InterfaceDatabaseTableGroup<QleanyEditor::Entities::CustomDTOField> *customDTOFieldDatabase);

    SignalHolder *signalHolder() override;

    Result<QHash<int, QList<int>>> removeInCascade(QList<int> ids) override;
    Result<QHash<int, QList<int>>> changeActiveStatusInCascade(QList<int> ids, bool active) override;

private:
    QScopedPointer<SignalHolder> m_signalHolder;
    QReadWriteLock m_lock;
};

} // namespace QleanyEditor::Repository