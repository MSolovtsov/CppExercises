import QtQuick
import QtQuick.Window
import QtQuick.Controls

ApplicationWindow {
    id: main
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: scene
        anchors.fill: parent

        Rectangle {
            id: leftRectangle
            x: 100
            y: 200
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 5
            //
            MouseArea {
                anchors.fill: parent
                onClicked: scene.state = "LeftState"
            }
        }

        Rectangle {
            id: rightRectangle
            x: 300
            y: 200
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 5
            //
            MouseArea {
                anchors.fill: parent
                onClicked: scene.state = "RightState"
            }
        }

        Rectangle {
            id: ball
            color: "darkgreen"
            x: leftRectangle.x + 5
            y: leftRectangle.y + 5
            width: leftRectangle.width - 10
            height: leftRectangle.height - 10
            radius: width / 2
        }

        // Состояния
        states: [
            State {
                name: "RightState"
                PropertyChanges {
                    target: ball
                    x: rightRectangle.x + 5
                }
            },

            State {
                name: "LefttState"
                PropertyChanges {
                    target: ball
                    x: leftRectangle.x + 5
                }
            }
        ]

        // Переходы
        transitions: [
            Transition {
                from: "LeftState"
                to: "RightState"


                NumberAnimation {
                    properties: "x, y"
                    duration: 1000
                    easing.type: Easing.InOutExpo
                }
            },

            Transition {
                from: "RightState"
                to: "LeftState"


                NumberAnimation {
                    properties: "x, y"
                    duration: 1000
                    easing.type: Easing.OutBounce
                }
            }
        ]

    }
}
