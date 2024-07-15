//这是第二个窗口的头文件
#ifndef USERWINDOW_H
#define USERWINDOW_H
#include<QApplication>
#include <QMainWindow>
#include <QWidget>
#include<creatwindow.h>
#include<Opwindow.h>
#include<Swindow.h>
using namespace std;

namespace Ui {
class UserWindow;
}

class UserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = nullptr);
    CreatWindow cw;
    OpWindow ow;
    SWindow sw;
    void backMain(char cmd, bool is_now_reading_a_file);
    ~UserWindow();

private slots:
    void on_cbCard_activated(int index);

    void on_btnCreate_clicked();

    void on_btnOperate_clicked();

    void on_btnSearch_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::UserWindow *ui;
};

#endif // USERWINDOW_H
