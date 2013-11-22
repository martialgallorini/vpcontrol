import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0
//import net.charlesfleche.vpcontrol 1.0

ApplicationWindow {
    id: root
    title: "vpcontrol"

    width: 800
    height: 600

/*
    MockProjector {
        id: projector
    }

    Text {
        text: projector.name
    }
*/


    ListView {
        anchors.fill: parent

        model: projectorsModel
        delegate: RowLayout {
                    Text {
                        text: name
                    }

                    Text {
                        text: manufacturer
                    }

                    Text {
                        text: address
                    }
                  }
    }
}
