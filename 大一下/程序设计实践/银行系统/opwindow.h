#ifndef OPWINDOW_H
#define OPWINDOW_H

#include <QMainWindow>
#include<QApplication>
#include <QWidget>
namespace Ui {
class OpWindow;
}

class OpWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OpWindow(QWidget *parent = nullptr);
    QString getMoney();
    QString getDesc();
    QString str;
    ~OpWindow();

private slots:
    void on_pushButton_clicked();

    void on_cb_activated(int index);
private:
    Ui::OpWindow *ui;
};

#endif // OPWINDOW_H
