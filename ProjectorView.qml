import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

Item {
    id: root

    property string address
    property bool connected
    property alias power: powerLalel.text
    property alias projectorName: projectorNameLabel.text
    property alias projectorManufacturer: projectorManufacturerLabel.text

    signal queryAll()
    signal setConnect(bool value)
    signal setPower(bool value)

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

            text: "192.168.0.9"

            onAccepted: root.address = text //console.log(addressControl.text + " " + root.address)
        }
        Text {
            id: projectorNameLabel
        }
        Text {
            id: projectorManufacturerLabel
        }

        Button {
            text: root.connected ? "Disconnect" : "Connect"

            onClicked: root.setConnect(!connected)
        }
        Button {
            text: "Query all"
            onClicked: root.queryAll()
        }

        RowLayout {
            Text {
                id: powerLalel

                text: "Power status"
            }
            Button {
                text: "Power ON"
                onClicked: root.setPower(true)
            }
            Button {
                text: "Power OFF"
                onClicked: root.setPower(false)
            }
        }
    }
}
