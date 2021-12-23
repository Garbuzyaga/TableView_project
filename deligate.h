#ifndef DELIGATE_H
#define DELIGATE_H

#include <QStyledItemDelegate>

class Deligate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit Deligate(QObject *parent = 0);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // DELIGATE_H
