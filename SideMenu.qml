import QtQuick 2.0
import Thaum 1.0

Rectangle {
    id: idSideMenu
    width: idButtonColumn.width + 20
    x: -width
    property int pullState: 0

    onPullStateChanged: {
        if (pullState == 1) {
            idAnimExpand.restart()
        } else if (pullState == 3) {
            idAnimHide.restart()
        }
    }

    ClockWidget {
        id: idClockWidget
    }

    SimulationControl {
        id: idSimControl
    }

    Column {
        id: idButtonColumn
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10

        SimpleLabel {
            label: "Fps: " + idClockWidget.fps
            anchors.horizontalCenter: parent.horizontalCenter
        }

        SimpleButton {
            anchors.horizontalCenter: parent.horizontalCenter
            label: "Auto"
            color: "red"
            onPressed: {
                idSimControl.setAutomatic()
            }
        }

        SimpleButton {
            anchors.horizontalCenter: parent.horizontalCenter
            label: "Player"
            color: "blue"
            onPressed: {
                idSimControl.setWithPlayer()
            }
        }


        SimpleButton {
            anchors.horizontalCenter: parent.horizontalCenter
            label: "Manual"
            color: "green"
            onPressed: {
                idSimControl.setManual()
            }
        }

        SimpleButton {
            anchors.horizontalCenter: parent.horizontalCenter
            label: "Update"
            color: "yellow"
            onPressed: {
                idSimControl.requestUpdate()
            }
        }
    }

    NumberAnimation {
        id: idAnimExpand
        target: idSideMenu
        property: "x"
        to: 0
        duration: 300
        running: false
        onStopped: {
            idSideMenu.pullState = 2
        }
    }

    NumberAnimation {
        id: idAnimHide
        target: idSideMenu
        property: "x"
        to: -idSideMenu.width
        duration: 300
        running: false
        onStopped: {
            idSideMenu.pullState = 0
        }
    }
}
