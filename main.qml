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
        onConnectionChangeRequested: projectorModel.connected = requestedConnectionState
    }
}
