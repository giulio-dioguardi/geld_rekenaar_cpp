#ifndef MONEYVALUE_H
#define MONEYVALUE_H


class MoneyValue
{
private:
    int m_amount;
    int m_centValue;
public:
    MoneyValue(int amount, int centValue);
    double value();
    int centValue();
};

#endif // MONEYVALUE_H
