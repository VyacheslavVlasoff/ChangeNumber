import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.5  // это версия библиотеки, содержащей Contol (аналоги виджетов) для версии Qt 5.6
import QtQuick.Layouts 1.2


Window {
    id: root
    modality: Qt.ApplicationModal  // окно объявляется модальным
    title: qsTr("Добавление информации")
    minimumWidth: 400
    maximumWidth: 400
    minimumHeight: 300
    maximumHeight: 300

    property bool isEdit: false
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
            Layout.alignment: Qt.AlignRight  // выравнивание по правой стороне
            text: qsTr("Государство:")
        }
        TextField {
            id: textNameG
            Layout.fillWidth: true
            placeholderText: qsTr("Введите название")
        }
        Label {
            Layout.alignment: Qt.AlignRight  // выравнивание по правой стороне
            text: qsTr("Столица государства:")
        }
        TextField {
            id: textNameS
            Layout.fillWidth: true
            placeholderText: qsTr("Введите название")
        }
        Label {
            Layout.alignment: Qt.AlignRight  // выравнивание по правой стороне
            text: qsTr("Рекомендуемый вид отдыха:")
        }
        TextField {
            id: textCheell
            Layout.fillWidth: true
            placeholderText: qsTr("Введите информацию")
        }
    }

    Button {
        //visible: {textNameK.length>0 && textNameG.length>0 && textNameS.length>0}
        anchors { right: buttonCancel.left; verticalCenter: buttonCancel.verticalCenter; rightMargin: 10 }
        text: qsTr("ОК")
        width: 100
        onClicked: {
                root.hide()
                if (currentIndex<0)
                {
                    add(textNameK.text, textNameG.text, textNameS.text, textCheell.text)
                }
                else
                {
                    edit(textNameK.text, textNameG.text, textNameS.text, textCheell.text,  root.currentIndex)
                }

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

    // изменение статуса видимости окна диалога
    onVisibleChanged: {
      if (visible && currentIndex < 0) {
          textNameK.text = ""
          textNameG.text = ""
          textNameS.text = ""
          textCheell.text = ""

      }
    }

    function execute(nameK, nameG, nameS, cheell, index){
        isEdit = true;
        textNameK.text = nameK
        textNameG.text = nameG
        textNameS.text = nameS
        textCheell.text = cheell
        root.currentIndex = index

        root.show()
    }
 }
