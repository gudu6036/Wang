// loginwindow.cpp
#include "loginwindow.h"
#include <QVBoxLayout>

LoginWindow::LoginWindow(QWidget *parent) : QWidget(parent)
{
    // 创建 UI 元素
    QLabel *usernameLabel = new QLabel("用户名:");
    QLabel *passwordLabel = new QLabel("密码:");
    usernameLineEdit = new QLineEdit();
    passwordLineEdit = new QLineEdit();
    loginButton = new QPushButton("登录");

    // 连接登录按钮的点击事件到槽函数
    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::on_loginButton_clicked);

    // 布局管理
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(usernameLabel);
    layout->addWidget(usernameLineEdit);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordLineEdit);
    layout->addWidget(loginButton);

    setLayout(layout);

    // 设置窗口标题
    setWindowTitle("登录窗口");
}

void LoginWindow::on_loginButton_clicked() {
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();

    // 在这里添加验证逻辑，决定用户角色

    QString role = determineUserRole(username, password);

    emit loginClicked(role);
}
