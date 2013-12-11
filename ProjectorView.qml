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
