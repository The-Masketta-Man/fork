#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "database.h"
#include "footballwindow.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        void on_button_football_clicked();
        void on_button_tennis_clicked();

private:
        Ui::MainWindow *ui;
        Database *db;
        FootballWindow *f_window;
};
#endif // MAINWINDOW_H
