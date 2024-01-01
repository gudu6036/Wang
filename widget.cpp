#include "widget.h"
#include "ui_widget.h"
#include "CAddStuInfoDialog.h"

#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_dataSource(NULL)
    , m_standardModel(NULL)
    , m_addStuInfo(NULL)
    , m_menu(NULL)
    , m_actUpdate(NULL)
    , m_actDelete(NULL)
{
    ui->setupUi(this);
    qRegisterMetaType<CStuInfo>("CStuInfo");
    qRegisterMetaType<CStuInfo>("CStuInfo&");


    //实例化数据源
    m_dataSource = new CDataSourceSQLite();
    //    m_dataSource = new CDataSourceJSON();

    m_addStuInfo = new CAddStuInfoDialog(this);


    //关联槽函数
    connect(m_addStuInfo,&CAddStuInfoDialog::sig_addStuInfo,this,&Widget::slot_addStuInfo);
    connect(m_addStuInfo,&CAddStuInfoDialog::sig_updateStuInfo,this,&Widget::slot_updateStuInfo);

    //初始化界面
    initUI();
}

Widget::~Widget()
{
    delete m_dataSource;
    delete ui;
}

bool Widget::appendToModel(CStuInfo &stuInfo)
{
    QStandardItem *itemId = new QStandardItem(QString("%1").arg(stuInfo.id(),4,10,QLatin1Char('0')));
    itemId->setCheckable(true); //添加复选框
    itemId->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QStandardItem *itemName = new QStandardItem(stuInfo.name());
    itemName->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QStandardItem *itemSex = new QStandardItem(stuInfo.sex());
    itemSex->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QStandardItem *itemPhone = new QStandardItem(stuInfo.phone());
    itemPhone->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QStandardItem *itemCet4 = new QStandardItem(QString::number(stuInfo.cet4()));
    itemCet4->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QStandardItem *itemGpa = new QStandardItem(QString::number(stuInfo.gpa()));
    itemGpa->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QStandardItem *itemOverallScore = new QStandardItem(QString::number(stuInfo.overallScore()));
    itemOverallScore->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QList<QStandardItem*> rowItem;
    rowItem.append(itemId);
    rowItem.append(itemName);
    rowItem.append(itemSex);
    rowItem.append(itemPhone);
    rowItem.append(itemCet4);
    rowItem.append(itemGpa);
    rowItem.append(itemOverallScore);

    m_standardModel->appendRow(rowItem);
    return true;
}

void Widget::initUI()
{
    //实例化model
    m_standardModel = new QStandardItemModel(this);
    //实例化菜单以及菜单项
    m_menu = new QMenu(this);
    m_actUpdate = new QAction("修改",m_menu);
    m_actDelete = new QAction("删除",m_menu);
    m_menu->addAction(m_actUpdate);
    m_menu->addAction(m_actDelete);

    //设置tableView 菜单策略 customContextMenuRequested(const QPoint &pos)
    ui->tbStudentInfo->setContextMenuPolicy(Qt::CustomContextMenu);
    //关联槽函数
    connect(m_standardModel,&QStandardItemModel::itemChanged,this,&Widget::slot_itemChanged); //勾选复选框槽函数
    connect(ui->tbStudentInfo,&QTableView::customContextMenuRequested,this,&Widget::slot_popMenu); //弹出菜单槽函数
    connect(m_actUpdate,&QAction::triggered,this,&Widget::slot_actUpdate); //修改项槽函数
    connect(m_actDelete,&QAction::triggered,this,&Widget::slot_actDelete); //删除项槽函数



    //查询数据
    QList<CStuInfo> stuInfoList;
    bool res = m_dataSource->selectStuInfos(stuInfoList);
    if(!res)
    {
        QMessageBox::information(this,"提示","查询学生信息失败");
        return;
    }
    qDebug() << stuInfoList.size();
    for(int i=0;i<stuInfoList.size();++i)
    {
        appendToModel(stuInfoList[i]);
    }
    //添加表头
    QStringList headerList;
    headerList<<"学号"<<"姓名"<<"性别"<<"手机号"<<"cet4"<<"gpa"<<"综合成绩";
    m_standardModel->setHorizontalHeaderLabels(headerList);

    ui->tbStudentInfo->verticalHeader()->setVisible(false); //隐藏垂直表头
    ui->tbStudentInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tbStudentInfo->setModel(m_standardModel);
    for (int col=0;col<CONST_COLUMN_SIZE;++col) {
        ui->tbStudentInfo->setColumnWidth(col,(width()-28)/7);
    }

}


void Widget::on_btnAdd_clicked()
{
    m_addStuInfo->setIsUpateDlg(false);
    m_addStuInfo->show();
}

