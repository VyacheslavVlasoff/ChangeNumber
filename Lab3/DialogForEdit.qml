import QtQuick 2.2
import QtQuick.Window 2.2
import QtQuick.Controls 2.2 // это версия библиотеки, содержащей Contol (аналоги виджетов) для версии Qt 5.6
import QtQuick.Layouts 1.2


Window {
    id: root
    modality: Qt.ApplicationModal  // окно объявляется модальным
    title: qsTr("Редактирование информации")
    minimumWidth: 400
    maximumWidth: 400
    minimumHeight: 300
    maximumHeight: 300

    property int currentIndex: -1

    GridLayout {
        anchors { left: parent.left; top: parent.top; right: parent.right; bottom: buttonCancel.top; margins: 10 }
        columns: 2

        Label {
            Layout.alignment: Qt.AlignRight  // выравнивание по правой стороне
            text: qsTr("Континент:")
        }
        TextField {
            id: textNameK
            Layout.fillWidth: true
            placeholderText: qsTr("Введите название")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Государство:")
        }
        TextField {
            id: textNameG
            Layout.fillWidth: true
            placeholderText: qsTr("Введите название")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Столица государства:")
        }
        TextField {
            id: textNameS
            Layout.fillWidth: true
            placeholderText: qsTr("Введите название")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Рекомендуемый вид отдыха:")
        }
        TextField {
            id: textCheell
            Layout.fillWidth: true
            placeholderText: qsTr("Введите информацию")
        }
    }
    Button {
        visible: {textNameK.length>0 && textNameG.length>0 && textNameS.length>0 && root.currentIndex <0}
        anchors { right: buttonCancel.left; verticalCenter: buttonCancel.verticalCenter; rightMargin: 10 }
        text: qsTr("Добавить в список")
        width: 100
        onClicked: {
            root.hide()
            add(textNameK.text, textNameG.text, textNameS.text, textCheell.text)
        }
    }
    Button {
        visible: {root.currentIndex>=0}
        anchors { right: buttonCancel.left; verticalCenter: buttonCancel.verticalCenter; rightMargin: 10 }
        text: qsTr("Применить")
        width: 100
        onClicked: {
            root.hide()
            edit(textNameK.text, textNameG.text, textNameS.text, textCheell.text, root.currentIndex)
        }
    }
    Button {
        id: buttonCancel
        anchors { right: parent.right; bottom: parent.bottom; rightMargin: 10; bottomMargin: 10 }
        text: qsTr("Отменить")
        width: 100
        onClicked: {
             root.hide()
        }
    }


    function execute(nameK, nameG, nameS, cheell, index){
        textNameK.text = nameK
        textNameG.text = nameG
        textNameS.text = nameS
        textCheell.text = cheell
        root.currentIndex = index

        root.show()
    }
 }
