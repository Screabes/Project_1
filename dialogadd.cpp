#include "dialogadd.h"
#include "ui_dialogadd.h"
#include <QValidator>
#include <QMessageBox>
#include <QCloseEvent>
#include "laba6.h"
DialogAdd::DialogAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAdd)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    ui->Name->setValidator(new QRegExpValidator(QRegExp("^[а-яА-я]{0,20}$\\d"), this));//задаем то,что можно вводить ^$-ограничивает выражение не забывать про них
    ui->Proteins->setValidator(new QRegExpValidator(QRegExp("^[0-9]{0,20}$\\d"), this));//задаем то,что можно вводить ^$-ограничивает выражение не забывать про них
    ui->Fats->setValidator(new QRegExpValidator(QRegExp("^[0-9]{0,20}$\\d"), this));//задаем то,что можно вводить ^$-ограничивает выражение не забывать про них
    ui->Carbohydrates->setValidator(new QRegExpValidator(QRegExp("^[0-9]{0,20}$\\d"), this));//задаем то,что можно вводить ^$-ограничивает выражение не забывать про них
}

DialogAdd::~DialogAdd()
{
    delete ui;
}
QString DialogAdd::ValueName()
{
   QString Name=ui->Name->text();
   return Name;
}
QString DialogAdd::ValueProteins()
{
    QString Proteins=ui->Proteins->text();
    return Proteins;
}
QString DialogAdd::ValueFats()
{
    QString Fats=ui->Fats->text();
    return Fats;
}
QString DialogAdd::ValueCarbohydrates()
{
QString Carbohydrates=ui->Carbohydrates->text();
return Carbohydrates;
}

/*void DialogAdd::closeEvent(QCloseEvent *event)
{
    if ((ui->Name->text().isEmpty())&&(ui->AddRow->isChecked()))
    {
        QMessageBox::warning(this,"Предупреждение.","Введите название продукта.");
        event->ignore();
    }
    else
    {
        ValueForAdd(false);
        DialogAdd::close();
   }
}*/

bool DialogAdd::ValueForAdd() //если или это или это то не дает в основе делать ничего
{
    QString tmp=ui->label_5->text();
    if (tmp=="1")
    {
        return true;
    }
    else
    {
        return false;
    }
}
void DialogAdd::on_AddRow_clicked()
{
    if (ui->Name->text().isEmpty())
    {
        QMessageBox::warning(this,"Предупреждение.","Введите название продукта.");
    }
    else
    {
        if (ui->Proteins->text().isEmpty())
        {
            ui->Proteins->setText("0");
        }
        if (ui->Fats->text().isEmpty())
        {
            ui->Fats->setText("0");
        }
        if (ui->Carbohydrates->text().isEmpty())
        {
            ui->Carbohydrates->setText("0");
        }
        ValueName();
        ValueProteins();
        ValueFats();
        ValueCarbohydrates();
        ui->label_5->setText("1");
        DialogAdd::close();
   }
}

void DialogAdd::on_Cancel_clicked()
{
    DialogAdd::close();
}
