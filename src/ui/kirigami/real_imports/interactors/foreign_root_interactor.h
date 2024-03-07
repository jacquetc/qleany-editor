// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once
#include "root/root_interactor.h"
#include <QCoroQml>
#include <QCoroQmlTask>
#include <QQmlEngine>

using namespace QleanyEditor::Interactor::Root;

class ForeignRootInteractor : public QObject
{
    Q_OBJECT
    QML_SINGLETON
    QML_NAMED_ELEMENT(RootInteractor)

public:
    ForeignRootInteractor(QObject *parent = nullptr)
        : QObject(parent)
    {
        s_interactorInstance = RootInteractor::instance();
    }

    Q_INVOKABLE QCoro::QmlTask get(int id) const
    {
        return s_interactorInstance->get(id);
    }

private:
    RootInteractor *s_interactorInstance = nullptr;
};