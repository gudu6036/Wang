#ifndef CADDSTUINFODIALOG_H
#define CADDSTUINFODIALOG_H

#include "CStuInfo.h"

#include <QDialog>

namespace Ui {
class CAddStuInfoDialog;
}

class CAddStuInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CAddStuInfoDialog(QWidget *parent = nullptr);
    ~CAddStuInfoDialog();

    /**
     * @brief 清空数据
     * @return
     */
    bool clearData();

    bool display(int id, QString name, QString sex, QString phone, int cet4, double gpa);

    void setIsUpateDlg(bool isUpateDlg);

signals:
    void sig_addStuInfo(CStuInfo &stuInfo);
    void sig_updateStuInfo(CStuInfo &stuInfo);

private slots:
    void on_btnConfirm_clicked();

    void on_btnCancel_clicked();

private:
    void initUI();

private:
    Ui::CAddStuInfoDialog *ui;
    bool m_isUpateDlg; //是否是修改窗口 true: 修改  false:添加窗口
};

#endif // CADDSTUINFODIALOG_H
