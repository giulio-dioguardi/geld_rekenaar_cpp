import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    id: appWindow
    visible: true
    title: qsTr("Money Calculator")
    width: 400
    height: 700

    MoneyValueList {
        anchors.centerIn: parent
    }
}
