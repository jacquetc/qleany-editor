// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once
#include "custom_query/custom_query_interactor.h"
#include <QCoroQml>
#include <QCoroQmlTask>
#include <QQmlEngine>

using namespace QleanyEditor::Interactor::CustomQuery;

class ForeignCustomQueryInteractor : public QObject
{
    Q_OBJECT
    QML_SINGLETON
    QML_NAMED_ELEMENT(CustomQueryInteractor)

public:
    ForeignCustomQueryInteractor(QObject *parent = nullptr)
        : QObject(parent)
    {
        s_interactorInstance = CustomQueryInteractor::instance();
    }

    Q_INVOKABLE QCoro::QmlTask get(int id) const
    {
        return s_interactorInstance->get(id);
    }

    Q_INVOKABLE QCoro::QmlTask getWithDetails(int id) const
    {
        return s_interactorInstance->get(id);
    }

    Q_INVOKABLE CreateCustomQueryDTO getCreateDTO()
    {
        return s_interactorInstance->getCreateDTO();
    }

    Q_INVOKABLE UpdateCustomQueryDTO getUpdateDTO()
    {
        return s_interactorInstance->getUpdateDTO();
    }

    Q_INVOKABLE QCoro::QmlTask create(const CreateCustomQueryDTO &dto)
    {
        return s_interactorInstance->create(dto);
    }

    Q_INVOKABLE QCoro::QmlTask update(const UpdateCustomQueryDTO &dto)
    {
        return s_interactorInstance->update(dto);
    }

    Q_INVOKABLE QCoro::QmlTask remove(int id)
    {
        return s_interactorInstance->remove(id);
    }

private:
    CustomQueryInteractor *s_interactorInstance = nullptr;
};