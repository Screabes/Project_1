#ifndef DIALOGADD_H
#define DIALOGADD_H

#include <QDialog>

namespace Ui {
class DialogAdd;
}

class DialogAdd : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAdd(QWidget *parent = nullptr);
    ~DialogAdd();
    QString ValueName();//возвращает значение строки с именем
    QString ValueProteins();//возвращает значение строки белков
    QString ValueFats();//возвращает значение строки жиров
    QString ValueCarbohydrates();//возвращает значение строки
    bool ValueForAdd();

private slots:
    //void closeEvent(QCloseEvent *event);

    void on_AddRow_clicked();

    void on_Cancel_clicked();

private:
    Ui::DialogAdd *ui;
};

#endif // DIALOGADD_H
