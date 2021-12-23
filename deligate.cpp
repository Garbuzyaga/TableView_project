#include "deligate.h"
#include <QLabel>

Deligate::Deligate(QObject *parent) : QStyledItemDelegate(parent)
{

}

QWidget *Deligate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLabel *label = new QLabel(parent);
    label->setText("Correct");
    return label;
}
