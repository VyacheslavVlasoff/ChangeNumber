#ifndef CHANGENUMBERWINDOW_H
#define CHANGENUMBERWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class ChangeNumberWindow; }
QT_END_NAMESPACE

class ChangeNumberWindow : public QMainWindow
{
    Q_OBJECT

public:
    ChangeNumberWindow(QWidget *parent = nullptr);
    ~ChangeNumberWindow();

public slots:
void NumberPlus();
void NumberMinus();
void Remove();

private:
    Ui::ChangeNumberWindow *ui;
    QLineEdit* number;
    QLineEdit* max;
    QLineEdit* min;
    QLabel* label;
    QProgressBar* pb; int steep = 0;
    QLabel* last;
};
#endif // CHANGENUMBERWINDOW_H
