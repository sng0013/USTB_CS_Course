//这是第二个窗口的源文件
#include "userwindow.h"
#include "ui_userwindow.h"
#include"account.h"
#include<fstream>
#include<QString>
#include<QMessageBox>
#include <QMainWindow>
#include<QApplication>
#include <QWidget>
#include<string>
#include<bank.h>
#include<date.h>
#include<account.h>
#include<SavingsAccount.h>
#include<CreditAccount.h>
#include<iostream>

using namespace std;

Date date(2008, 11, 1); // 起始日期
fstream commands;
vector<Account *> accounts; // 创建账户数组，元素个数为0
vector<Account *>accounts_1;// 存储已有的账户
QString aa[5]; // 0.s or c 1.账户名 2.信用 3.利率 4.年费
QString ddww[3]; // 0.账户名编号 1.金额 2.原因
int day_change,month_change,year_change;
bool is_have_date=0;//是否输入日期
Date q1,q2;
char cmd;

UserWindow::UserWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UserWindow)
{
    ui->setupUi(this);

    ui->setupUi(this);
    QString theHello = "欢迎用户 "+ QString::fromStdString(Bank::Log_in_User) +" ，请进行接下来的操作:";
    ui->label->setText(theHello);


    commands.open("commands.txt", ios_base::in | ios_base::out);
    if(!commands.is_open()){
        // 文件打开失败
        commands.open("commands.txt",ios_base::out | ios_base::app);
        // cout << "File cannot open or there is no such a command.txt. It will create a new file." << endl;
        //is_now_reading_a_file = false;
    }
    else {
        do{
            commands >> cmd;
            UserWindow::backMain(cmd, true);
        }while(commands.peek()!=EOF);//while(!commands.eof());
        commands.clear();
    }
    //InsideWindow::jisrBro2();
}
UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::backMain(char cmd, bool is_now_reading_a_file){
    // if(!is_now_reading_a_file){
    //     date.show();
    //     cout << "\tTotal: " << Account::getTotal() << "\tcommand> ";
    // }
    char type;
    unsigned int index; int day,year,month;
    double amount, credit, rate, fee;
    string user, id, desc;
    Account* account;
    Account* account_1;
    // SavingsAccount* savingsaccount_1;
    // CreditAccount* creditaccount_1;
    Date date1{}, date2{};
    switch (cmd) {
    case 'a':{//增加账户
        if(is_now_reading_a_file){
            commands >> type >> user >> id;
        }
        else {
            try{
                type = aa[0].toStdString().c_str()[0];
                user = Bank::Log_in_User;
                id = aa[1].toStdString();

                if(type == 's' || type == 'c'){
                    commands << endl << cmd << " ";
                    commands << type << " " << user << " " << id << " ";
                }
                else throw QMessageBox::warning(this,tr("警告信息"),tr("不是可添加的账户类型"));
            }
            catch (runtime_error& err) {
                cerr << err.what() << endl;
            }
        }
        if (type == 's') {
            if(is_now_reading_a_file) {
                commands >> rate;
                account_1=new SavingsAccount(date,user,id,rate);
                accounts_1.push_back(account_1);//将文件读取保存到容器中
            }
            else {
                //cin >> rate;
                rate = aa[3].toDouble();
                commands << rate;
            }
            account = new SavingsAccount(date, user,id, rate);
        }
        else {
            if(is_now_reading_a_file) {
                commands >> credit >> rate >> fee;
                account_1=new CreditAccount(date,user,id,credit,rate,fee);
                accounts_1.push_back(account_1);//将文件读取保存到容器中
            }
            else {
                credit = aa[2].toDouble();
                rate = aa[3].toDouble();
                fee = aa[4].toDouble();
                commands << credit << " " << rate << " " << fee;
            }
            account = new CreditAccount(date, user,id, credit, rate, fee);
        }
        if(user == Bank::Log_in_User) //进行用户过滤
            QMessageBox::warning(this,tr("警告信息"),tr("账号已创建!"));
        accounts.push_back(account);
        break;
    }

    case 'd':{//存入现金
        try{
            if(is_now_reading_a_file){
                commands >> index >> amount;
                getline(commands, desc);
                accounts_1[index]->deposit(date, amount, desc);
            }
            else{
                index = ddww[0].toUInt();
                amount = ddww[1].toDouble();
                desc = ddww[2].toStdString();
                if(index >= accounts.size()){
                    throw QMessageBox::warning(this,tr("警告信息"),tr("该账户不存在"));
                }
                //写入文件
                commands << endl << cmd << " ";
                commands << index << " " << amount << " " << desc;
                //InsideWindow::jisrBro2();
            }
            accounts[index]->deposit(date, amount, desc);
            if(accounts[index]->getUser() == Bank::Log_in_User) {// 进行用户过滤
                //this->ui->QMessageBox::setInformativeText(to_string(date.getYear())+"年"+to_string(date.getMonth())+"月"+to_string(date.getDay())+"日"+accounts[index]->getId()+"存了"+to_string(amount)+"元,原因："+desc));
            }
        }
        catch (runtime_error& err) {
            cerr << err.what() << endl;
        }
        break;
    }

    case 'w':{//取出现金
        try{
            if(is_now_reading_a_file){
                commands >> index >> amount;
                getline(commands, desc);
                accounts_1[index]->withdraw(date, amount, desc);
            }
            else{
                index = ddww[0].toUInt();
                amount = ddww[1].toDouble();
                desc = ddww[2].toStdString();
                if(index < 0 || index >= accounts.size()){
                    throw QMessageBox::warning(this,tr("警告信息"),tr("该账户不存在"));
                }
                //InsideWindow::jisrBro2();
            }
            accounts[index]->withdraw(date, amount, desc);
            if(accounts[index]->getUser() == Bank::Log_in_User){ // 进行用户过滤
                //iw->ui->textBrowser1->append(QString::fromStdString(to_string(date.getYear())+"年"+to_string(date.getMonth())+"月"+to_string(date.getDay())+"日"+accounts[index]->getId()+"取了"+to_string(amount)+"元,原因："+desc));
            }
                // 如果没有错误再进行写入文件
            if(!is_now_reading_a_file) {
                commands << endl << cmd << " ";
                commands << index << " " << amount << " " << desc;
            }
        }
        catch (AccountException& err){
            cerr << err.what() << endl;
            QMessageBox::warning(this,tr("警告信息"),tr("超支！"));
            return;
        }
        catch (runtime_error& err) {
            cerr << err.what() << endl;
        }
        break;
    }

    // case 's':{//查询各账户信息
    //     static unsigned int num=1;
    //     for (size_t i = 0; i < accounts.size(); i++) {
    //         //                        cout << "[" << i << "] ";
    //         //                        accounts[i]->show();
    //         //                        cout << endl;
    //        // if(accounts[i]->getUser() == Bank::Log_in_User) // 进行用户过滤
    //          //   iw->ui->textBrowser1->append(QString::fromStdString("[" + to_string(num++) + "] " + accounts[i]->show()));
    //     }
    //     break;
    // }

    case 'c':{//改变日期
        if(is_now_reading_a_file) {
            commands >>year>>month>> day;
            date = Date(year, month, day);
        }
        else {
            //cin >> day;
            day = day_change;
            month=month_change;
            year=year_change;
        }
        if (day < date.getDay()||year<date.getYear()||month<date.getMonth()){
            cerr << "You cannot specify a previous day" << endl;
            QMessageBox::warning(this,tr("警告信息"),tr("时光不能倒流。"));
            return;
        }
        else if (day > date.getMaxDay()||((month>12)||(month<1))){
            cerr << "Invalid day" << endl;
            QMessageBox::warning(this,tr("警告信息"),tr("日期不合理"));
            return;
        }
        else {
            date = Date(year, month, day);
            if(!is_now_reading_a_file) {
                commands << endl << cmd << " ";
                commands << year<<month<<day;
            }
        }
        break;
    }

    // case 'n': {	//进入下个月
    //     if (date.getMonth() == 12)
    //         date = Date(date.getYear() + 1, 1, 1);
    //     else
    //         date = Date(date.getYear(), date.getMonth() + 1, 1);
    //     for (vector<Account*>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)
    //         (*iter)->settle(date);
    //     break;

    // case 'q':{//查询一段时间内的账目
    //     try {
    //         date1 = q1;//q1还未实现
    //         date2 = q2;//q2还未实现
    //         //iw->ui->textBrowser1->append(QString::fromStdString(Account::query(date1, date2, MainWindow::Log_on_User)));
    //     }
    //     catch (DateException& err){
    //         cerr << err.what() << endl;
    //         if(cin.fail()) cin.clear();
    //     }
    //     break;
    // }

    default:
        cerr << "Not a right command." <<endl;
        break;
    }
}

