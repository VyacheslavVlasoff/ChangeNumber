#include "countrylistsql.h"
#include "QObject"

countryListSQL::countryListSQL(QObject *parent) :
    QSqlQueryModel(parent)
{
//    QSqlDatabase::removeDatabase("myConnection");

    db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("Countries");
       db.setPort(5432);
       db.setPassword("123");
       db.setUserName("Postgre");

       QSqlQuery query(db);

     _isConnectionOpen = true;

    if(!db.open())
    {
        qDebug() << db.lastError().text();
        _isConnectionOpen = false;
    }

/*    QSqlQuery qry(db);
    qry.prepare( "CREATE TABLE IF NOT EXISTS Countries "
                 "(Id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,"
                 "NameK VARCHAR(150), NameG VARCHAR(150),"
                 "NameS VARCHAR(150),Cheell VARCHAR(150))" );
    if( !qry.exec() )
    {
        qDebug() << db.lastError().text();
        _isConnectionOpen = false;
    }
*/
    refresh();
}

QSqlQueryModel* countryListSQL::getModel(){
    return this;
}

bool countryListSQL::isConnectionOpen(){
    return _isConnectionOpen;
}

QHash<int, QByteArray> countryListSQL::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole + 1] = "nameOfK";
    roles[Qt::UserRole + 2] = "nameOfG";
    roles[Qt::UserRole + 3] = "nameOfS";
    roles[Qt::UserRole + 4] = "kindOfCh";
    roles[Qt::UserRole + 5] = "Id_country";

    return roles;
}

QVariant countryListSQL::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlQueryModel::data(index, role);
    if(role < Qt::UserRole-1)
    {
        value = QSqlQueryModel::data(index, role);
    }
    else
    {
        int columnIdx = role - Qt::UserRole - 1;
        QModelIndex modelIndex = this->index(index.row(), columnIdx);
        value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
    }
    return value;
}

const char* countryListSQL::SQL_SELECT =
        "SELECT Countries.NameK, Countries.NameG, Countries.NameS, Countries.Cheell, Countries.Id"
        " FROM Countries";

void countryListSQL::refresh()
{
    this->setQuery(countryListSQL::SQL_SELECT,db);
    qDebug() << db.lastError().text();
}

void countryListSQL::add(const QString& nameK, const QString& nameG, const QString& nameS, const QString& cheell){

    QSqlQuery query(db);

    QString strQuery= QString("INSERT INTO Countries (NameK,NameG,NameS,Cheell) VALUES ('%1', '%2', '%3', '%4')")
            .arg(nameK)
            .arg(nameG)
            .arg(nameS)
            .arg(cheell);

    bool res = query.exec(strQuery);
    qDebug() << res;

    refresh();
}

void countryListSQL::edit(const QString& nameK, const QString& nameG, const QString& nameS, const QString& cheell, const int Id_country){

    QSqlQuery query(db);
    QString strQuery= QString("UPDATE Countries SET NameK = '%1',NameG = '%2',NameS = '%3',Cheell = '%4' WHERE Id = %5")
            .arg(nameK)
            .arg(nameG)
            .arg(nameS)
            .arg(cheell)
            .arg(Id_country);

    bool res = query.exec(strQuery);
    qDebug() << res;

    refresh();
}
void countryListSQL::del(const int Id_country){


    QSqlQuery query(db);
    QString strQuery= QString("DELETE FROM Countries WHERE Id = %1")
            .arg(Id_country);

    bool res = query.exec(strQuery);
    qDebug() << res;

    refresh();
}