bool Widget::slot_addStuInfo(CStuInfo &stuInfo)
{
    bool res = m_dataSource->addStuInfo(stuInfo);
    if(!res)
    {
        QMessageBox::information(this,"提示","插入失败！！！");
        return false;
    }
    appendToModel(stuInfo);
    return true;
}

bool Widget::slot_updateStuInfo(CStuInfo &stuInfo)
{
    int res = m_dataSource->updateStuInfo(stuInfo);
    if(!res)
    {
        QMessageBox::information(this,"提示","修改失败！！！");
        return false;
    }
    int row = ui->tbStudentInfo->currentIndex().row();
    m_standardModel->setData(m_standardModel->item(row,CONST_COL_NAME)->index(),stuInfo.name());
    m_standardModel->setData(m_standardModel->item(row,CONST_COL_SEX)->index(),stuInfo.sex());
    m_standardModel->setData(m_standardModel->item(row,CONST_COL_PHONE)->index(),stuInfo.phone());
    m_standardModel->setData(m_standardModel->item(row,CONST_COL_CET4)->index(),stuInfo.cet4());
    m_standardModel->setData(m_standardModel->item(row,CONST_COL_GPA)->index(),stuInfo.gpa());
    m_standardModel->setData(m_standardModel->item(row,CONST_COL_OVERALLSCORE)->index(),stuInfo.overallScore());

    QMessageBox::information(this,"提示","修改成功！！！");
    return true;
}

bool Widget::slot_itemChanged(QStandardItem *item)
{
    if(m_standardModel->indexFromItem(item).column()>0) return false;
    for(int row = 0;row<m_standardModel->rowCount();++row)
    {
        if(m_standardModel->item(row)->checkState()!=Qt::Checked)
        {
            ui->chkSelcetAll->setChecked(false);
            return false;
        }

    }
    ui->chkSelcetAll->setChecked(true);
    return true;
}

bool Widget::slot_popMenu(const QPoint &pos)
{
    if(m_standardModel->itemFromIndex(ui->tbStudentInfo->indexAt(pos))!=NULL)
        m_menu->exec(QCursor::pos());
    return true;
}

void Widget::on_chkSelcetAll_clicked(bool checked)
{
    for(int row = 0;row<m_standardModel->rowCount();++row)
    {
        if(checked)
            m_standardModel->item(row)->setCheckState(Qt::Checked);
        else
            m_standardModel->item(row)->setCheckState(Qt::Unchecked);
    }
}

bool Widget::slot_actUpdate()
{
    m_addStuInfo->setIsUpateDlg(true); //设置修改标识
    int row = ui->tbStudentInfo->currentIndex().row();
    int id = m_standardModel->item(row,CONST_COL_ID)->text().toInt();
    QString name = m_standardModel->item(row,CONST_COL_NAME)->text();
    QString sex = m_standardModel->item(row,CONST_COL_SEX)->text();
    QString phone = m_standardModel->item(row,CONST_COL_PHONE)->text();
    int cet4 = m_standardModel->item(row,CONST_COL_CET4)->text().toInt();
    int gpa = m_standardModel->item(row,CONST_COL_GPA)->text().toDouble();
    m_addStuInfo->display(id,name,sex,phone,cet4,gpa);
    m_addStuInfo->show();
    return true;
}

bool Widget::slot_actDelete()
{
    int row =  ui->tbStudentInfo->currentIndex().row();
    int id = m_standardModel->item(row)->text().toInt();
    m_dataSource->deleteStuInfo(id);
    m_standardModel->removeRow(row);
    return true;
}

void Widget::on_btnDelete_clicked()
{
    QMap<int,QStandardItem*> delRowsMap;  //待删除的行
    for(int row = 0;row<m_standardModel->rowCount();++row)
    {
        QStandardItem *item = m_standardModel->item(row);
        if(item->checkState() == Qt::Checked)
        {
            delRowsMap.insert(row,item);
        }
    }

    if(delRowsMap.size()<1)
        return;

    //弹出删除提示
    int res = QMessageBox::information(this,"提示","是否真的要删除",QMessageBox::Yes|QMessageBox::No);
    if(res == QMessageBox::No) return;

    QList<int> keyList = delRowsMap.keys();
    //1.删除数据库中的数据
    for(int key=keyList.size()-1;key>=0;--key)
    {
        if(m_dataSource->deleteStuInfo(delRowsMap.value(keyList[key])->text().toInt()))
        {
            //2.删除窗口中的数据
            m_standardModel->removeRow(keyList[key]);
        }
    }


}
void Widget::getUserInfo(QString user)
{

}
