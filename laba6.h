#ifndef LABA6_H
#define LABA6_H

#include <QMainWindow>
struct Product//шаблон продукта
{
    QString Name;
    int Proteins;
    int Fats;
    int Carbohydrates;
    int Row;
};
namespace Ui {
class laba6;
}

class laba6 : public QMainWindow
{
    Q_OBJECT

public:
    explicit laba6(QWidget *parent = nullptr);
    ~laba6();

    //void closeEvent(QCloseEvent *event);
    void Rewrite();
        void resizeEvent(QResizeEvent*);
        int SummProteins(Product products[],int rows);
        int SummFats(Product products[],int rows);
        int SummCarbohydrates(Product products[],int rows);
        double AverageValue(Product products[],int rows);
        Product Fillproducts(int row);
        int NumbersOfRows();
        QString ValueProteinsForEdit (int row);
        QString ValueFatsForEdit (int row);
        QString ValueCarbohydratesForEdit (int row);

private slots:
    void on_Add_clicked();

    void on_Remove_clicked();

    void on_Edit_clicked();

    void on_Sort_clicked();
private:
    Ui::laba6 *ui;
};

#endif // LABA6_H
