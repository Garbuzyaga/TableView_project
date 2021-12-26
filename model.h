#ifndef MODEL_H
#define MODEL_H


#include <QAbstractTableModel>
#include <QVector>

class Model : public QAbstractTableModel
{
    Q_OBJECT
public:
    Model(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
private:
    QVector<QVector<QString>> cellsData_;  //holds text entered into QTableView
    bool isCorrect();
signals:
    void checkCell(bool);
};
#endif // MODEL_H
