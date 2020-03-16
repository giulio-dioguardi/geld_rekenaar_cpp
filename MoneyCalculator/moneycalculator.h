#ifndef CALCULATORSTUB_H
#define CALCULATORSTUB_H

#include <QVector>
#include <QObject>
#include <moneyvalue.h>
using namespace std;

class MoneyCalculator : public QObject
{
    Q_OBJECT

private:
    QVector<MoneyValue> m_moneyValues;


public:
    QVector<MoneyValue> items() const;
    bool setItemAt(int index, const MoneyValue &item);

    explicit MoneyCalculator(QObject *parent = nullptr);
    int centValue();
    double value();

signals:
    void preItemAppended();
    void postItemAppended();

public slots:
    void addMoneyValue(const MoneyValue value);

};

#endif // CALCULATORSTUB_H
