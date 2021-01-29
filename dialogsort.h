#ifndef DIALOGSORT_H
#define DIALOGSORT_H

#include <QDialog>

namespace Ui {
class DialogSort;
}
class DialogSort : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSort(QWidget *parent = nullptr);
    ~DialogSort();
    Ui::DialogSort *ui;
    bool StateButtonName();
    bool StateButtonProteins();
    bool StateButtonFats();
    bool StateButtonCarbohydrates();
    bool ButtonProteins();
    bool ButtonFats();
    bool ButtonCarbohydrates();
    int Number();
    bool Index0();
    bool Index1();
    bool Index2();
    bool ValueForSort();


private slots:
   // void closeEvent(QCloseEvent *event);

    void on_Sort_clicked();

    void on_Cancel_clicked();

private:

};

#endif // DIALOGSORT_H
