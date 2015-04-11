import QtQuick 2.0

Item {
    id: idContainer
    property alias label: idLabel.text
    width: idLabel.width + 20
    height: idLabel.height + 20

    Rectangle {
        anchors.fill: parent
        anchors.margins: 5
        radius: 4
        border.width: 2
        color: "#505050FF"
        border.color: "#303030FF"

        Text {
            id: idLabel
            anchors.centerIn: parent
        }
    }
}

