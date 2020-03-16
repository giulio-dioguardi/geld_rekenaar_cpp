#ifndef MONEYCALCULATORMODEL_H
#define MONEYCALCULATORMODEL_H

#include <QAbstractListModel>

class MoneyCalculator;

class MoneyCalculatorModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(MoneyCalculator *list READ list WRITE setList)

public:
    enum MoneyValueRoles {
        CentValueRole = Qt::UserRole + 1,
        ValueRole,
        AmountRole
    };
    MoneyCalculatorModel(QObject *parent);
    virtual QHash <int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    MoneyCalculator *list() const;
    void setList(MoneyCalculator *list);
private:
    MoneyCalculator *m_List;
};

#endif // MONEYCALCULATORMODEL_H
