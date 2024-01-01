/********************************************************************************
** Form generated from reading UI file 'CAddStuInfoDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADDSTUINFODIALOG_H
#define UI_CADDSTUINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CAddStuInfoDialog
{
public:
    QPushButton *btnConfirm;
    QPushButton *btnCancel;
    QComboBox *cmbSex;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *edtPhone;
    QLabel *label_5;
    QSpinBox *spbCet4;
    QDoubleSpinBox *spbGpa;
    QLabel *label_6;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *edtId;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *edtName;

    void setupUi(QDialog *CAddStuInfoDialog)
    {
        if (CAddStuInfoDialog->objectName().isEmpty())
            CAddStuInfoDialog->setObjectName(QString::fromUtf8("CAddStuInfoDialog"));
        CAddStuInfoDialog->resize(441, 381);
        btnConfirm = new QPushButton(CAddStuInfoDialog);
        btnConfirm->setObjectName(QString::fromUtf8("btnConfirm"));
        btnConfirm->setGeometry(QRect(70, 320, 93, 28));
        btnCancel = new QPushButton(CAddStuInfoDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(220, 320, 93, 28));
        cmbSex = new QComboBox(CAddStuInfoDialog);
        cmbSex->setObjectName(QString::fromUtf8("cmbSex"));
        cmbSex->setGeometry(QRect(133, 121, 80, 21));
        label_3 = new QLabel(CAddStuInfoDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(81, 121, 45, 16));
        label_4 = new QLabel(CAddStuInfoDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(61, 161, 60, 16));
        edtPhone = new QLineEdit(CAddStuInfoDialog);
        edtPhone->setObjectName(QString::fromUtf8("edtPhone"));
        edtPhone->setGeometry(QRect(133, 161, 171, 21));
        label_5 = new QLabel(CAddStuInfoDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(81, 201, 40, 16));
        spbCet4 = new QSpinBox(CAddStuInfoDialog);
        spbCet4->setObjectName(QString::fromUtf8("spbCet4"));
        spbCet4->setGeometry(QRect(135, 201, 80, 21));
        spbCet4->setMinimumSize(QSize(80, 0));
        spbGpa = new QDoubleSpinBox(CAddStuInfoDialog);
        spbGpa->setObjectName(QString::fromUtf8("spbGpa"));
        spbGpa->setGeometry(QRect(133, 241, 80, 21));
        label_6 = new QLabel(CAddStuInfoDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(81, 241, 32, 16));
        widget = new QWidget(CAddStuInfoDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 30, 251, 23));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        edtId = new QLineEdit(widget);
        edtId->setObjectName(QString::fromUtf8("edtId"));

        horizontalLayout->addWidget(edtId);

        widget1 = new QWidget(CAddStuInfoDialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(80, 70, 251, 23));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        edtName = new QLineEdit(widget1);
        edtName->setObjectName(QString::fromUtf8("edtName"));

        horizontalLayout_2->addWidget(edtName);


        retranslateUi(CAddStuInfoDialog);

        QMetaObject::connectSlotsByName(CAddStuInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *CAddStuInfoDialog)
    {
        CAddStuInfoDialog->setWindowTitle(QCoreApplication::translate("CAddStuInfoDialog", "Dialog", nullptr));
        btnConfirm->setText(QCoreApplication::translate("CAddStuInfoDialog", "\347\241\256\345\256\232", nullptr));
        btnCancel->setText(QCoreApplication::translate("CAddStuInfoDialog", "\345\217\226\346\266\210", nullptr));
        label_3->setText(QCoreApplication::translate("CAddStuInfoDialog", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("CAddStuInfoDialog", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("CAddStuInfoDialog", "cet4:", nullptr));
        label_6->setText(QCoreApplication::translate("CAddStuInfoDialog", "gpa:", nullptr));
        label->setText(QCoreApplication::translate("CAddStuInfoDialog", "\345\255\246\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("CAddStuInfoDialog", "\345\247\223\345\220\215\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CAddStuInfoDialog: public Ui_CAddStuInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADDSTUINFODIALOG_H
