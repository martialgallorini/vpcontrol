import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

RowLayout {
    id: root

    anchors.left: parent.left
    anchors.right: parent.right

    spacing: 2

    property string text: "default Text"
    property string button1Text: "default"
    property string button2Text: "default"

    TextField {
        text: root.text
        Layout.fillWidth: true
    }
}
