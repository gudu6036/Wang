#include "login.h"
#include "ui_login.h"

LogIn::LogIn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
    QIcon icon = QIcon(":/back/images/001.ico");
    this->setWindowIcon(icon);
    connect(ui->loginButton,&QPushButton::clicked,this,&LogIn::login);
}

LogIn::~LogIn()
{
    delete ui;
}
void LogIn::login()
{
    QString user = ui->userName->text();
    QString password = ui->passWord->text();
    //查询数据库
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("userinfo");
    model->setFilter(QString("userName = '%1' and password = '%2'")
                    .arg(user).arg(password));
    model->select();
    int row = model->rowCount();
    if(row > 0)
    {
        //QMessageBox::information(this,"登录提示","登录成功");
        //进入主程序
        Widget*w = new Widget;
        connect(this,&LogIn::sendUserInfo,w,& Widget::getUserInfo);
        emit sendUserInfo(user);
        w->show();
        this->close();
        ui->userName->clear();
        ui->passWord->clear();
    }else
    {
        QMessageBox::information(this,"登录提示","登录失败");
    }



    delete model;
//    if(user == "root" && password == "1")
//    {
//        //进入主程序
//        MainWindow *w = new MainWindow;
//        connect(this,&LogIn::sendUserInfo,w,&MainWindow::getUserInfo);
//        emit sendUserInfo(user);
//        w->show();
//        this->close();
//        ui->userName->clear();
//        ui->passWord->clear();
//    }
//    else {
//        QMessageBox::information(this,"出错提示","用户名或密码不匹配");
//    }
}

