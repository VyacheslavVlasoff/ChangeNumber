#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    :QAbstractTableModel(parent)
{
//    students = new QList<Student*>();
    Gosvo* std1 = new Gosvo("Европа","Германия","Берлин","пивко", this);
    Gosvo* std2 = new Gosvo("Азия","Китай","Пекин","суши", this);
    Gosvo* std3 = new Gosvo("Африка","Египет","Каир","песочек", this);
    Gosvo* std4 = new Gosvo("Африка","Алжир","Алжир","", this);
    Gosvo* std5 = new Gosvo("Азия","Армения","Ереван","", this);
    Gosvo* std6 = new Gosvo("Европа","Белоруссия","Минск","", this);
    Gosvo* std7 = new Gosvo("Южная Америка","Бразилия","Бразилиа","", this);
    Gosvo* std8 = new Gosvo("Северная Америка","США","Вашингтон","", this);
    Gosvo* std9 = new Gosvo("Европа","Франция","Париж","", this);
    Gosvo* std10 = new Gosvo("Европа","Австрия","Вена","", this);
    Gosvo* std11 = new Gosvo("Азия","Таиланд","Бангкок","", this);
    Gosvo* std12 = new Gosvo("Африка","Марокко","Рабат","", this);
    Gosvo* std13 = new Gosvo("Африка","Габон","Либревиль","", this);
    Gosvo* std14 = new Gosvo("Европа","Ирландия","Дублин","", this);
    Gosvo* std15 = new Gosvo("Азия","КНДР","Пхеньян","", this);
    Gosvo* std16 = new Gosvo("Северная Америка","Канада","Оттава","", this);
    Gosvo* std17 = new Gosvo("Южная Америка","Аргентина","Буэнос-Айрес","", this);
    Gosvo* std18 = new Gosvo("Европа","Ватикан","Ватикан","", this);
    Gosvo* std19 = new Gosvo("Азия","Абхазия","Сухум","", this);
    Gosvo* std20 = new Gosvo("Азия","Вьетнам","Ханой","", this);
    Gosvo* std21 = new Gosvo("Азия","Япония","Токио","", this);
    Gosvo* std22 = new Gosvo("Австралия","Новая Зеландия","Веллингтон","", this);
    AddGosvo(std1);
    AddGosvo(std2);
    AddGosvo(std3);
    AddGosvo(std4);
    AddGosvo(std5);
    AddGosvo(std6);
    AddGosvo(std7);
    AddGosvo(std8);
    AddGosvo(std9);
    AddGosvo(std10);
    AddGosvo(std11);
    AddGosvo(std12);
    AddGosvo(std13);
    AddGosvo(std14);
    AddGosvo(std15);
    AddGosvo(std16);
    AddGosvo(std17);
    AddGosvo(std18);
    AddGosvo(std19);
    AddGosvo(std20);
    AddGosvo(std21);
    AddGosvo(std22);

}

int MyModel::rowCount(const QModelIndex &) const
{
   return gosvo.count();
}

int MyModel::columnCount(const QModelIndex &) const
{
    return 4;
}


QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        QString Value = "";
        Gosvo* std = gosvo.at(index.row());
        if (index.column() == 0){Value = std->Kontinent();}
        else if (index.column() == 1){Value = std->Gosudvo();}
        else if (index.column() == 2){Value = std->Stolitsa();}
        else if (index.column() == 3){Value = std->Otdih();}
        else {Value = "";};
       return Value;
    }
    return QVariant();
}


QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("КОНТИНЕНТ");
            case 1:
                return QString("ГОСУДАРСТВО");
            case 2:
                return QString("СТОЛИЦА");
            case 3:
                return QString("ОТДЫХ");
            }
        }
    }
    return QVariant();
}


bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
   if (role == Qt::EditRole)
    {
        Gosvo* std = gosvo.at(index.row());
        if (index.column() == 0){std->SetKontinent(value.toString());}
        else if (index.column() == 1){std->SetGosvo(value.toString());}
        else if (index.column() == 2){std->SetStolitsa(value.toString());}
        else if (index.column() == 3){std->SetOtdih(value.toString());}
    }
    //QAbstractTableModel::setData(index,value,  role);
    return true;
}

//Qt::ItemFlags MyModel::flags(const QModelIndex & /*index*/) const
//{
//    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
//}

void MyModel::AddGosvo(Gosvo *gosv)
{
    beginInsertRows(QModelIndex(),gosvo.size(),gosvo.size());
    gosvo.append(gosv);
    endInsertRows();
    //emit layoutChanged(); //Можно так
}

void MyModel::DeleteGosvo(int row)
{
    beginRemoveRows(QModelIndex(),row,row);
    gosvo.removeAt(row);
    endRemoveRows();
    //emit layoutChanged(); //Можно так
}

