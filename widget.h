#ifndef WIDGET_H
#define WIDGET_H

#include "CAddStuInfoDialog.h"
#include "CDataSourceSQLite.h"

#include <QWidget>
#include <QStandardItemModel>
#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

const int CONST_COLUMN_SIZE = 7;     //表的列数
const int CONST_COL_ID = 0;           //id列
const int CONST_COL_NAME = 1;         //姓名列
const int CONST_COL_SEX = 2;          //性别列
const int CONST_COL_PHONE = 3;        //手机号列
const int CONST_COL_CET4 = 4;         //cet4列
const int CONST_COL_GPA = 5;          //gpa列
const int CONST_COL_OVERALLSCORE = 6; //综合成绩列

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    bool appendToModel(CStuInfo &stuInfo);
public slots:
    void getUserInfo(QString user);//获取用户信息

private slots:
    void on_btnAdd_clicked();


    /**
     * @brief 添加信息槽函数
     * @param stuInfo
     * @return
     */
    bool slot_addStuInfo(CStuInfo &stuInfo);

    /**
     * @brief 修改信息槽函数
     * @param stuInfo
     * @return
     */
    bool slot_updateStuInfo(CStuInfo &stuInfo);


    /**
     * @brief 复选框项发生改变
     * @param item
     * @return
     */
    bool slot_itemChanged(QStandardItem *item);

    /**
     * @brief 弹出背景式菜单槽函数
     * @param pos
     * @return
     */
    bool slot_popMenu(const QPoint &pos);

    /**
     * @brief 点击“全选”按钮
     * @param checked
     */
    void on_chkSelcetAll_clicked(bool checked);

    /**
     * @brief 菜单中修改项槽函数
     * @return
     */
    bool slot_actUpdate();

    bool slot_actDelete();

    void on_btnDelete_clicked();

private:
    void initUI();
private:
    Ui::Widget *ui;
    CDataSourceSQLite  *m_dataSource;  //数据源
    QStandardItemModel *m_standardModel; //model
    CAddStuInfoDialog *m_addStuInfo;  //添加学生信息窗口
    QMenu *m_menu;  //菜单
    QAction *m_actUpdate; //修改菜单项
    QAction *m_actDelete; //删除菜单项

};
#endif // WIDGET_H
