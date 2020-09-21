#ifndef FOOTBALLWINDOW_H
#define FOOTBALLWINDOW_H

#include <QDialog>

namespace Ui {
class FootballWindow;
}

class FootballWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FootballWindow(QWidget *parent = nullptr);
    ~FootballWindow();

private:
    Ui::FootballWindow *ui;
};

#endif // FOOTBALLWINDOW_H
