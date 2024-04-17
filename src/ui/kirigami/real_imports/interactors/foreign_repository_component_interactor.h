// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once
#include "repository_component/repository_component_interactor.h"
#include <QCoroQml>
#include <QCoroQmlTask>
#include <QQmlEngine>

using namespace QleanyEditor::Interactor::RepositoryComponent;

class ForeignRepositoryComponentInteractor : public QObject
{
    Q_OBJECT
    QML_SINGLETON
    QML_NAMED_ELEMENT(RepositoryComponentInteractor)

public:
    ForeignRepositoryComponentInteractor(QObject *parent = nullptr)
        : QObject(parent)
    {
        s_interactorInstance = RepositoryComponentInteractor::instance();
    }

    Q_INVOKABLE QCoro::QmlTask get(int id) const
    {
        return s_interactorInstance->get(id);
    }

    Q_INVOKABLE QCoro::QmlTask getWithDetails(int id) const
    {
        return s_interactorInstance->get(id);
    }

    Q_INVOKABLE CreateRepositoryComponentDTO getCreateDTO()
    {
        return s_interactorInstance->getCreateDTO();
    }

    Q_INVOKABLE UpdateRepositoryComponentDTO getUpdateDTO()
    {
        return s_interactorInstance->getUpdateDTO();
    }

    Q_INVOKABLE QCoro::QmlTask create(const CreateRepositoryComponentDTO &dto)
    {
        return s_interactorInstance->create(dto);
    }

    Q_INVOKABLE QCoro::QmlTask update(const UpdateRepositoryComponentDTO &dto)
    {
        return s_interactorInstance->update(dto);
    }

    Q_INVOKABLE QCoro::QmlTask remove(int id)
    {
        return s_interactorInstance->remove(id);
    }

private:
    RepositoryComponentInteractor *s_interactorInstance = nullptr;
};