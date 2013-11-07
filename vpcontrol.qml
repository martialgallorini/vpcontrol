import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0


ApplicationWindow {
    id: root
    title: qsTr("Hello World")
    width: 800
    height: 600

    toolBar: ToolBar {
        id: toolBar

        Row {
            ToolButton {
                id: addProjectorAction
                text: "&Add"
                tooltip: "Add a projector"
            }

            ToolButton {
                id: connectAllAction
                text: "&Connect"
                tooltip: "Connect all projectors"
            }

            ToolButton {
                id: disconnectAllAction
                text: "&Disconnect"
                tooltip: "Disconnect all projectors"
            }

            ComboBox {
                id: sourceAllComboBox
                model: ["DVI", "SDI", "HDMI", "RGB1", "RGB2", "VIDEO", "S-VIDEO"]
            }

            ToolButton {
                id: shutterOnAllAction
                text: "&Shutter ON"
                tooltip: "Set shutter ON on all projectors"
            }

            ToolButton {
                id: shutterOffAllAction
                text: "&Shutter OFF"
                tooltip: "Set shutter OFF on all projectors"
            }

            ToolButton {
                id: powerOnAllAction
                text: "&Power ON"
                tooltip: "Set shutter ON on all projectors"
            }

            ToolButton {
                id: powerOffAllAction
                text: "&Power OFF"
                tooltip: "Set shutter OFF on all projectors"
            }
        }
    }

    ListModel {
        id: adresses
        ListElement { address: "192.168.0.1"
                      port: "80" }
        ListElement { address: "192.168.0.2"
                      port: "80" }
        ListElement { address: "192.168.0.3"
                      port: "80" }
        ListElement { address: "192.168.0.4"
                      port: "80" }
        ListElement { address: "192.168.0.5"
                      port: "80" }
        ListElement { address: "192.168.0.6"
                      port: "80" }
    }

    ListView {
        id: listView
        anchors.fill: parent
        model: adresses
        delegate: TestWidget{text: address + ":" + port}
    }

/*
        Rectangle {
            id: rectangle1
            width: 600
            height: 20
            color: "#ffffff"
        }
*/

/*
        ListView {
                anchors.fill: parent
            model: adresses
            delegate: ProjectorWidget
        }
        */

}
