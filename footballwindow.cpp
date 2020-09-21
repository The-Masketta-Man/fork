#include "footballwindow.h"
#include "ui_footballwindow.h"

FootballWindow::FootballWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FootballWindow)
{
    ui->setupUi(this);
}

FootballWindow::~FootballWindow()
{
    delete ui;
}
