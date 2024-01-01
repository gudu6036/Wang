#include "CAddStuInfoDialog.h"
#include "CStuInfo.h"
#include "ui_CAddStuInfoDialog.h"

#include <QMessageBox>

CAddStuInfoDialog::CAddStuInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CAddStuInfoDialog),
    m_isUpateDlg(false)
{
    ui->setupUi(this);
    initUI();
}

CAddStuInfoDialog::~CAddStuInfoDialog()
{
    delete ui;
}

bool CAddStuInfoDialog::clearData()
{
    ui->edtId->clear();
    ui->edtName->clear();
    ui->edtPhone->clear();
    ui->spbCet4->setValue(0);
    ui->spbGpa->setValue(0.0);

    return true;
}

bool CAddStuInfoDialog::display(int id, QString name, QString sex, QString phone, int cet4, double gpa)
{
    ui->edtId->setText(QString("%1").arg(id,4,10,QLatin1Char('0')));
    ui->edtId->setReadOnly(true);
    ui->edtName->setText(name);
    ui->cmbSex->setCurrentText(sex);
    ui->edtPhone->setText(phone);
    ui->spbCet4->setValue(cet4);
    ui->spbGpa->setValue(gpa);
    return true;
}

void CAddStuInfoDialog::on_btnConfirm_clicked()
{
    //第一步：输入信息的合法性
    int idLength = ui->edtId->text().length();
    if(idLength != 4)
    {
        QMessageBox::information(this,"提示","学号输入不合规！！！");
        return;
    }
    int phoneLength = ui->edtPhone->text().length();
    if(phoneLength!=11)
    {
        QMessageBox::information(this,"提示","手机号输入不合规！！！");
        return;
    }

    int id = ui->edtId->text().toInt();
    QString name = ui->edtName->text();
    QString sex = ui->cmbSex->currentText();
    QString phone = ui->edtPhone->text();
    int cet4 = ui->spbCet4->value();
    double gpa = ui->spbGpa->value();
    CStuInfo stuInfo;
    stuInfo.setData(id,name,sex,phone,cet4,gpa);

    if(m_isUpateDlg)
    {
        emit sig_updateStuInfo(stuInfo);
    }
    else
    {
        emit sig_addStuInfo(stuInfo);
        //清空数据
        clearData();
    }
}

void CAddStuInfoDialog::initUI()
{
    //设置窗口标题
    this->setWindowTitle("添加/修改学生信息");

    //学号
    ui->edtId->setPlaceholderText("请输入四位数字的学号");
    QRegExp regId("^[0-9]{4}$");
    ui->edtId->setValidator(new QRegExpValidator(regId,this));
    //名称 允许中文和字母
    QRegExp regName("^[a-zA-Z\u4e00-\u9fa5]{1,}$");
    ui->edtName->setValidator(new QRegExpValidator(regName,this));
    //性别
    ui->cmbSex->addItem("男");
    ui->cmbSex->addItem("女");

    //手机号
    ui->edtPhone->setPlaceholderText("请输入11位数字的手机号：");
    QRegExp regPhone("^[1-9][0-9]{10}$");
    ui->edtPhone->setValidator(new QRegExpValidator(regPhone,this));

    //cet4
    ui->spbCet4->setRange(0,750);

    //gpa
    ui->spbGpa->setRange(0.0,4.0);
}

void CAddStuInfoDialog::setIsUpateDlg(bool isUpateDlg)
{
    m_isUpateDlg = isUpateDlg;
}

void CAddStuInfoDialog::on_btnCancel_clicked()
{
    this->close();
}
