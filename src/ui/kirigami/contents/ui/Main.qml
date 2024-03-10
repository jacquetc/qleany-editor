// SPDX-License-Identifier: GPL-2.0-or-later
// SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>

import QtQuick
import QtCore
import QtQuick.Controls as Controls
import QtQuick.Layouts
import QtQuick.Dialogs

import org.kde.kirigami as Kirigami
import Interactors
import org.kde.qleanyeditor

Kirigami.ApplicationWindow {
    id: root

    title: i18n("Qleany Editor")

    minimumWidth: Kirigami.Units.gridUnit * 20
    minimumHeight: Kirigami.Units.gridUnit * 20

    onClosing: App.saveWindowGeometry(root)

    onWidthChanged: saveWindowGeometryTimer.restart()
    onHeightChanged: saveWindowGeometryTimer.restart()
    onXChanged: saveWindowGeometryTimer.restart()
    onYChanged: saveWindowGeometryTimer.restart()

    Component.onCompleted: App.restoreWindowGeometry(root)

    // This timer allows to batch update the window size change to reduce
    // the io load and also work around the fact that x/y/width/height are
    // changed when loading the page and overwrite the saved geometry from
    // the previous session.
    Timer {
        id: saveWindowGeometryTimer
        interval: 1000
        onTriggered: App.saveWindowGeometry(root)
    }

    property int counter: 0

    FileDialog {
        id: loadProjectFileDialog
        title: i18n("Load project")
        nameFilters: ["YAML files (*.yaml)"]
        currentFolder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)
        onAccepted: {
            var file = loadProjectFileDialog.selectedFile
            if (file) {
                var dto = ProjectInteractor.getLoadProjectDTO()
                dto.fileName = file
                console.log("loading project")
                ProjectInteractor.loadProject(dto).then(
                            function() {
                        console.log("project loaded")
                    }
                )
            }
        }
    }

    globalDrawer: Kirigami.GlobalDrawer {
        title: i18n("Qleany Editor")

        isMenu: !Kirigami.Settings.isMobile
        actions: [
            Kirigami.Action {
                text: i18n("Load project")
                icon.name: "list-add"
                onTriggered: loadProjectFileDialog.open()}

            ,
            Kirigami.Action {
                text: i18n("About qleany-editor")
                icon.name: "help-about"
                onTriggered: root.pageStack.pushDialogLayer("About.qml")
            },
            Kirigami.Action {
                text: i18n("Quit")
                icon.name: "application-exit"
                onTriggered: Qt.quit()
            }
        ]
    }

    contextDrawer: Kirigami.ContextDrawer {
        id: contextDrawer
    }

    WelcomePage {
        id: welcomePage
    }

    pageStack.initialPage: welcomePage
}
