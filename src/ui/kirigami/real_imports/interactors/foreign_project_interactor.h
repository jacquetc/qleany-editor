// This file was generated automatically by Qleany's generator, edit at your own risk!
// If you do, be careful to not overwrite it when you run the generator again.
#pragma once
#include "project/project_interactor.h"
#include <QCoroQml>
#include <QCoroQmlTask>
#include <QQmlEngine>

using namespace QleanyEditor::Interactor::Project;

class ForeignProjectInteractor : public QObject
{
    Q_OBJECT
    QML_SINGLETON
    QML_NAMED_ELEMENT(ProjectInteractor)

public:
    ForeignProjectInteractor(QObject *parent = nullptr)
        : QObject(parent)
    {
        s_interactorInstance = ProjectInteractor::instance();
    }

    Q_INVOKABLE QCoro::QmlTask get(int id) const
    {
        return s_interactorInstance->get(id);
    }

    Q_INVOKABLE QCoro::QmlTask loadProject(LoadProjectDTO dto)
    {
        return s_interactorInstance->loadProject(dto);
    }

    Q_INVOKABLE QCoro::QmlTask saveProject(SaveProjectDTO dto)
    {
        return s_interactorInstance->saveProject(dto);
    }

    Q_INVOKABLE QCoro::QmlTask createProject(CreateProjectDTO dto)
    {
        return s_interactorInstance->createProject(dto);
    }

    Q_INVOKABLE QCoro::QmlTask closeProject()
    {
        return s_interactorInstance->closeProject();
    }

private:
    ProjectInteractor *s_interactorInstance = nullptr;
};