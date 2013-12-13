import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1

Rectangle {
    id: root

    property string address
    property bool connected

    property int power
    property alias projectorName: nameText.text
    property string projectorManufacturer
    property string projectorModel
    property bool videoMute
    property bool audioMute
    property bool mute: videoMute || audioMute
    property variant inputSources
    property int inputSource

    signal queryAll()
    signal setConnect(bool value)
    signal setPower(bool value)
    signal setMute(bool value)
    signal setInput(int value)

    width: 256
    height: .5 * width

    color: "transparent"
    border.color: "black"
    radius: 10

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: spacing * 2

        TextInput {
            id: addressTextInput
            Layout.fillWidth: true
            text: "xxx.xxx.xxx.xxx"
            visible: !nameText.visible
        }
        Text {
            id: nameText
            Layout.fillWidth: true
            text: ""
            visible: text.length > 0
        }
        Text {
            id: sourceText
            Layout.fillWidth: true
            text: "Source"
        }

        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true

            property int iconSize: (Math.min(width, height * 3) - 2 * parent.spacing) / 3

            PowerButton {
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                width: parent.iconSize
                height: parent.iconSize
            }
            MuteButton {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                width: parent.iconSize
                height: parent.iconSize
            }
            StatusButton {
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                width: parent.iconSize
                height: parent.iconSize
            }
        }
    }
}

/*
Item {
    id: root

    property string address
    property bool connected

    property alias power: powerLalel.text
    property alias projectorName: projectorNameLabel.text
    property alias projectorManufacturer: projectorManufacturerLabel.text
    property alias projectorModel: projectorModel.text
    property alias videoMute: videoMuteLalel.text
    property alias audioMute: audioMuteLalel.text
    property alias inputSources: inputSourcesComboBox.model
    property alias inputSource: inputSourcesComboBox.currentIndex

    signal queryAll()
    signal setConnect(bool value)
    signal setPower(bool value)
    signal setMute(bool value)
    signal setInput(int value)

    onConnectedChanged: console.log("projectorView.connected: " + projectorView.connected)

    Rectangle {
        anchors.fill: root
        color: "darkgrey"
    }

    RowLayout {
        id: widgetRow

        anchors.fill: parent

        Rectangle {
            anchors.fill: parent
            color: "transparent"
            border.color: "magenta"
            radius: 5
        }

        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true

            Rectangle {
                anchors.fill: parent
                color: "lightgrey"
                radius: 15
            }

            RowLayout {
                anchors.centerIn: parent

                TextInput {
                    id: addressControl
                    text: "192.168.0.9"
                    onAccepted: root.address = text //console.log(addressControl.text + " " + root.address)
                }

                ColumnLayout {
                    //Layout.fillHeight: true

                    Button {
                        text: root.connected ? "Disconnect" : "Connect"
                        onClicked: root.setConnect(!connected)
                    }
                    Button {
                        text: "Refresh"
                        onClicked: root.queryAll()
                    }
                }
            }
        }

        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true

            Rectangle {
                anchors.fill: parent
                color: "lightgrey"
                radius: 15
            }

            ColumnLayout {
                anchors.fill: parent

                Text {
                    id: projectorNameLabel
                    text: "Name"
                }
                Text {
                    id: projectorManufacturerLabel
                    text: "Manufacturer"
                }
                Text {
                    id: projectorModel
                    text: "Model"
                }
            }
        }

        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true

            Rectangle {
                anchors.fill: parent
                color: "lightgrey"
                radius: 15
            }

            RowLayout {
                anchors.fill: parent

                Text {
                    id: powerLalel
                    text: "Power status"
                }
                ColumnLayout {
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

        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true

            Rectangle {
                anchors.fill: parent
                color: "lightgrey"
                radius: 15
            }

            RowLayout {
                anchors.fill: parent

                Text {
                    text: "Input"
                }

                ComboBox {
                    id: inputSourcesComboBox
                    anchors.centerIn: parent
                }
            }
        }

        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true

            Rectangle {
                anchors.fill: parent
                color: "lightgrey"
                radius: 15
            }

            RowLayout {
                anchors.fill: parent

                ColumnLayout {
                    Text {
                        id: videoMuteLalel
                        text: "Video mute status"
                    }
                    Text {
                        id: audioMuteLalel
                        text: "Audio mute status"
                    }
                }
                ColumnLayout {
                    Button {
                        text: "Mute"
                        onClicked: root.setMute(true)
                    }
                    Button {
                        text: "Unmute"
                        onClicked: root.setMute(false)
                    }
                }
            }
        }
    }
}
*/
