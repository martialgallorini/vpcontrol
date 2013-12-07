import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

Item {
    id: root

    property string address
    property bool connected

    signal connectionChangeRequested(bool requestedConnectionState)

    onConnectedChanged: console.log("projectorView.connected: " + projectorView.connected)

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
        Button {
            text: root.connected ? "Disconnect" : "Connect"

            onClicked: root.connectionChangeRequested(!connected)
        }
    }
}
