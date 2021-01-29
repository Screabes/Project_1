#include "dialogsort.h"
#include "ui_dialogsort.h"
#include <QMessageBox>
#include "laba6.h"
#include <QCloseEvent>

DialogSort::DialogSort(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSort)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    ui->Number->setValidator(new QRegExpValidator(QRegExp("^[0-9]{0,20}$\\d"), this));//задаем то,что можно вводить ^$-ограничивает выражение не забывать про них
}

DialogSort::~DialogSort()
{
    delete ui;
}
bool DialogSort::StateButtonName()//начало кнопок для типа сортировки
{
bool flag=ui->ButtonSortByName->isChecked();
        return flag;
}
bool DialogSort::StateButtonProteins()
{
bool flag=ui->ButtonSortByProteins->isChecked();
        return flag;
}
bool DialogSort::StateButtonFats()
{
bool flag=ui->ButtonSortByFats->isChecked();
        return flag;
}
bool DialogSort::StateButtonCarbohydrates()//конец
{
bool flag=ui->ButtonSortByCarbohydrates->isChecked();
        return flag;
}
bool DialogSort::ButtonProteins()//начало кнопок для сортировки выше какого-то значения
{
    bool flag=ui->ButtonProteins->isChecked();
            return flag;
}
bool DialogSort::ButtonFats()
{
    bool flag=ui->ButtonFats->isChecked();
            return flag;
}
bool DialogSort::ButtonCarbohydrates()//конец
{
    bool flag=ui->ButtonCarbohydrates->isChecked();
            return flag;
}
int DialogSort::Number()//выше какого значнеия сортировать
{
    int number=ui->Number->text().toInt();
            return number;
}
bool DialogSort::Index0()
{
    bool flag;
    if((ui->BoxChoice->currentIndex()==-1)||(ui->BoxChoice->currentIndex()==0))
    {
        flag=true;
    }
    return flag;
}
bool DialogSort::Index1()
{
    bool flag;
    if(ui->BoxChoice->currentIndex()==1)
    {
        flag=true;
    }
    return flag;
}
bool DialogSort::Index2()
{
    bool flag;
    if(ui->BoxChoice->currentIndex()==2)
    {
        flag=true;
    }
    return flag;
}
/*void DialogSort::closeEvent(QCloseEvent *event)
{
    if (!StateButtonName()&&!StateButtonProteins()&&!StateButtonFats()&&!StateButtonCarbohydrates())
    {
        QMessageBox::warning(this,"Предупреждение.","Выберите тип сортировки");
        event->ignore();
    }
    else
    {
         StateButtonName();
         StateButtonProteins();
         StateButtonFats();
         StateButtonCarbohydrates();
         ButtonProteins();
         ButtonFats();
         ButtonCarbohydrates();
         Number();
         Index0();
         Index1();
         Index2();
         DialogSort::close();
    }
}*/
bool DialogSort::ValueForSort()//возвращает true если нажата ok а не отмена чтобы начать создавать строки в Elements после нажатия
{
    QString tmp=ui->label_2->text();
    if (tmp=="1")
    {
        return true;
    }
    else
    {
        return false;
    }
}
void DialogSort::on_Sort_clicked()
{
    if (!StateButtonName()&&!StateButtonProteins()&&!StateButtonFats()&&!StateButtonCarbohydrates())
    {
        QMessageBox::warning(this,"Предупреждение.","Выберите тип сортировки");
    }
    else
    {
         StateButtonName();
         StateButtonProteins();
         StateButtonFats();
         StateButtonCarbohydrates();
         ButtonProteins();
         ButtonFats();
         ButtonCarbohydrates();
         Number();
         Index0();
         Index1();
         Index2();
         ui->label_2->setText("1");
         DialogSort::close();
    }
}

void DialogSort::on_Cancel_clicked()
{
    DialogSort::close();
}
