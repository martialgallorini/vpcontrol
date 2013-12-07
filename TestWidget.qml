import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

RowLayout {
    id: root

    anchors.left: parent.left
    anchors.right: parent.right

    property string nameText:    "name"
    property string modelText:   "model"
    property string addressText: "address"
    property bool   isConnected: false
    property bool   isMuted:     false
    property bool   isPowered:   false
    property var    inputSources: ["InputSources"]

    //property var sources

    function setSource(sourceIndex) {
        sourceComboBox.currentIndex = sourceIndex
    }

    Button {
        text: root.isConnected ? "Disconnect" : "Connect"
    }

    ColumnLayout {
        id: idInfo
        spacing: 0
        Text {text: root.nameText }
        Text {text: root.modelText}
    }

    TextField {
        text: root.addressText
        anchors.top: idInfo.top
        anchors.bottom: idInfo.bottom
        Layout.fillWidth: true
    }

    ComboBox {
        model: root.inputSources
    }

    Button {
        text: root.isMuted ? "Unmute" : "Mute"
    }

    Button {
        text: root.isPowered ? "Turn on" : "Shutdown"
    }

/*
    ComboBox {
        id: sourceComboBox
        model: root.sources
        currentIndex: sourceIndex
    }
*/
}
