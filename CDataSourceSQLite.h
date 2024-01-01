#ifndef CDATASOURCESQLITE_H
#define CDATASOURCESQLITE_H

#include "IDataSource.h"


#include <QSqlDatabase>

class CDataSourceSQLite : public IDataSource
{
public:
    CDataSourceSQLite();
    ~CDataSourceSQLite();

    /**
     * @brief 查询所有信息
     * @param stuInfos
     * @return
     */
    virtual bool selectStuInfos(QList<CStuInfo> &stuInfoList) override;
    virtual bool addStuInfo(CStuInfo &stuInfo) override;
    virtual bool updateStuInfo(CStuInfo &stuInfo) override;
    virtual bool deleteStuInfo(int id) override;
private:
    QSqlDatabase m_db;  //数据库连接


};

#endif // CDATASOURCESQLITE_H
