#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    :QAbstractTableModel(parent)
{
//    students = new QList<Student*>();
    Gosvo* std1 = new Gosvo("Европа","Германия","Берлин","пивко", this);
    Gosvo* std2 = new Gosvo("Азия","Китай","Пекин","суши", this);
    Gosvo* std3 = new Gosvo("Африка","Египет","Каир","песочек", this);
    AddGosvo(std1);
    AddGosvo(std2);
    AddGosvo(std3);
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

