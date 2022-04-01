#pragma once
#define MYMODEL_H


#include <QAbstractTableModel>
#include <QString>
#include "gosvo.h"

class MyModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    MyModel(QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    //Qt::ItemFlags flags(const QModelIndex & index) const ;


    void AddGosvo(Gosvo* gosv);
    void DeleteGosvo(int row);
private:
    QList<Gosvo*> gosvo;
};
