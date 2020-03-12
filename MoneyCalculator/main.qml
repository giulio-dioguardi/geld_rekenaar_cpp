import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    title: qsTr("Hello World")
    width: 640
    height: 480

    Rectangle {
        width: parent.width
        height: parent.height

        ListView {
            anchors.fill: parent
            model: myModel
            delegate: Text { text: "Denominator: " + centValue + ", Amount: " + amount }
            highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
            focus: true
        }
    }
}
