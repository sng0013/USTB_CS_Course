#ifndef SWINDOW_H
#define SWINDOW_H
#include<QString>
#include <QMainWindow>
#include<QApplication>
#include <QWidget>
#include"date.h"
using namespace std;
namespace Ui {
class SWindow;
}

class SWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SWindow(QWidget *parent = nullptr);
    Date getDate_1();
    Date getDate_2();
    ~SWindow();

private slots:
    char on_btnS_clicked();

private:
    Ui::SWindow *ui;
};

#endif // SWINDOW_H
