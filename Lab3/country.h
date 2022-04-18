#ifndef COUNTRY_H
#define COUNTRY_H

#include <QString>
class Country
{
private:

    QString nameK;
    QString nameG;
    QString nameS;
    QString cheell;


public:
    Country();
    QString getNameK() const;
    QString getNameG() const;
    QString getNameS() const;
    QString getCheell() const;
    void setNameK(const QString &K);
    void setNameG(const QString &G);
    void setNameS(const QString &S);
    void setCheell(const QString &Ch);
};

#endif // COUNTRY_H
