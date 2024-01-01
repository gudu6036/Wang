#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlTableModel>
#include "Widget.h"

namespace Ui {
class LogIn;
}

class LogIn : public QMainWindow
{
    Q_OBJECT
public:

public:
    explicit LogIn(QWidget *parent = nullptr);
    ~LogIn();
signals:
    void sendUserInfo(QString user);//发送用户信息  信号函数
private slots:
    void login();

private:
    Ui::LogIn *ui;


};

#endif // LOGIN_H
