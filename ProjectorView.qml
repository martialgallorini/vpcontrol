import QtQuick 2.2
import QtQuick.Layouts 1.1

Item {
    id: root

    property string address

    Rectangle {
        anchors.fill: root
        color: "aliceblue"
        border.color: "aquamarine"
        radius: 10
    }

    ColumnLayout {
        TextInput {
            id: addressControl

            text: "Default"

            onAccepted: root.address = text //console.log(addressControl.text + " " + root.address)
        }
    }
}
