#ifndef LINEDELEGATE_H
#define LINEDELEGATE_H

#include "QtWidgets"

class LineDelegate: public QStyledItemDelegate
{
    Q_OBJECT
public:
    LineDelegate(QObject *parent = nullptr);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void paint(QPainter* painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

};

#endif // LINEDELEGATE_H
