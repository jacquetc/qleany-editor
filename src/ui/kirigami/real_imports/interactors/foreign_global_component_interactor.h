// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once
#include "global_component/global_component_interactor.h"
#include <QCoroQml>
#include <QCoroQmlTask>
#include <QQmlEngine>

using namespace QleanyEditor::Interactor::GlobalComponent;

class ForeignGlobalComponentInteractor : public QObject
{
    Q_OBJECT
    QML_SINGLETON
    QML_NAMED_ELEMENT(GlobalComponentInteractor)

public:
    ForeignGlobalComponentInteractor(QObject *parent = nullptr)
        : QObject(parent)
    {
        s_interactorInstance = GlobalComponentInteractor::instance();
    }

    Q_INVOKABLE QCoro::QmlTask get(int id) const
    {
        return s_interactorInstance->get(id);
    }

    Q_INVOKABLE UpdateGlobalComponentDTO getUpdateDTO()
    {
        return s_interactorInstance->getUpdateDTO();
    }

    Q_INVOKABLE QCoro::QmlTask update(const UpdateGlobalComponentDTO &dto)
    {
        return s_interactorInstance->update(dto);
    }

private:
    GlobalComponentInteractor *s_interactorInstance = nullptr;
};