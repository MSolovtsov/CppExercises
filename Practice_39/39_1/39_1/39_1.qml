import QtQuick
import QtQuick.Window
import QtQuick.Controls

ApplicationWindow {
    id: main
    width: 640
    height: 480
    visible: true
    title: qsTr("Ex/39.1")

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
                onClicked: {
                    ball.x += 10
                    if (ball.x < rightRectangle.x)
                        scene.state = "GoState"
                    else
                        scene.state = "StartState"
                }
            }
            //
            Text {
                id: move
                anchors.centerIn: parent
                text: "Move"
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
                onClicked: {
                    scene.state = "StartState"
                }
            }
            //
            Text {
                id: start
                anchors.centerIn: parent
                text: "ToStart"
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
                name: "GoState"
                PropertyChanges {
                    target: ball
                    x: ball.x
                }
            },

            State {
                name: "StartState"
                PropertyChanges {
                    target: ball
                    x: leftRectangle.x + 5
                }
            }
        ]

        // Переходы
        transitions: [
            Transition {
                from: "GoState"
                to: "GoState"
            },

            Transition {
                from: "GoState"
                to: "StartState"


                NumberAnimation {
                    properties: "x, y"
                    duration: 1000
                    easing.type: Easing.OutBounce
                }
            }
        ]

    }
}
