// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once
#include "presenter_component/presenter_component_interactor.h"
#include <QCoroQml>
#include <QCoroQmlTask>
#include <QQmlEngine>

using namespace QleanyEditor::Interactor::PresenterComponent;

class ForeignPresenterComponentInteractor : public QObject
{
    Q_OBJECT
    QML_SINGLETON
    QML_NAMED_ELEMENT(PresenterComponentInteractor)

public:
    ForeignPresenterComponentInteractor(QObject *parent = nullptr)
        : QObject(parent)
    {
        s_interactorInstance = PresenterComponentInteractor::instance();
    }

    Q_INVOKABLE QCoro::QmlTask get(int id) const
    {
        return s_interactorInstance->get(id);
    }

    Q_INVOKABLE QCoro::QmlTask getWithDetails(int id) const
    {
        return s_interactorInstance->get(id);
    }

    Q_INVOKABLE CreatePresenterComponentDTO getCreateDTO()
    {
        return s_interactorInstance->getCreateDTO();
    }

    Q_INVOKABLE UpdatePresenterComponentDTO getUpdateDTO()
    {
        return s_interactorInstance->getUpdateDTO();
    }

    Q_INVOKABLE QCoro::QmlTask create(const CreatePresenterComponentDTO &dto)
    {
        return s_interactorInstance->create(dto);
    }

    Q_INVOKABLE QCoro::QmlTask update(const UpdatePresenterComponentDTO &dto)
    {
        return s_interactorInstance->update(dto);
    }

    Q_INVOKABLE QCoro::QmlTask remove(int id)
    {
        return s_interactorInstance->remove(id);
    }

private:
    PresenterComponentInteractor *s_interactorInstance = nullptr;
};