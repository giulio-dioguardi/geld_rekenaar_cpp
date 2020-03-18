#include "moneycalculatormodel.h"
#include <moneycalculator.h>

MoneyCalculatorModel::MoneyCalculatorModel(QObject *parent)
    : QAbstractListModel(parent),
      m_List(nullptr)
{

}
QHash<int, QByteArray> MoneyCalculatorModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[CentValueRole] = "centValue";
    roles[ValueRole] = "value";
    roles[CalculateTotalCentValueRole] = "calculateTotalCentValue";
    roles[CalculateTotalValueRole] = "calculsteTotalValue";
    roles[AmountRole] = "amount";
    return roles;
}

int MoneyCalculatorModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !m_List)
        return 0;

    return m_List->items().size();
}

QVariant MoneyCalculatorModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !m_List)
    {
        return QVariant();
    }

    const MoneyValue item = m_List->items().at(index.row());
    switch (role) {
    case CentValueRole:
        return QVariant(item.centValue());
    case CalculateTotalCentValueRole:
        return QVariant(item.calculateTotalCentValue());
    case ValueRole:
        return QVariant(item.value());
    case CalculateTotalValueRole:
        return QVariant(item.calculateTotalValue());
    case AmountRole:
        return QVariant(item.amount());
    default:
        return QVariant();
    }

}

bool MoneyCalculatorModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!m_List)
    {
        return false;
    }

    MoneyValue item = m_List->items().at(index.row());
    if ( role == AmountRole)
    {
        item.setAmount(value.toInt());
    }

    if (m_List->setItemAt(index.row(), item))
    {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags MoneyCalculatorModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return Qt::NoItemFlags;
    }
    return Qt::ItemIsEditable;
}

MoneyCalculator *MoneyCalculatorModel::list() const
{
    return m_List;
}

void MoneyCalculatorModel::setList(MoneyCalculator *list)
{
    beginResetModel();
    if (m_List) {
        m_List->disconnect(this);
    }
    m_List = list;

    if (m_List) {
        connect(m_List, &MoneyCalculator::preItemAppended, this, [=]() {
            const int index = m_List->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(m_List, &MoneyCalculator::postItemAppended, this, [=]() {
            endInsertRows();
        });
    }
    endResetModel();
}
