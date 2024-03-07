// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once
#include "entity_component/entity_component_interactor.h"
#include <QCoroQml>
#include <QCoroQmlTask>
#include <QQmlEngine>

using namespace QleanyEditor::Interactor::EntityComponent;

class ForeignEntityComponentInteractor : public QObject
{
    Q_OBJECT
    QML_SINGLETON
    QML_NAMED_ELEMENT(EntityComponentInteractor)

public:
    ForeignEntityComponentInteractor(QObject *parent = nullptr)
        : QObject(parent)
    {
        s_interactorInstance = EntityComponentInteractor::instance();
    }

    Q_INVOKABLE QCoro::QmlTask get(int id) const
    {
        return s_interactorInstance->get(id);
    }

    Q_INVOKABLE QCoro::QmlTask getWithDetails(int id) const
    {
        return s_interactorInstance->get(id);
    }

    Q_INVOKABLE UpdateEntityComponentDTO getUpdateDTO()
    {
        return s_interactorInstance->getUpdateDTO();
    }

    Q_INVOKABLE QCoro::QmlTask update(const UpdateEntityComponentDTO &dto)
    {
        return s_interactorInstance->update(dto);
    }

private:
    EntityComponentInteractor *s_interactorInstance = nullptr;
};