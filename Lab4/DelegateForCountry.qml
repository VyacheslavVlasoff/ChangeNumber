import QtQuick 2.6
import QtQuick.Controls 2.5  // это версия библиотеки, содержащей Contol (аналоги виджетов) для версии Qt 5.6
import QtQuick.Layouts 1.2

Rectangle {
    id: countryItem
    readonly property color evenBackgroundColor: "white"  // цвет для четных пунктов списка
    readonly property color oddBackgroundColor: "lightgray"   // цвет для нечетных пунктов списка
    readonly property color selectedBackgroundColor: "lightgreen"  // цвет выделенного элемента списка

    property bool isCurrent: countryItem.ListView.view.currentIndex === index   // назначено свойство isCurrent истинно для текущего (выделенного) элемента списка
    property bool selected: countryItemMouseArea.containsMouse || isCurrent // назначено свойство "быть выделенным",
    //которому присвоено значение "при наведении мыши,
    //или совпадении текущего индекса модели"

    property variant personData: model // свойство для доступа к данным конкретного студента

    width: parent ? parent.width : countryList.width
    height: 140

    // состояние текущего элемента (Rectangle)
    states: [
        State {
            when: selected
            // как реагировать, если состояние стало selected
            PropertyChanges { target: countryItem;  // для какого элемента должно назначаться свойство при этом состоянии (selected)
                color: isCurrent ? palette.highlight : selectedBackgroundColor  /* какое свойство целевого объекта (Rectangle)
                                                                                                  и какое значение присвоить*/
            }
        },
        State {
            when: !selected
            PropertyChanges { target: countryItem;  color: isCurrent ? palette.highlight : index % 2 == 0 ? evenBackgroundColor : oddBackgroundColor }
        }
    ]

    MouseArea {
        id: countryItemMouseArea
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            countryItem.ListView.view.currentIndex = index
            countryItem.forceActiveFocus() }
    }
    Item {
        id: itemOfCountry
        width: parent.width
        height: 140
        Column{
            id: t2
            anchors.left: parent.left
            anchors.leftMargin: 10
            width: 240
            anchors.verticalCenter: parent.verticalCenter
            Text {
                id: t1
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Континент:"
                color: "firebrick"
                font.pointSize: 12
            }
            Text {
                id: textNameK
                anchors.horizontalCenter: parent.horizontalCenter
                text: nameOfK
                color: "purple"
                font.pointSize: 18
                font.bold: true
            }
        }
        Column{
            anchors.left: t2.right
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            Text {

                text: "Государство"
                color: "firebrick"
                font.pointSize: 10
            }
            Text {
                id: textNameG
                text: nameOfG
                color: "purple"
                font.pointSize: 12
            }
            Text {

                text: "Столица государства"
                color: "firebrick"
                font.pointSize: 10
            }
            Text {
                id: textNameS
                color: "purple"
                text: nameOfS
                font.pointSize: 12
            }
            Text {

                text: "Рекомендуемый вид отдыха"
                color: "firebrick"
                font.pointSize: 10
            }
            Text {
                id: textCheell
                color: "purple"
                text: kindOfCh
                font.pointSize: 12
            }
        }

    }
}
