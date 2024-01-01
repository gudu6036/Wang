#include "CStuInfo.h"

CStuInfo::CStuInfo()
{

}

bool CStuInfo::setData(int id, QString name, QString sex, QString phone, int cet4, double gpa)
{
    m_id = id;
    m_name = name;
    m_sex = sex;
    m_phone = phone;
    m_cet4 = cet4;
    m_gpa = gpa;
    m_overallScore = 0.04*cet4 + gpa*17.5;

    return true;
}

int CStuInfo::id() const
{
    return m_id;
}

void CStuInfo::setId(int id)
{
    m_id = id;
}

QString CStuInfo::name() const
{
    return m_name;
}

void CStuInfo::setName(const QString &name)
{
    m_name = name;
}

QString CStuInfo::sex() const
{
    return m_sex;
}

void CStuInfo::setSex(const QString &sex)
{
    m_sex = sex;
}

QString CStuInfo::phone() const
{
    return m_phone;
}

void CStuInfo::setPhone(const QString &phone)
{
    m_phone = phone;
}

int CStuInfo::cet4() const
{
    return m_cet4;
}

void CStuInfo::setCet4(int cet4)
{
    m_cet4 = cet4;
}

double CStuInfo::gpa() const
{
    return m_gpa;
}

void CStuInfo::setGpa(double gpa)
{
    m_gpa = gpa;
}

double CStuInfo::overallScore() const
{
    return m_overallScore;
}

void CStuInfo::setOverallScore(double overallScore)
{
    m_overallScore = overallScore;
}
