import QtQuick 2.0

Item {
    id: idContainer
    signal pressed
    property alias label: idButtonLabel.text
    property alias color: idBackground.color
    width: idButtonLabel.width + 30
    height: idButtonLabel.height + 30

    Rectangle {
        id: idBackground
        anchors.fill: parent
        anchors.margins: 5
        radius: 4
        border.width: 2
        border.color: "#303030FF"

        MouseArea {
            anchors.fill: parent

            onClicked: {
                idContainer.pressed()
            }
        }

        Text {
            id: idButtonLabel
            anchors.centerIn: parent
        }
    }
}

