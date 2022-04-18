import QtQuick 2.2
import QtQuick.Window 2.2
import QtQuick.Controls 2.2// это версия библиотеки, содержащей Contol (аналоги виджетов) для версии Qt 5.6
import QtQuick.Layouts 1.2
import "script.js" as Js

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("СПРАВОЧНИК ПУТЕШЕСТВЕННИКА")

    // объявляется системная палитра
    SystemPalette {
          id: palette;
          colorGroup: SystemPalette.Active
       }

    Rectangle{
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: btnAdd.top
        anchors.bottomMargin: 8
        border.color: "lightgray"
    ScrollView {
        anchors.fill: parent
        //flickableItem.interactive: true  // сохранять свойство "быть выделенным" при потере фокуса мыши

        ListView {
            id: countryList
            anchors.fill: parent
            model: countryModel // назначение модели, данные которой отображаются списком
            delegate: Delegate{}
            clip: true //
            activeFocusOnTab: true  // реагирование на перемещение между элементами ввода с помощью Tab
            focus: true  // элемент может получить фокус
        }
    }
   }

    ComboBox{
        id: cb
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.rightMargin: 8
        currentIndex: 0
        model: ListModel{
            id: elem
            ListElement {text: "Не выбрано"}
            ListElement {text: "Европа"}
            ListElement {text: "Азия"}
            ListElement {text: "Африка"}
            ListElement {text: "Австралия"}
            ListElement {text: "Северная Америка"}
            ListElement {text: "Южная Америка"}
        }

        onCurrentIndexChanged: label.text = countK(cb.currentIndex)
    }

    Label{
       id: label
       anchors.bottom: parent.bottom
       anchors.bottomMargin: 8
       anchors.leftMargin: 8
       anchors.left: cb.right
       text: "0"
       font.pointSize: 18
    }

    Button {
        id: btnAdd
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.rightMargin: 8
        anchors.right:btnEdit.left
        text: "Добавить"
        width: 100

        onClicked: windowAdd.show()
    }

    Button {
        id: btnEdit
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right: btnDel.left
        anchors.rightMargin: 8
        text: "Редактировать"
        width: 100

        onClicked: {
           Js.edit()
        }
    }

    Button {
        id: btnDel
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right:parent.right
        anchors.rightMargin: 8
        text: "Удалить"
        width: 100
        enabled: countryList.currentIndex >= 0
        onClicked: del(countryList.currentIndex)
    }

    DialogForAdd {
        id: windowAdd
    }
    DialogForEdit{
        id: windowEdit
    }
}
