#include <QApplication>
#include <QTableView>
#include "model.h"
#include "deligate.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTableView table_view;
    Model model;
    table_view.setModel(&model);
    Deligate deligate;
    table_view.setItemDelegate(&deligate);
    table_view.resize(420, 170);
    table_view.show();
    return a.exec();
}
