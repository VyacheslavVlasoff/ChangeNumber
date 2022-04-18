#include "countrylist.h"
#include <QDebug>

CountryList::CountryList(QObject* parent):QAbstractListModel(parent)
{
    add("Европа","","","");
    add("Азия","","","");
    add("Европа","","","");
}

CountryList::~CountryList()
{

}

int CountryList::rowCount(const QModelIndex&) const
{
    return listOfCountry.size();
}


QVariant CountryList::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= listOfCountry.size())
            return QVariant();
      {
        switch (role) {
                case nameK:
                    return QVariant(listOfCountry.at(index.row()).getNameK());
                case nameG:
                    return QVariant(listOfCountry.at(index.row()).getNameG());
                case nameS:
                    return QVariant(listOfCountry.at(index.row()).getNameS());
                case cheell:
                    return QVariant(listOfCountry.at(index.row()).getCheell());

                default:
                    return QVariant();
            }

    }
}

QHash<int, QByteArray> CountryList::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[nameK] = "nameOfKontinent";
    roles[nameG] = "nameOfGosvo";
    roles[nameS] = "nameOfState";
    roles[cheell] = "kindOfCheell";
       return roles;
}

void CountryList::add(const QString& nameK, const QString& nameG, const QString& nameS, const QString& cheell){
     Country country;
    country.setNameK(nameK);
    country.setNameG(nameG);
    country.setNameS(nameS);
    country.setCheell(cheell);

    beginInsertRows(QModelIndex(),listOfCountry.size(),listOfCountry.size());
    listOfCountry.append(country);  //добавление в конец списка
    endInsertRows();

}

QAbstractListModel* CountryList::getModel(){
    return this;
}

void CountryList::del(const int index){

     if (index >= 0 && index < listOfCountry.size())
     {

    // сообщение модели о процессе удаления данных
         beginRemoveRows(QModelIndex(), index, index);
        listOfCountry.removeAt(index);
              endRemoveRows();
     }
     else qDebug() << "Error index";

}

void CountryList::edit(const QString& nameK, const QString& nameG, const QString& nameS, const QString& cheell, const int index) {
     if(index >= 0 && index < listOfCountry.size() )
     {
        auto& currentStudent = listOfCountry[index];
        if (currentStudent.getNameK().compare(nameK)!=0 ||
                currentStudent.getNameG().compare(nameG)!=0 ||
                currentStudent.getNameS().compare(nameS)!=0 ||
                currentStudent.getCheell().compare(cheell)!=0)
        {
            currentStudent.setNameK(nameK);
            currentStudent.setNameG(nameG);
            currentStudent.setNameS(nameS);
            currentStudent.setCheell(cheell);


            auto modelIndex = createIndex(index, 0);
            emit dataChanged(modelIndex, modelIndex);
            qDebug() << listOfCountry[index].getNameK();
        }

     }
      else qDebug() << "Error index";
}

int CountryList::countK(const int sel){
    int col = 0;
    auto str = "";
    if (sel == 1) str = "Европа";
    else if (sel == 2) str = "Азия";
    else if (sel == 3) str = "Африка";
    else if (sel == 4) str = "Австралия";
    else if (sel == 5) str = "Северная америка";
    else if (sel == 6) str = "Южная америка";
    for (int i = 0; i < listOfCountry.size(); i++)
    {
        auto& currentK = listOfCountry[i];
        if (currentK.getNameK() == str) col++;
    }
    return col;
}
