#include "dialogremove.h"
#include "ui_dialogremove.h"
#include "laba6.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QValidator>

DialogRemove::DialogRemove(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRemove)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    ui->LineNumberRemoveRow->setValidator(new QRegExpValidator(QRegExp("^[0-9]{0,20}$\\d"), this));//задаем то,что можно вводить ^$-ограничивает выражение не забывать про них
}

DialogRemove::~DialogRemove()
{
    delete ui;
}
int DialogRemove::NumberRow()
{
     int LineNumberRemoveRow=ui->LineNumberRemoveRow->text().toInt();
     return LineNumberRemoveRow;
}
bool DialogRemove::ValueForRemove()
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
void DialogRemove::on_Remove_clicked()
{
    bool CheckRow=true;
    if ((ui->LineNumberRemoveRow->text().isEmpty()))
    {
        QMessageBox::warning(this,"Предупреждение.","Введите номер строки.");
        CheckRow=false;
    }
    laba6 laba6;
    int rows=laba6.NumbersOfRows();
    if ((((ui->LineNumberRemoveRow->text().toInt())>rows)||((ui->LineNumberRemoveRow->text().toInt())<1))&&CheckRow)
    {
        QMessageBox::warning(this,"Предупреждение.","Строки с таким номером нет.");
        CheckRow=false;
    }
    if (CheckRow)
    {
        ui->label_2->setText("1");
        DialogRemove::close();
    }
}

void DialogRemove::on_Cancel_clicked()
{
   DialogRemove::close();
}
