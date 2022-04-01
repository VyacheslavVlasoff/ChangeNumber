#ifndef STUDENT_H
#define STUDENT_H
#include "QString"
#include <QObject>

class Gosvo: public QObject
{
    Q_OBJECT

public:
    Gosvo(QString Kontinent, QString Gosudvo,
            QString Stolitsa, QString Otdih,
            QObject *parent = nullptr );
    virtual ~Gosvo();
    void SetKontinent(QString Kontinent);
    void SetGosvo(QString Gosudvo);
    void SetStolitsa(QString Stolitsa);
    void SetOtdih(QString Otdih);

    QString Kontinent();
    QString Gosudvo();
    QString Stolitsa();
    QString Otdih();
    static QStringList GetOtdih();

private:
    QString kontinent;
    QString gosudvo;
    QString stolitsa;
    QString otdih;
};



#endif
