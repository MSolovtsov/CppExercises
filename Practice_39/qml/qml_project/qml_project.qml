import QtQuick
import QtQuick.Window
import QtQuick.Controls

ApplicationWindow {
    id: main
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    // Колонка
    Column {
        id: mainElements
        anchors.fill: parent // Под кого мы растягиваемся
        spacing: 10 // расстояние между элементами в этой колонке
        // Элементы управления в строку
        Row {
            spacing: 5 // расстояние между элементами
            width: parent.width - 20 // Ширина привязана к ширине родителя
            SpinBox {
                id: spacingSpinBox
                onValidatorChanged: {
                    mainElements.spacing = value
                }
            }
            ComboBox {
                id: currentColor
                width: parent.width * 2/3
                model: ["red", "yellow", "green"]
            }
            CheckBox {
                id: hasBorder
                onCheckStateChanged: {
                    if (checkState == Qt.Checked){
                        colorBox.border.width = 10
                    } else {
                        colorBox.border.width = 0
                    }
                }
            }
            Button {
                text: "quit"
                onClicked: Qt.quit();
            }
        }

        Rectangle {
            id: colorBox
            width: parent.width - 20
            height: parent.width - 40
            color: currentColor.currentText
            border.width: 0
            border.color: "black"
        }
    }
}
