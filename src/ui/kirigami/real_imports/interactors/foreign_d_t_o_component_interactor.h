// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once
#include "d_t_o_component/d_t_o_component_interactor.h"
#include <QCoroQml>
#include <QCoroQmlTask>
#include <QQmlEngine>

using namespace QleanyEditor::Interactor::DTOComponent;

class ForeignDTOComponentInteractor : public QObject
{
    Q_OBJECT
    QML_SINGLETON
    QML_NAMED_ELEMENT(DTOComponentInteractor)

public:
    ForeignDTOComponentInteractor(QObject *parent = nullptr)
        : QObject(parent)
    {
        s_interactorInstance = DTOComponentInteractor::instance();
    }

    Q_INVOKABLE QCoro::QmlTask get(int id) const
    {
        return s_interactorInstance->get(id);
    }

    Q_INVOKABLE CreateDTOComponentDTO getCreateDTO()
    {
        return s_interactorInstance->getCreateDTO();
    }

    Q_INVOKABLE UpdateDTOComponentDTO getUpdateDTO()
    {
        return s_interactorInstance->getUpdateDTO();
    }

    Q_INVOKABLE QCoro::QmlTask create(const CreateDTOComponentDTO &dto)
    {
        return s_interactorInstance->create(dto);
    }

    Q_INVOKABLE QCoro::QmlTask update(const UpdateDTOComponentDTO &dto)
    {
        return s_interactorInstance->update(dto);
    }

    Q_INVOKABLE QCoro::QmlTask remove(int id)
    {
        return s_interactorInstance->remove(id);
    }

private:
    DTOComponentInteractor *s_interactorInstance = nullptr;
};