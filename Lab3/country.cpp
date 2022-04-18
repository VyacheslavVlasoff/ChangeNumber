#include "country.h"

Country::Country()
{

}
QString Country::getNameK() const
{
    return nameK;
}
QString Country::getNameG() const
{
    return nameG;
}
QString Country::getNameS() const
{
    return nameS;
}
QString Country::getCheell() const
{
    return cheell;
}
void Country::setNameK(const QString &K)
{
    nameK = K;
}
void Country::setNameG(const QString &G)
{
    nameG = G;
}
void Country::setNameS(const QString &S)
{
    nameS = S;
}
void Country::setCheell(const QString &Ch)
{
    cheell = Ch;
}


