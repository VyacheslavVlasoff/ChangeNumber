#include "gosvo.h"

Gosvo::Gosvo(QString Kontinent, QString Gosudvo, QString Stolitsa, QString Otdih, QObject *parent): QObject(parent)
{
    kontinent = Kontinent;
    gosudvo = Gosudvo;
    stolitsa = Stolitsa;
    otdih = Otdih;
}

void Gosvo::SetKontinent(QString Kontinent)
{
    kontinent = Kontinent;
}
void Gosvo::SetGosvo(QString Gosudvo)
{
    gosudvo = Gosudvo;
}
void Gosvo::SetStolitsa(QString Stolitsa)
{
    stolitsa = Stolitsa;
}
void Gosvo::SetOtdih(QString Otdih)
{
    otdih = Otdih;
}
QString Gosvo::Kontinent()
{
    return kontinent;
}
QString Gosvo::Gosudvo()
{
    return gosudvo;
}
QString Gosvo::Stolitsa()
{
    return stolitsa;
}
QString Gosvo::Otdih()
{
    return otdih;
}
 Gosvo::~Gosvo()
{
}
