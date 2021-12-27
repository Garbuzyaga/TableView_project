#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTableView>
#include <QLabel>
#include <QHBoxLayout>
#include "model.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void checkValidity(bool validation);

private:
    bool isValid(const QString& string);
    Model *model;
    QTableView *view;
    QLabel *label;
    QHBoxLayout *lay;
};
#endif // MAINWINDOW_H
