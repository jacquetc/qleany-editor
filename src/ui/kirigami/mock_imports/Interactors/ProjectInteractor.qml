// This file was generated automatically by Qleany's generator, edit at your own risk! 
// If you do, be careful to not overwrite it when you run the generator again.
pragma Singleton

import QtQuick

QtObject {
    id: interactor


    function get(id) {
        // mocking QCoro::Task
        var component = Qt.createComponent("QCoroQmlTask.qml");
        if (component.status === Component.Ready) {
            var task = component.createObject(interactor);
            task.setValue(dto);
            task.setDelay(50);
            task.setSignalFn(function(){EventDispatcher.project().getReplied(id)})
        }

        return task
    }


    function loadProject(dto) {
        // change this function to return the correct signal name, dto in and dto out
        var reply_dto = {
            "id": 0,
            "content": ""
        }

        // mocking QCoro::Task
        var component = Qt.createComponent("QCoroQmlTask.qml");
        if (component.status === Component.Ready) {
            var task = component.createObject(interactor);
            task.setValue(reply_dto);
            task.setDelay(50);
            task.setSignalFn(function(){
                EventDispatcher.project().loadProjectChanged(reply_dto);
            })
        }

        return task
    }


    function saveProject(dto) {
        // change this function to return the correct signal name, dto in and dto out
        var reply_dto = {
            "id": 0,
            "content": ""
        }

        // mocking QCoro::Task
        var component = Qt.createComponent("QCoroQmlTask.qml");
        if (component.status === Component.Ready) {
            var task = component.createObject(interactor);
            task.setValue(reply_dto);
            task.setDelay(50);
            task.setSignalFn(function(){
                EventDispatcher.project().saveProjectChanged(reply_dto);
            })
        }

        return task
    }


    function createProject(dto) {
        // change this function to return the correct signal name, dto in and dto out
        var reply_dto = {
            "id": 0,
            "content": ""
        }

        // mocking QCoro::Task
        var component = Qt.createComponent("QCoroQmlTask.qml");
        if (component.status === Component.Ready) {
            var task = component.createObject(interactor);
            task.setValue(reply_dto);
            task.setDelay(50);
            task.setSignalFn(function(){
                EventDispatcher.project().createProjectChanged(reply_dto);
            })
        }

        return task
    }


    function closeProject(dto) {
        // change this function to return the correct signal name, dto in and dto out
        var reply_dto = {
            "id": 0,
            "content": ""
        }

        // mocking QCoro::Task
        var component = Qt.createComponent("QCoroQmlTask.qml");
        if (component.status === Component.Ready) {
            var task = component.createObject(interactor);
            task.setValue(reply_dto);
            task.setDelay(50);
            task.setSignalFn(function(){
                EventDispatcher.project().closeProjectChanged(reply_dto);
            })
        }

        return task
    }


}