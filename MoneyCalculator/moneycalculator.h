#ifndef CALCULATORSTUB_H
#define CALCULATORSTUB_H

#include <vector>
#include <moneyvalue.h>
#include <QAbstractListModel>
using namespace std;

class MoneyCalculator : public QAbstractListModel
{
    Q_OBJECT

private:
    vector<MoneyValue> m_moneyValues;

public:
    enum MoneyValueRoles {
        CentValueRole = Qt::UserRole + 1,
        AmountRole
    };
    QHash <int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    MoneyCalculator(QObject *parent = nullptr);
    int centValue();
    double value();
    void addMoneyValue(const MoneyValue value);
};

#endif // CALCULATORSTUB_H
