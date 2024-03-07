// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once

#include "qleany_editor_application_root_export.h"
#include "root/queries/get_root_query.h"
#include "root/root_dto.h"

#include "repository/interface_root_repository.h"
#include <QPromise>

using namespace Qleany;
using namespace QleanyEditor::Contracts::DTO::Root;
using namespace QleanyEditor::Contracts::Repository;
using namespace QleanyEditor::Contracts::CQRS::Root::Queries;

namespace QleanyEditor::Application::Features::Root::Queries
{
class QLEANY_EDITOR_APPLICATION_ROOT_EXPORT GetRootQueryHandler : public QObject
{
    Q_OBJECT
public:
    GetRootQueryHandler(InterfaceRootRepository *repository);
    Result<RootDTO> handle(QPromise<Result<void>> &progressPromise, const GetRootQuery &query);

private:
    InterfaceRootRepository *m_repository;
    Result<RootDTO> handleImpl(QPromise<Result<void>> &progressPromise, const GetRootQuery &query);
    static bool s_mappingRegistered;
    void registerMappings();
};

} // namespace QleanyEditor::Application::Features::Root::Queries