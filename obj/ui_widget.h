/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *btnAdd;
    QPushButton *btnDelete;
    QTableView *tbStudentInfo;
    QCheckBox *chkSelcetAll;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1016, 590);
        btnAdd = new QPushButton(Widget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(50, 50, 93, 28));
        btnDelete = new QPushButton(Widget);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setGeometry(QRect(170, 50, 93, 28));
        tbStudentInfo = new QTableView(Widget);
        tbStudentInfo->setObjectName(QString::fromUtf8("tbStudentInfo"));
        tbStudentInfo->setGeometry(QRect(10, 100, 991, 441));
        chkSelcetAll = new QCheckBox(Widget);
        chkSelcetAll->setObjectName(QString::fromUtf8("chkSelcetAll"));
        chkSelcetAll->setGeometry(QRect(50, 550, 91, 19));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\345\255\246\347\224\237\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237Demo", nullptr));
        btnAdd->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240", nullptr));
        btnDelete->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244", nullptr));
        chkSelcetAll->setText(QCoreApplication::translate("Widget", "\345\205\250\351\200\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
