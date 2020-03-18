import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import Calculator 1.0

Frame {
    height: parent.height
    width: parent.width
    ListView {
        height: parent.height
        width: parent.width

        clip: true

        model: MoneyCalculatorList {
            list: moneyCalculatorModel
        }

        delegate: RowLayout {
            width: parent.width
            Label { text: "€ " + model.value + "\t" }
            Label { text: "Amount: " }
            TextField {
                Layout.fillWidth: true
                text: model.amount
                onEditingFinished: model.amount = text
            }
        }
    }

}
