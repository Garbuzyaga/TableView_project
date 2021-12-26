#include "model.h"

Model::Model(QObject *parent)
    : QAbstractTableModel(parent)
{
    cellsData_.resize(4);
    for(auto &column : cellsData_)
    {
        column.resize(4);
        for(auto &row : column)
            row = "Cell";
    }
}

int Model::rowCount(const QModelIndex & /*parent*/) const
{
   return cellsData_.size();
}

int Model::columnCount(const QModelIndex & /*parent*/) const
{
    return cellsData_[0].size();
}

QVariant Model::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    if (role == Qt::DisplayRole)
       return cellsData_.at(index.column()).at(index.row());
    return QVariant();
}

bool Model::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole) {
           if (!checkIndex(index))
               return false;
           cellsData_[index.column()][index.row()] = value.toString();
           emit checkCell(isCorrect());
           return true;
    }
    return false;
}

Qt::ItemFlags Model::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable | QAbstractTableModel::flags(index);
}

bool Model::isCorrect()
{
    for(const auto &column : cellsData_)
    {
        for(const auto &row : column){
            for(auto ch : row)
            if(!std::isalpha(ch.toLatin1()))
                return false;
        }
    }
    return true;
}

