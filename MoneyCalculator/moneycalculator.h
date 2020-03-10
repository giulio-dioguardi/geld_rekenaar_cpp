#ifndef CALCULATORSTUB_H
#define CALCULATORSTUB_H

#include <vector>
#include <moneyvalue.h>
using namespace std;

class MoneyCalculator
{
private:
    vector<MoneyValue> m_moneyValues;

public:
    MoneyCalculator();
    int centValue();
    double value();
    void addMoneyValue(MoneyValue value);
};

#endif // CALCULATORSTUB_H
