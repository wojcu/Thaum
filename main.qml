import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import Thaum 1.0

Window {
    id: idMainWindow
    title: qsTr("Thaum")
    visible: true

    Item {
        anchors.fill: parent

        RenderWidget {
            id: idRenderWidget
            anchors.fill: parent
            active: idMainWindow.active


            InputWidget {
                anchors.fill: parent
                focus: true

                Keys.onPressed: {
                    if (event.key == Qt.Key_Tab) {
                        if (idSideMenu.pullState == 0) {
                            idSideMenu.pullState = 1
                        } else if (idSideMenu.pullState == 2) {
                            idSideMenu.pullState = 3
                        }
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    property int startX: 0
                    property bool ready: false
                    onPressed: {
                        if (idSideMenu.pullState == 0) {
                            if (mouse.x < idMainWindow.width * 0.05) {
                                startX = mouse.x
                                ready = true
                            } else mouse.accepted = false
                        } else if (idSideMenu.pullState == 2) {
                            if (mouse.x < idSideMenu.width) {
                                startX = mouse.x
                                ready = true
                            } else mouse.accepted = false
                        } else mouse.accepted = false
                    }

                    onReleased: {
                        if (ready) {
                            ready = false
                            if (idSideMenu.pullState == 0) {
                                idSideMenu.pullState = 3
                            } else if (idSideMenu.pullState == 2)
                                idSideMenu.pullState = 1
                        } else mouse.accepted = false
                    }

                    onMouseXChanged: {
                        if (ready) {
                            if (idSideMenu.pullState == 0) {
                                idSideMenu.x = mouse.x - startX - idSideMenu.width
                                if (idSideMenu.x > -2 * idSideMenu.width / 3) {
                                    idSideMenu.pullState = 1
                                    ready = false
                                }
                            } else if (idSideMenu.pullState == 2) {
                                if (mouse.x - startX < 0) {
                                    idSideMenu.x = mouse.x - startX
                                    if (idSideMenu.x < -idSideMenu.width / 3) {
                                        idSideMenu.pullState = 3
                                        ready = false
                                    }
                                }
                            } else mouse.accepted = false
                        } else mouse.accepted = false
                    }
                }
            }

            SideMenu {
                id: idSideMenu
                anchors.top: parent.top
                anchors.bottom: parent.bottom
            }


        }
    }
}
