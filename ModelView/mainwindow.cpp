#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtWidgets"
#include "mymodel.h"
#include "QGridLayout"
#include "dialogdelegate.h"
#include "editgosvodialog.h"
#include "linedeligate.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    tableView = new QTableView();
    myModel = new MyModel(this);
    tableView->setModel( myModel );

    DialogDelegate* dialogdelegate = new DialogDelegate(nullptr,this);
    LineDelegate* labeldelegate = new LineDelegate();

    tableView->setItemDelegateForColumn(0,dialogdelegate);
    for (int i = 1; i < 4; i++)
        tableView->setItemDelegateForColumn(i,labeldelegate);
    tableView->viewport()->setAttribute(Qt::WA_Hover);
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QGridLayout* mainLayout= new QGridLayout();
    mainLayout->addWidget(tableView,1,1,1,2);

    QPushButton* btn1 = new QPushButton("Добавить информацию");
    QPushButton* btn2 = new QPushButton("Удалить");

    mainLayout->addWidget(btn1,2,1);
    mainLayout->addWidget(btn2,2,2);

    QObject::connect(btn1,SIGNAL(clicked(bool)),this,SLOT(AddRow()));
    QObject::connect(btn2,SIGNAL(clicked(bool)),this,SLOT(DeleteRow()));

    QWidget* wdg=new QWidget();
    wdg->setLayout(mainLayout);

    this->setCentralWidget(wdg);

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::AddRow()
{

    EditDialog* addDialog = new EditDialog(this);
    if (addDialog->exec() == QDialog::Accepted) {
        Gosvo* std = new Gosvo(addDialog->kontinent(),addDialog->gosudvo(),
                               addDialog->stolitsa(),addDialog->otdih(), this);
        myModel->AddGosvo(std);
    }

    addDialog->deleteLater();
}

void MainWindow::DeleteRow()
{

    QModelIndex selList = tableView->currentIndex();
    myModel->DeleteGosvo(selList.row());
}