void UserWindow::on_cbCard_activated(int index)
{
    // 获取当前索引的项目文本
    QString cardText = qobject_cast<QComboBox*>(sender())->itemText(index);
    if(cardText=="Savings Card"){aa[0]='s';}
    else{aa[0]='c';}

}

//初始化日期
void UserWindow::on_pushButton_2_clicked()
{
    is_have_date=1;
    year_change=ui->lineEdit->text().toInt();
    month_change=ui->lineEdit_2->text().toInt();
    day_change=ui->lineEdit_3->text().toInt();
    cmd='c';
    UserWindow::backMain(cmd, false);
}

void UserWindow::on_btnCreate_clicked()//创建账户
{
    QMessageBox::warning(this,tr("提示"),tr("你已经按下这个按钮"));
    bool is_have_this_account=0;
    string text_std=ui->leAccount->text().toStdString();//获取账户
    //是否已有这个帐户
    for(auto &iter : accounts_1){
        if(iter->getId() == text_std){//如果出现重名用户
            is_have_this_account=1;
            ui->leAccount->clear();
            QMessageBox::warning(this,tr("警告信息"),tr("系统中已有该账户"));
            return;
        }
    }
    if(is_have_date==0)
    {
        QMessageBox::warning(this,tr("警告信息"),tr("您还未输入今日日期"));
    }
    //如果成功创建
    if((!is_have_this_account)&&is_have_date){
        QMessageBox::warning(this,tr("完成操作信息"),tr("成功创建账户"));
        cmd='a';
        aa[1]=ui->leAccount->text();
        //跳转到下一个界面
        this->hide();//隐藏该界面
        cw.show();//显示
        if(aa[0]=='s')
        {
            //aa[2]=cw.getCredit();
            aa[3]=cw.getRate();
            //aa[4]=cw.getFee();
        }
        else
        {
            aa[2]=cw.getCredit();
            aa[3]=cw.getRate();
            aa[4]=cw.getFee();
        }
        UserWindow::backMain(cmd, false);
    }
    this->show();//显示
    ui->leAccount->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}


