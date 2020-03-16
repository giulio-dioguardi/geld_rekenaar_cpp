import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import Calculator 1.0

Frame {
    ListView {
        implicitWidth: 250
        implicitHeight: 250
        clip: true

        model: MoneyCalculatorList {
            list: moneyCalculatorModel
        }

        delegate: RowLayout {
            width: parent.width
            Label { text: "€ " + model.value }
            Label { text: "Amount: " }
            TextField {
                Layout.fillWidth: true
                text: model.amount
                onEditingFinished: model.amount = text
            }
        }
    }

}
