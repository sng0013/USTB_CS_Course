#ifndef CREATWINDOW_H
#define CREATWINDOW_H
#include<QString>
#include <QMainWindow>
#include<QApplication>
#include <QWidget>
namespace Ui {
class CreatWindow;
}

class CreatWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreatWindow(QWidget *parent = nullptr);
    QString getRate();
    QString getCredit();
    QString getFee();
    ~CreatWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CreatWindow *ui;
};

#endif // CREATWINDOW_H
