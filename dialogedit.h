#ifndef DIALOGEDIT_H
#define DIALOGEDIT_H

#include <QDialog>

namespace Ui {
class DialogEdit;
}

class DialogEdit : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEdit(QWidget *parent = nullptr);
    ~DialogEdit();
    int NumberRow();//возвращает значение номера строки
    QString ValueName();//возвращает значение строки с именем
    QString ValueProteins();//возвращает значение строки белков
    QString ValueFats();//возвращает значение строки жиров
    QString ValueCarbohydrates();//возвращает значение строки углеводов
    bool ValueForEdit();



private slots:
    //void closeEvent(QCloseEvent *event);

    void on_Edit_clicked();

    void on_Cancel_clicked();
private:
    Ui::DialogEdit *ui;
};

#endif // DIALOGEDIT_H
