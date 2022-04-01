#include "dialogdelegate.h"
#include "QtWidgets"
#include "editgosvodialog.h"

DialogDelegate::DialogDelegate(QObject *parent, QWidget* parentWidget): QStyledItemDelegate(parent)
{
    dparentWidget = parentWidget;
}

bool DialogDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                 const QStyleOptionViewItem &, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        EditDialog* editDialog = new EditDialog(dparentWidget);

        QString Kontinent = model->data(model->index(index.row(),0,index)).toString();
        QString Gosudvo = model->data(model->index(index.row(),1,index)).toString();
        QString Stolitsa = model->data(model->index(index.row(),2,index)).toString();
        QString Otdih = model->data(model->index(index.row(),3,index)).toString();


        editDialog->SetUpDialog(Kontinent, Gosudvo, Stolitsa, Otdih);
        if (editDialog->exec() == QDialog::Accepted)
        {
            model->setData(model->index(index.row(),0,index),editDialog->kontinent());
            model->setData(model->index(index.row(),1,index),editDialog->gosudvo());
            model->setData(model->index(index.row(),2,index),editDialog->stolitsa());
            model->setData(model->index(index.row(),3,index),editDialog->otdih());
        }

         editDialog->deleteLater();
    }
    return false;

}

QWidget *DialogDelegate::createEditor(QWidget* /* parent */,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    return nullptr;
}
