#include "moneycalculator.h"

MoneyCalculator::MoneyCalculator(QObject *parent)
{
    addMoneyValue(MoneyValue(0,1));
    addMoneyValue(MoneyValue(0,2));
    addMoneyValue(MoneyValue(0,5));
    addMoneyValue(MoneyValue(0,10));
    addMoneyValue(MoneyValue(0,20));
    addMoneyValue(MoneyValue(0,50));
    addMoneyValue(MoneyValue(0,100));
    addMoneyValue(MoneyValue(0,200));
    addMoneyValue(MoneyValue(0,500));
    addMoneyValue(MoneyValue(0,1000));
    addMoneyValue(MoneyValue(0,2000));
    addMoneyValue(MoneyValue(0,5000));
    addMoneyValue(MoneyValue(0,10000));
    addMoneyValue(MoneyValue(0,20000));
    addMoneyValue(MoneyValue(0,50000));
}

int MoneyCalculator::centValue()
{
    int result = 0;
    for (size_t i = 0; i < m_moneyValues.size(); i++)
    {
        result += m_moneyValues.at(i).calculateTotalCentValue();
    }
    return result;
}

QVector<MoneyValue> MoneyCalculator::items() const
{
    return m_moneyValues;
}

bool MoneyCalculator::setItemAt(int index, const MoneyValue &item)
{
    if (index < 0 || index >=m_moneyValues.size())
    {
        return false;
    }

    const MoneyValue &oldItem = m_moneyValues.at(index);
    if (item.amount() && oldItem.amount())
    {
        return false;
    }

    m_moneyValues[index] = item;
    return true;
}



double MoneyCalculator::value()
{
    return centValue() / 100.0;
}

void MoneyCalculator::addMoneyValue(const MoneyValue value)
{
    emit preItemAppended();
    this->m_moneyValues.push_back(value);
    emit postItemAppended();
}
