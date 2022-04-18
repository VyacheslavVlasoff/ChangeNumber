#ifndef COUNTRYLIST_H
#define COUNTRYLIST_H


#include <QAbstractListModel>
#include <QVariant>
#include <QList>
#include <QModelIndex>
#include <QItemSelectionModel>
#include "country.h"

class CountryList : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(QAbstractListModel* countryModel READ getModel CONSTANT)  /* первый параметр - тип свойства (property)
                                                                     второй параметр - имя свойства, по которому будем обращаться к реальной модели в qml-файле
                                                                     третий параметр - метод С++ для получения значения свойства (получим саму модель)
                                                                     CONSTANT - qml получит свойство однократно, и в процессе работы это свойство изменяться не будет */
private:
    QList<Country> listOfCountry; // непосредственно данные
    QAbstractListModel *getModel();

public:
    CountryList(QObject *parent = nullptr);
    ~CountryList() override;

    // количество колонок
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

     // возвращение данных модели по указанному индексу и роли
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

    enum ResentRoles {
            nameK = Qt::DisplayRole,
            nameG = Qt::UserRole + 1,
            nameS = Qt::UserRole + 2,
            cheell = Qt::UserRole + 3
       };

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void add(const QString& nameK, const QString& nameG, const QString& nameS, const QString& cheell);  // макрос указывает, что к методу можно обратиться из QML
    Q_INVOKABLE void del(const int index);
    Q_INVOKABLE void edit(const QString& nameK, const QString& nameG, const QString& nameS, const QString& cheell, const int index);
    Q_INVOKABLE int countK(const int sel);
};

#endif // COUNTRYLIST_H
