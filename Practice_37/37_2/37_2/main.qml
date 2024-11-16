import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Videoplayer")

    Button {
        id: play
        text: "▶"
        font.pointSize: 16
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -2*width

    }

    Button {
        id: pause
        text: "||"
        font.pointSize: 12
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -width
    }

    Button {
        id: stop
        text: "■"
        font.pointSize: 16
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: width
    }

    Button {
        id: back
        text: "≪"
        font.pointSize: 14
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter

    }

    Button {
        id: forward
        text: "≫"
        font.pointSize: 14
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 2*width
    }


    ProgressBar {
        id: progressbar
        width: parent.width
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0.5*parent.height - play.height - 5
    }


//    Text {
//        id: hello
//        text: "Hello, Misha!"
//        font.pointSize: 24
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.verticalCenter: parent.verticalCenter
//    }

//    Button {
//        text: "GO!"
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.verticalCenter: parent.verticalCenter
//        anchors.verticalCenterOffset: 100
//        onClicked: {
//            hello.color = "Orange"
//        }
//    }
}
