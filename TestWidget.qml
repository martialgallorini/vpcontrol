import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

ToolBar {
    id: root

    property string text: "default Text"
    property string button1Text: "default"
    property string button2Text: "default"

    Layout.fillWidth: true

    RowLayout {
        anchors.fill: parent
        spacing: 2

        TextField {
            text: root.text
            Layout.fillWidth: true
        }
    }
}
