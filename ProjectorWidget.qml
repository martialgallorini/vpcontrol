import QtQuick 2.1
import QtQuick.Controls 1.0


Item {
    width: 800
    height: 100

    Row {
        x: 21
        y: 19

Rectangle {
        id: connectedButton
        width: 73
        height: 63
        color: "#ffffff"
    }

Grid {
        columns: 6

        Label {
            id: nameLabel
            width: 111
            height: 17
            text: "name"
        }

        Label {
                id: ipLabel
                width: 95
                height: 17
                text: "ip"
        }

        TextField {
            id: ipEdit
            placeholderText: "Text Field"
        }

        Label {
            id: sourceLabel
            width: 91
            height: 17
            text: "Source"
            horizontalAlignment: Text.AlignHCenter
        }

        Button {
            id: unmuteButton
            text: "Unmute"
        }

        Button {
            id: powerOnButton
            text: "Power ON"
        }

        Label {
            id: manucfacturerLabel
            width: 122
            height: 17
            text: "manufacturer"
        }

        Label {
                id: portLabel
                width: 116
                height: 17
                text: "port"
            }

        TextField {
            id: portEdit
            placeholderText: "Text Field"
        }

        ComboBox {
            id: sourceComboBox
            width: 125
            height: 25
        }

        Button {
            id: muteButton
            text: "Mute"
        }

        Button {
            id: powerOffButton
            text: "Power OFF"
            activeFocusOnPress: false
        }

    }
    }
}
