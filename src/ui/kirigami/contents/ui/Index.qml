
import QtQuick
import QtQuick.Controls as Controls
import QtQuick.Layouts
import QtQuick.Dialogs

import org.kde.kirigami as Kirigami

Kirigami.Page {

    id: page

    title: i18n("Main Page")

    actions: [
        Kirigami.Action {
            text: i18n("Plus One")
            icon.name: "list-add"
            tooltip: i18n("Add one to the counter")
            onTriggered: root.pageStack.push(secondPage)
        }
    ]

    ColumnLayout {
        width: page.width

        anchors.centerIn: parent

        Kirigami.Heading {
            Layout.alignment: Qt.AlignCenter
            text: root.counter === 0 ? i18n("Hello, World!") : root.counter
        }

        Controls.Button {
            Layout.alignment: Qt.AlignHCenter
            text: i18n("+ 1")
            onClicked: root.counter += 1
        }
    }
}
