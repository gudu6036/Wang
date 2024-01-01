#ifndef CSTUINFO_H
#define CSTUINFO_H

#include <QString>
#include <QMetaType>

class CStuInfo
{
public:
    CStuInfo();
    bool setData(int id,QString name,QString sex,QString phone,int cet4,double gpa);


    int id() const;
    void setId(int id);

    QString name() const;
    void setName(const QString &name);

    QString sex() const;
    void setSex(const QString &sex);

    QString phone() const;
    void setPhone(const QString &phone);

    int cet4() const;
    void setCet4(int cet4);

    double gpa() const;
    void setGpa(double gpa);

    double overallScore() const;
    void setOverallScore(double overallScore);

private:
    int m_id;              //学生id 四位数字
    QString m_name;        //学生名称
    QString m_sex;         //男 女
    QString m_phone;       //11位
    int m_cet4;            //0~750
    double m_gpa;          //0~4
    double m_overallScore; //总成绩 综合成绩= 0.04*cet4 + gpa*17.5;
};
Q_DECLARE_METATYPE(CStuInfo)
#endif // CSTUINFO_H
