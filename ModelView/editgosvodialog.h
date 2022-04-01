#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "gosvo.h"

class EditDialog : public QDialog
{
  Q_OBJECT

private:
    QLineEdit* editKontinent;
    QLineEdit* editGosudvo;
    QLineEdit* editStolitsa;
    QLineEdit* editOtdih;

public:
    EditDialog(QWidget* pwgt = nullptr);

    QString kontinent() const;
    QString gosudvo() const;
    QString stolitsa() const;
    QString otdih() const;

    void SetUpDialog(QString kontinent, QString gosudvo,QString stolitsa, QString otdih);
};

#endif // INPUTDIALOG_H
