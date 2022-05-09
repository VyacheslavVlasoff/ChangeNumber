import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.5  // это версия библиотеки, содержащей Contol (аналоги виджетов) для версии Qt 5.6
import QtQuick.Layouts 1.2

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
        Text {
            anchors.fill: parent
            text: "Could not connect to BD"
            color: "red"
            font.pointSize: 20
            font.bold: true
            visible: IsConnectionOpen == false
        }
        ListView {
            id: countryList
            anchors.fill: parent
            model: countryModel // назначение модели, данные которой отображаются списком
            delegate: DelegateForCountry{}
            clip: true //
            activeFocusOnTab: true  // реагирование на перемещение между элементами ввода с помощью Tab
            focus: true  // элемент может получить фокус
            opacity: {if (IsConnectionOpen == true) {100} else {0}}
        }
    }
   }

    Label{
       id: label
       anchors.bottom: parent.bottom
       anchors.bottomMargin: 8
       anchors.leftMargin: 8
       anchors.left: parent.right
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

        onClicked: {
            windowAddorEdit.currentIndex = -1
            windowAddorEdit.show()
        }
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
            var nameK = countryList.currentItem.personData.nameOfK
            var nameG = countryList.currentItem.personData.nameOfG
            var nameS = countryList.currentItem.personData.nameOfS
            var cheell = countryList.currentItem.personData.kindOfCh

            windowAddorEdit.execute(nameK, nameG, nameS, cheell, countryList.currentIndex)
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
        enabled: {
            if (countryList.currentItem==null || countryList.currentItem.personData == null)
            {false}
            else
            {countryList.currentItem.personData.Id_country >= 0} }
        onClicked: del(countryList.currentItem.personData.Id_country)
    }

    DialogForAddorEdit {
        id: windowAddorEdit
    }
}
