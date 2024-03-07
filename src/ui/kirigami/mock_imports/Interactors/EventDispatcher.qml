// This file was generated automatically by Qleany's generator, edit at your own risk! 
// If you do, be careful to not overwrite it when you run the generator again.
pragma Singleton

import QtQuick

QtObject {
    function progress() {
        return ProgressSignals;
    }
    function error() {
        return ErrorSignals;
    }



    function root() {
        return RootSignals;
    }

    function recentProject() {
        return RecentProjectSignals;
    }

    function project() {
        return ProjectSignals;
    }

    function globalComponent() {
        return GlobalComponentSignals;
    }

    function entityComponent() {
        return EntityComponentSignals;
    }

    function entity() {
        return EntitySignals;
    }

}