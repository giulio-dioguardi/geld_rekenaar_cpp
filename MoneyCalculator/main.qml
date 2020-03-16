import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    id: appWindow
    visible: true
    title: qsTr("Hello World")
    width: 640
    height: 480

    MoneyValueList {
        anchors.centerIn: parent
    }
}
