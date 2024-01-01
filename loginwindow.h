// loginwindow.h
#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);

signals:
    void loginClicked(const QString &role);

private slots:
    void on_loginButton_clicked();

private:
    QPushButton *loginButton;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QString determineUserRole(const QString &username, const QString &password);

    // 如果有其他 UI 元素，可以在这里添加相应的指针声明
};

#endif // LOGINWINDOW_H
