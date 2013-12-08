import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0
import org.vpcontrol.qmlcomponents 1.0

ApplicationWindow {
    id: root
    title: "vpcontrol"

    width: 800
    height: 600

    Projector {
        id: projectorModel

        address: projectorView.address
    }

    ProjectorView {
        id: projectorView
        anchors.fill: parent

        connected: projectorModel.connected
        onSetConnect: projectorModel.connected = value
        onSetPower: projectorModel.setPower(value)
        onSetMute: projectorModel.setMute(value)

        onQueryAll: projectorModel.queryAll()

        Connections {
            target: projectorModel
            onPowerChanged: {
                switch (powerStatus) {
                case 0:
                    projectorView.power = "Off";
                    break;
                case 1:
                    projectorView.power = "Warm up"
                    break;
                case 2:
                    projectorView.power = "On"
                    break;
                case 3:
                    projectorView.power = "Cooling"
                    break;
                }
            }

            onVideoMuteChanged: videoMute ? projectorView.videoMute = "Video mute ON" : projectorView.videoMute = "Video mute OFF"
            onAudioMuteChanged: audioMute ? projectorView.audioMute = "Audio mute ON" : projectorView.audioMute = "Audio mute OFF"
            onNameChanged: projectorView.projectorName = projectorName
            onManufacturerChanged: projectorView.projectorManufacturer = manufacturerName
            onModelChanged: projectorView.projectorModel = modelName
        }
    }
}
