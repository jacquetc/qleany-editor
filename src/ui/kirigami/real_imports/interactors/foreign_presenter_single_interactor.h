// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once
#include "presenter_single/presenter_single_interactor.h"
#include <QCoroQml>
#include <QCoroQmlTask>
#include <QQmlEngine>

using namespace QleanyEditor::Interactor::PresenterSingle;

class ForeignPresenterSingleInteractor : public QObject
{
    Q_OBJECT
    QML_SINGLETON
    QML_NAMED_ELEMENT(PresenterSingleInteractor)

public:
    ForeignPresenterSingleInteractor(QObject *parent = nullptr)
        : QObject(parent)
    {
        s_interactorInstance = PresenterSingleInteractor::instance();
    }

    Q_INVOKABLE QCoro::QmlTask get(int id) const
    {
        return s_interactorInstance->get(id);
    }

    Q_INVOKABLE QCoro::QmlTask getWithDetails(int id) const
    {
        return s_interactorInstance->get(id);
    }

    Q_INVOKABLE CreatePresenterSingleDTO getCreateDTO()
    {
        return s_interactorInstance->getCreateDTO();
    }

    Q_INVOKABLE UpdatePresenterSingleDTO getUpdateDTO()
    {
        return s_interactorInstance->getUpdateDTO();
    }

    Q_INVOKABLE QCoro::QmlTask create(const CreatePresenterSingleDTO &dto)
    {
        return s_interactorInstance->create(dto);
    }

    Q_INVOKABLE QCoro::QmlTask update(const UpdatePresenterSingleDTO &dto)
    {
        return s_interactorInstance->update(dto);
    }

    Q_INVOKABLE QCoro::QmlTask remove(int id)
    {
        return s_interactorInstance->remove(id);
    }

private:
    PresenterSingleInteractor *s_interactorInstance = nullptr;
};