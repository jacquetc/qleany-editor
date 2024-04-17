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
            task.setSignalFn(function(){EventDispatcher.repository().getReplied(id)})
        }

        return task
    }

    function getWithDetails(id) {
        // mocking QCoro::Task
        var component = Qt.createComponent("QCoroQmlTask.qml");
        if (component.status === Component.Ready) {
            var task = component.createObject(interactor);
            task.setValue(dto);
            task.setDelay(50);
            task.setSignalFn(function(){EventDispatcher.repository().getWithDetailsReplied(id)})
        }

        return task
    }

    function getAll() {
        // fill it with whatever you want to return
        var dtos = []

        // mocking QCoro::Task
        var component = Qt.createComponent("QCoroQmlTask.qml");
        if (component.status === Component.Ready) {
            var task = component.createObject(interactor);
            task.setValue(dtos);
            task.setDelay(50);
            task.setSignalFn(function(){EventDispatcher.repository().getAllReplied(dtos)})
        }

        return task
    }

    function getCreateDTO() {
        return {
            "content": "Repository 1"
        }
    }

    function create(dto) {
        // create random id
        var newId = Math.floor(Math.random() * 1000000);
        dto["id"] = newId;

        // mocking QCoro::Task
        var component = Qt.createComponent("QCoroQmlTask.qml");
        if (component.status === Component.Ready) {
            var task = component.createObject(interactor);
            task.setValue(dto);
            task.setDelay(50);
            task.setSignalFn(function(){EventDispatcher.repository().created(dto)})
        }

        return task
    }

    function getUpdateDTO() {
        return {
            "id": 0,
            "content": ""
        }
    }

    function update(dto) {

        // mocking QCoro::Task
        var component = Qt.createComponent("QCoroQmlTask.qml");
        if (component.status === Component.Ready) {
            var task = component.createObject(interactor);
            task.setValue(dto);
            task.setDelay(50);
            task.setSignalFn(function(){
                EventDispatcher.repository().updated(dto);
                EventDispatcher.repository().allRelationsInvalidated(dto.id);
            })
        }

        return task
    }

    signal repositoryRemoved(int id)
    function remove(id) {
        // mocking QCoro::Task
        var component = Qt.createComponent("QCoroQmlTask.qml");
        if (component.status === Component.Ready) {
            var task = component.createObject(interactor);
            task.setValue(dto);
            task.setDelay(50);
            task.setSignalFn(function(){
                EventDispatcher.repository().removed(id);
            })
        }

        return task
    }


}