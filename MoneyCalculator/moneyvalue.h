#ifndef MONEYVALUE_H
#define MONEYVALUE_H


class MoneyValue
{
private:
    int m_amount;
    int m_centValue;
public:
    MoneyValue(const int amount, const int centValue);
    double value() const;
    int centValue() const;
    int amount() const;
    void setAmount(int amount);
};

#endif // MONEYVALUE_H
