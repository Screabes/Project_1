#ifndef DIALOGREMOVE_H
#define DIALOGREMOVE_H

#include <QDialog>

namespace Ui {
class DialogRemove;
}

class DialogRemove : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRemove(QWidget *parent = nullptr);
    ~DialogRemove();
    int NumberRow();//возвращает значение номера строки
    bool ValueForRemove();


private slots:
    //void closeEvent(QCloseEvent *event);

    void on_Remove_clicked();

    void on_Cancel_clicked();

private:
    Ui::DialogRemove *ui;
};

#endif // DIALOGREMOVE_H
