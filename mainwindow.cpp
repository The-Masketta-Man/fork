#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include <QVector>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    db = new Database("MYSQL", "188.120.237.17", 1500, "admin", "ultrapassword", "findfork");
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_football_clicked()
{
    f_window = new FootballWindow(this);
    f_window->show();
}

void MainWindow::on_button_tennis_clicked()
{

}
