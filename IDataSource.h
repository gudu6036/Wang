#ifndef IDATASOURCE_H
#define IDATASOURCE_H

#include "CStuInfo.h"

class IDataSource
{
public:
    IDataSource();
    virtual ~IDataSource()=0;

    /**
     * @brief 查询所有学生的信息
     * @param stuInfos 学生们的信息
     * @return true-成功，false-失败
     */
    virtual bool selectStuInfos(QList<CStuInfo> &stuInfoList) = 0;

    /**
     * @brief 添加学生信息
     * @param stuInfo 学生信息
     * @return true-成功， false-失败
     */
    virtual bool addStuInfo(CStuInfo &stuInfo) = 0;

    /**
     * @brief 修改学生信息
     * @param stuInfo 学生信息
     * @return true-成功， false-失败
     */
    virtual bool updateStuInfo(CStuInfo &stuInfo) = 0;

    /**
     * @brief 删除学生学习
     * @param id 学号
     * @return true-成功， false-失败
     */
    virtual bool deleteStuInfo(int id) = 0;
};

#endif // IDATASOURCE_H
