#include "moneycalculator.h"

MoneyCalculator::MoneyCalculator(QObject *parent)
{}

int MoneyCalculator::centValue()
{
    int result = 0;
    for (size_t i = 0; i < m_moneyValues.size(); i++)
    {
        result += m_moneyValues.at(i).centValue();
    }
    return result;
}

QHash<int, QByteArray> MoneyCalculator::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[CentValueRole] = "centValue";
    roles[AmountRole] = "amount";
    return roles;
}

int MoneyCalculator::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 3;
}

QVariant MoneyCalculator::data(const QModelIndex &index, int role) const
{
    size_t row = static_cast<size_t>(index.row());
    if (index.row() < 0 || row >= m_moneyValues.size())
    {
        return QVariant();
    }
    const MoneyValue &moneyValue = m_moneyValues[row];
    switch (role) {
    case CentValueRole:
        return moneyValue.centValue();
    case AmountRole:
        return moneyValue.amount();
    default:
        return QVariant();
    }

}

double MoneyCalculator::value()
{
    return centValue() / 100.0;
}

void MoneyCalculator::addMoneyValue(const MoneyValue value)
{
    this->m_moneyValues.push_back(value);
}
