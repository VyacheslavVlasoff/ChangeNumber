#include "editgosvodialog.h"
#include "gosvo.h"
EditDialog::EditDialog(QWidget* pwgt): QDialog(pwgt)
{
    editKontinent = new QLineEdit();
    editGosudvo = new QLineEdit();
    editStolitsa = new QLineEdit();
    editOtdih = new QLineEdit();

    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->addWidget(new QLabel("Континент"),1,1);
    mainLayout->addWidget(editKontinent,1,2);
    mainLayout->addWidget(new QLabel("Государство"),2,1);
    mainLayout->addWidget(editGosudvo,2,2);
    mainLayout->addWidget(new QLabel("Столица"),3,1);
    mainLayout->addWidget(editStolitsa,3,2);
    mainLayout->addWidget(new QLabel("Отдых"),4,1);
    mainLayout->addWidget(editOtdih,4,2);


    QPushButton* btnOk = new QPushButton("&ОК");

     mainLayout->addWidget(btnOk,5,1,1,2);

    QObject::connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));

    this->setLayout(mainLayout);
    this->setWindowTitle("Данные о стране");


    //Располагаем диалог над основным окном
    int gx = 100;
    int gy = 100;
    if (pwgt!=nullptr)
    {
        gx = pwgt->geometry().x();
        gy = pwgt->geometry().y();

    }
    this->setGeometry(gx+10,gy+10,300,150);
}

QString EditDialog::kontinent() const
{
    return editKontinent->text();
}
QString EditDialog::gosudvo() const
{
    return editGosudvo->text();
}
QString EditDialog::stolitsa() const
{
    return editStolitsa->text();
}
QString EditDialog::otdih() const
{
    return editOtdih->text();
}
void EditDialog::SetUpDialog(QString kontinent, QString gosudvo,QString stolitsa, QString otdih)
{
    editKontinent->setText(kontinent);
    editGosudvo->setText(gosudvo);
    editStolitsa->setText(stolitsa);
    editOtdih->setText(otdih);
}