void UserWindow::on_btnOperate_clicked()
{
    bool is_have_this_account=0;
    string text_std=ui->leAccount->text().toStdString();//获取账户
    //是否已有这个帐户
    for(auto &iter : accounts_1){
        if(iter->getId() == text_std){//如果出现重名用户
            is_have_this_account=1;
        }
    }
    for(auto &iter:accounts)
        {
            if(iter->getId() == text_std){//如果出现重名用户
                is_have_this_account=1;
            }
        }
    if(is_have_date==0)
    {
        QMessageBox::warning(this,tr("警告信息"),tr("您还未输入今日日期"));
    }
    if(!is_have_this_account)
    {
    ui->leAccount->clear();
    QMessageBox::warning(this,tr("警告信息"),tr("系统中没有该账户"));
    return;
    }

    //如果成功创建
    if((is_have_this_account)&&is_have_date){
        QMessageBox::warning(this,tr("完成操作信息"),tr("成功登录账户"));
        aa[1]=ui->leAccount->text();

        //跳转到下一个界面
        this->hide();//隐藏该界面
        ow.show();//显示
        if(ow.str=="存钱")
        {
            cmd='d';
            ddww[0]=aa[1];
            ddww[1]=ow.getMoney();
            ddww[2]=ow.getDesc();
        }
        else
        {
            cmd='w';
            ddww[0]=aa[1];
            ddww[1]=ow.getMoney();
            ddww[2]=ow.getDesc();
        }
        UserWindow::backMain(cmd, false);
    }
    this->show();//显示
    ui->leAccount->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}


void UserWindow::on_btnSearch_clicked()
{
    bool is_have_this_account=0;
    string text_std=ui->leAccount->text().toStdString();//获取账户
    //是否已有这个帐户
    for(auto &iter : accounts_1){
        if(iter->getId() == text_std){//如果出现重名用户
            is_have_this_account=1;
        }
    }
    for(auto &iter:accounts)
    {
        if(iter->getId() == text_std){//如果出现重名用户
            is_have_this_account=1;
        }
    }
    if(is_have_date==0)
    {
        QMessageBox::warning(this,tr("警告信息"),tr("您还未输入今日日期"));
    }
    if(!is_have_this_account){
        ui->leAccount->clear();
        QMessageBox::warning(this,tr("警告信息"),tr("系统中没有该账户"));
        return;
    }
    //如果成功创建
    if((is_have_this_account)&&is_have_date){
        QMessageBox::warning(this,tr("完成操作信息"),tr("成功查询账户"));
        aa[1]=ui->leAccount->text();

        //跳转到下一个界面
        this->hide();//隐藏该界面
        sw.show();//显示
        // q1=sw.getDate_1();
        // q2=sw.getDate_2();
        // cmd=sw.on_btns_clicked();

        //UserWindow::backMain(cmd, false);
    }
    ui->leAccount->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}


