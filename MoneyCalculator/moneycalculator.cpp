#include "moneycalculator.h"

MoneyCalculator::MoneyCalculator()
{

}

int MoneyCalculator::centValue()
{
    int result = 0;
    for (size_t i = 0; i < m_moneyValues.size(); i++)
    {
        result += m_moneyValues.at(i).centValue();
    }
    return result;
}

double MoneyCalculator::value()
{
    return 0.0;
}

void MoneyCalculator::addMoneyValue(MoneyValue value)
{
    this->m_moneyValues.push_back(value);
}
