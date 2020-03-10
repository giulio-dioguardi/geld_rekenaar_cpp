#include "moneyvalue.h"

MoneyValue::MoneyValue(int amount, int centValue) :
    m_amount(amount),
    m_centValue(centValue)
{}

/**
 * Return the total value as a double
 */
double MoneyValue::value()
{
    return this->centValue() / 100.0;
}


/**
 * Return the total value as an integer in cents
 */
int MoneyValue::centValue()
{
    return m_amount * m_centValue;
}
