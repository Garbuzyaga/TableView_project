#include "mainwindow.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    model = new Model;
    view = new QTableView;
    label = new QLabel;
    connect(model, &Model::checkCell, this, &MainWindow::checkValidity);
    view->setModel(model);
    view->setMinimumSize(420, 10);
    label->setText("Correct");
    lay = new QHBoxLayout(this);
    lay->addWidget(view);
    lay->addWidget(label);

}

MainWindow::~MainWindow()
{
    delete view;
    delete model;
    delete label;
    delete lay;
}



void MainWindow::checkValidity(bool validation)
{
    if(validation)
        label->setText("Correct");
    else
        label->setText("Incorrect");

}

bool MainWindow::isValid(const QString &string)
{
    for(const auto& ch : string){
        if(!std::isalpha(ch.toLatin1()))
            return false;
    }
    return true;
}

