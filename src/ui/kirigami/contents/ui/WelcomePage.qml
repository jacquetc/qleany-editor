import QtQuick
import QtQuick.Controls as Controls
import QtQuick.Layouts
import QtQuick.Dialogs

import org.kde.kirigami as Kirigami
import Interactors
import Models

Kirigami.Page {

    id: page

    title: i18n("Main Page")

    actions: [
        Kirigami.Action {
            text: i18n("Load project manifest")
            icon.name: "list-add"
            tooltip: i18n("Add one to the counter")
            onTriggered: root.pageStack.push(secondPage)
        },

        Kirigami.Action {
            text: i18n("New manifest")
            icon.name: "list-add"
            tooltip: i18n("Create a new manifest for a project")
            onTriggered: root.pageStack.push(secondPage)
        }
    ]

    ColumnLayout {
        anchors.fill: parent

        Kirigami.Heading {
            Layout.alignment: Qt.AlignHorizontalCenter | Qt.AlignTop
            text: i18n("Recent projects")
        }
        RecentProjectListModel  {
            id: listModel
        }
        ListView {
            model: listModel
            Layout.fillHeight: true
            Layout.fillWidth: true
            delegate: Item {
                width: ListView.width
                height: 50

                Text {
                    text: model.rootPath
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                }

                // Kirigami.Action {
                //     text: i18n("Edit")
                //     icon.name: "document-edit"
                //     onTriggered: {
                //         ProjectInteractor.loadProject(model.fileName).then(
                //                     function() {

                //                 root.pageStack.push(Qt.createComponent("Index.qml"))
                //             }
                //         )


                //     }
                // }
            }
        }
    }
}
