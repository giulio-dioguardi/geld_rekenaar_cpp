#ifndef MONEYVALUE_H
#define MONEYVALUE_H


class MoneyValue
{
private:
    int m_amount;
    int m_centValue;
public:
    MoneyValue(const int amount, const int calculateTotalCentValue);
    double calculateTotalValue() const;
    int calculateTotalCentValue() const;
    int amount() const;
    void setAmount(int amount);
    int centValue() const;
    void setCentValue(int centValue);
    double value() const;
};

#endif // MONEYVALUE_H
