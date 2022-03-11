#include "changenumberwindow.h"
#include "ui_changenumberwindow.h"

ChangeNumberWindow::ChangeNumberWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChangeNumberWindow)
{
    ui->setupUi(this);
    number = new QLineEdit();
    number->setText("5");
    number->setFixedWidth(25);
    max = new QLineEdit();
    max->setText("9");
    max->setFixedWidth(25);
    min = new QLineEdit();
    min->setText("0");
    min->setFixedWidth(25);
    QPushButton* btnPlus = new QPushButton;
    btnPlus->setText("+");
    btnPlus->setFixedWidth(25);
    QPushButton* btnMinus = new QPushButton;
    btnMinus->setText("-");
    btnMinus->setFixedWidth(25);
    QPushButton* btnOk = new QPushButton;
    btnOk->setText("Ok");
    btnOk->setFixedWidth(25);
    pb = new QProgressBar;
    pb->setFormat("%v");
    pb->setRange(0, 9);
    pb->setValue(5);
    pb->setAlignment(Qt::AlignCenter);
    label = new QLabel;
    label->setStyleSheet("color: red; font-size: 11pt");
    last = new QLabel;
    last->setText("5");

    QGridLayout* chLayout = new QGridLayout;
    chLayout->setMargin(5);
    chLayout->addWidget(min, 2, 0);
    chLayout->addWidget(number, 1, 0);
    chLayout->addWidget(max, 0, 0);
    chLayout->addWidget(btnPlus, 0, 1);
    chLayout->addWidget(btnMinus, 2, 1);
    chLayout->addWidget(btnOk, 3, 0);
    chLayout->addWidget(pb, 1, 1);
    chLayout->addWidget(label, 3, 1);
    chLayout->addWidget(last, 1, 2);

    QWidget* w = new QWidget();
    w->setLayout(chLayout);

    this->setCentralWidget(w);

    connect(btnPlus, SIGNAL(clicked(bool)), this, SLOT(NumberPlus()));
    connect(btnMinus, SIGNAL(clicked(bool)), this, SLOT(NumberMinus()));
    connect(btnOk, SIGNAL(clicked(bool)), this, SLOT(Remove()));

}

void ChangeNumberWindow::Remove()
{
    QString a = min->text();
    QString b = max->text();
    QString c = number->text();
    pb->setRange(a.toInt(), b.toInt());
    pb->setValue(c.toInt());
}

void ChangeNumberWindow::NumberPlus()
{
        if (last->text() != number->text()) last->setText(number->text());
    QString smax = max->text();
    QString str = number->text();
    int s = str.toInt();
    if (smax.toInt() > s) {
        pb->setValue(s+1);
    number->setText(QString::number(s+1));
    }
    if (smax.toInt() == s)
    label->setText("Дальнейшее увеличение невозможно");
    else label->clear();
}

void ChangeNumberWindow::NumberMinus()
{
        if (last->text() != number->text()) last->setText(number->text());
    QString smin = min->text();
    QString str = number->text();
    int s = str.toInt();
    if (smin.toInt() < s) {
        pb->setValue(s-1);
    number->setText(QString::number(s-1)); 
    }
    if (smin.toInt() == s)
    label->setText("Дальнейшее уменьшение невозможно");
    else label->clear();
}

ChangeNumberWindow::~ChangeNumberWindow()
{
    delete ui;
}

