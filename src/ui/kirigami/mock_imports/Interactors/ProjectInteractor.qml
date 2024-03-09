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
        // TODO: change this dict below to conform to the command's dto out
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
            // TODO: change this signal name to the correct one
                EventDispatcher.project().loadProjectChanged(reply_dto);
            })
        }

        return task
    }

    
    function getLoadProjectDTO() {
    // TODO: change this dict below to conform to the command's dto in
        return {
            "id": 0,
            "content": ""
        }
    }
    



    function saveProject(dto) {
        // TODO: change this dict below to conform to the command's dto out
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
            // TODO: change this signal name to the correct one
                EventDispatcher.project().saveProjectChanged(reply_dto);
            })
        }

        return task
    }

    
    function getSaveProjectDTO() {
    // TODO: change this dict below to conform to the command's dto in
        return {
            "id": 0,
            "content": ""
        }
    }
    



    function createProject(dto) {
        // TODO: change this dict below to conform to the command's dto out
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
            // TODO: change this signal name to the correct one
                EventDispatcher.project().createProjectChanged(reply_dto);
            })
        }

        return task
    }

    
    function getCreateProjectDTO() {
    // TODO: change this dict below to conform to the command's dto in
        return {
            "id": 0,
            "content": ""
        }
    }
    



    function closeProject(dto) {
        // TODO: change this dict below to conform to the command's dto out
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
            // TODO: change this signal name to the correct one
                EventDispatcher.project().closeProjectChanged(reply_dto);
            })
        }

        return task
    }

    



}