#include "moneyvalue.h"

int MoneyValue::amount() const
{
    return m_amount;
}

void MoneyValue::setAmount(int amount)
{
    m_amount = amount;
}

int MoneyValue::centValue() const
{
    return m_centValue;
}

void MoneyValue::setCentValue(int centValue)
{
    m_centValue = centValue;
}

double MoneyValue::value() const
{
    return this->centValue() / 100.0;
}

MoneyValue::MoneyValue(const int amount, const int centValue) :
    m_amount(amount),
    m_centValue(centValue)
{}

/**
 * Return the total value as a double
 */
double MoneyValue::calculateTotalValue() const
{
    return this->calculateTotalCentValue() / 100.0;
}


/**
 * Return the total value as an integer in cents
 */
int MoneyValue::calculateTotalCentValue() const
{
    return m_amount * m_centValue;
}
