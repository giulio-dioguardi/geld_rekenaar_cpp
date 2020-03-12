#ifndef MONEYVALUE_H
#define MONEYVALUE_H


class MoneyValue
{
private:
    int m_amount;
    int m_centValue;
public:
    MoneyValue(int amount, int centValue);
    double value() const;
    int centValue() const;
    int amount() const;
};

#endif // MONEYVALUE_H
