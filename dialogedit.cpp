#include "dialogedit.h"
#include "ui_dialogedit.h"
#include <QValidator>
#include <QMessageBox>
#include "laba6.h"
#include <QCloseEvent>

DialogEdit::DialogEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEdit)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    ui->Name->setValidator(new QRegExpValidator(QRegExp("^[а-яА-я]{0,20}$\\d"), this));//задаем то,что можно вводить ^$-ограничивает выражение не забывать про них
    ui->Proteins->setValidator(new QRegExpValidator(QRegExp("^[0-9]{0,20}$\\d"), this));//задаем то,что можно вводить ^$-ограничивает выражение не забывать про них
    ui->Fats->setValidator(new QRegExpValidator(QRegExp("^[0-9]{0,20}$\\d"), this));//задаем то,что можно вводить ^$-ограничивает выражение не забывать про них
    ui->Carbohydrates->setValidator(new QRegExpValidator(QRegExp("^[0-9]{0,20}$\\d"), this));//задаем то,что можно вводить ^$-ограничивает выражение не забывать про них
    ui->LineNumberEditRow->setValidator(new QRegExpValidator(QRegExp("^[0-9]{0,20}$\\d"), this));//задаем то,что можно вводить ^$-ограничивает выражение не забывать про них
}

DialogEdit::~DialogEdit()
{
    delete ui;
}
int DialogEdit::NumberRow()
{
     int LineNumberRemoveRow=ui->LineNumberEditRow->text().toInt();
     return LineNumberRemoveRow;
}
QString DialogEdit::ValueName()
{
   QString Name=ui->Name->text();
   return Name;
}
QString DialogEdit::ValueProteins()
{
    laba6 laba6;
    if ((ui->Proteins->text().isEmpty()))
    {
        int LineNumberEditRow=ui->LineNumberEditRow->text().toInt();
        QString Proteins=laba6.ValueProteinsForEdit(LineNumberEditRow);
        return Proteins;

    }
    else
    {
        QString Proteins=ui->Proteins->text();
        return Proteins;
    }

}
QString DialogEdit::ValueFats()
{
    laba6 laba6;
    if ((ui->Fats->text().isEmpty()))
    {
        int LineNumberEditRow=ui->LineNumberEditRow->text().toInt();
        QString Fats=laba6.ValueFatsForEdit(LineNumberEditRow);
        return Fats;

    }
    else
    {
        QString Fats=ui->Fats->text();
        return Fats;
    }

}
QString DialogEdit::ValueCarbohydrates()
{
    laba6 laba6;
    if ((ui->Carbohydrates->text().isEmpty()))
    {
        int LineNumberEditRow=ui->LineNumberEditRow->text().toInt();
        QString Carbohydrates=laba6.ValueCarbohydratesForEdit(LineNumberEditRow);
        return Carbohydrates;

    }
    else
    {
        QString Carbohydrates=ui->Carbohydrates->text();
        return Carbohydrates;
    }
}
bool DialogEdit::ValueForEdit()
{
    QString tmp=ui->label_6->text();
    if (tmp=="1")
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*void DialogEdit::closeEvent(QCloseEvent *event)
{
    bool CheckRow=true,CheckName=true;
    if ((ui->LineNumberEditRow->text().isEmpty())&&(ui->Edit->isChecked()))
    {
        QMessageBox::warning(this,"Предупреждение.","Введите номер строки.");
        CheckRow=false;
        event->ignore();
    }
    laba6 laba6;
    int rows=laba6.NumbersOfRows();
    if ((((ui->LineNumberEditRow->text().toInt())>rows)||((ui->LineNumberEditRow->text().toInt())<1))&&CheckRow)
    {
        QMessageBox::warning(this,"Предупреждение.","Строки с таким номером нет.");
        CheckRow=false;
        event->ignore();
    }
    if ((ui->Name->text().isEmpty())&&CheckRow)
    {
        QMessageBox::warning(this,"Предупреждение.","Введите название продукта.");
        CheckName=false;
        event->ignore();
    }
    if (CheckRow&&CheckName)
    {

        ValueName();
        ValueProteins();
        ValueFats();
        ValueCarbohydrates();
        DialogEdit::close();
   }
}*/

void DialogEdit::on_Edit_clicked()
{
    bool CheckRow=true,CheckName=true;
    if ((ui->LineNumberEditRow->text().isEmpty()))
    {
        QMessageBox::warning(this,"Предупреждение.","Введите номер строки.");
        CheckRow=false;
    }
    laba6 laba6;
    int rows=laba6.NumbersOfRows();
    if ((((ui->LineNumberEditRow->text().toInt())>rows)||((ui->LineNumberEditRow->text().toInt())<1))&&CheckRow)
    {
        QMessageBox::warning(this,"Предупреждение.","Строки с таким номером нет.");
        CheckRow=false;
    }
    if ((ui->Name->text().isEmpty())&&CheckRow)
    {
        QMessageBox::warning(this,"Предупреждение.","Введите название продукта.");
        CheckName=false;
    }
    if (CheckRow&&CheckName)
    {
        ValueName();
        ValueProteins();
        ValueFats();
        ValueCarbohydrates();
        ui->label_6->setText("1");
        DialogEdit::close();
   }
}

void DialogEdit::on_Cancel_clicked()
{
    //ValueForEdit(false);
        DialogEdit::close();
}

