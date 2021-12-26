#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new Model;
    ui->tableView->setModel(model);
    ui->label->setText("Correct");
    connect(model, &Model::checkCell, this, &MainWindow::checkValidity);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::checkValidity(bool validation)
{
    if(validation)
        ui->label->setText("Correct");
    else
        ui->label->setText("Incorrect");

}

bool MainWindow::isValid(const QString &string)
{
    for(const auto& ch : string){
        if(!std::isalpha(ch.toLatin1()))
            return false;
    }
    return true;
}

