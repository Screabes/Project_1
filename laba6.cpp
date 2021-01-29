#include "laba6.h"
#include "ui_laba6.h"
#include "dialogadd.h"
#include "dialogremove.h"
#include "dialogedit.h"
#include "dialogsort.h"
#include <QFile>
#include <cstdlib>
#include <cstring>
#include <QMessageBox>
#include <QTextStream>
#include <iostream>
#include <QTextCodec>
#include <QComboBox>
#include <QStyleOptionViewItem>
#include<QAbstractItemView>



laba6::laba6(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::laba6)
{
    ui->setupUi(this);
    ui->RightTable->setColumnWidth(2,230);//устанавливаем размеры
    ui->Elements->setEditTriggers(QAbstractItemView::NoEditTriggers);//запрещаем редактирование таблиц
    ui->LeftTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->RightTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->RightTable->insertRow(0);//добавляем строки в табличку правую снизу
    ui->RightTable->insertRow(1);
    QFile file("D:\\ss\\laba6\\products.txt");
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        QTextStream in(&file);//чтобы можно на русском писать
        QString line = in.readLine();
        int CountRows=line.toInt();// переводим в инт
        while(!in.atEnd())//считываем весь файл
        {
        in.setCodec("Windows-1251");//UTF-8 Windows-1251
        //считываем первую строку с кол-вом строчек
        QStringList ListWithInformationAboutProducts;//тут храниться все с файла
        for (int i=0;i<CountRows*4;i++)
        {
            line = in.readLine();//считываем построчно из записываем в лист
            ListWithInformationAboutProducts<<line;
        }
     for (int i=0;i<CountRows;i++)
        {
            ui->Elements->insertRow(i);//перенос в таблицу из файла
            ui->Elements->setItem(i,0, new QTableWidgetItem((ListWithInformationAboutProducts[i*4])));//соответсвенно заносим значения навзваний из файла
        }
        for (int i=0;i<CountRows;i++)
        {
            ui->Elements->setItem(i,1,new QTableWidgetItem((ListWithInformationAboutProducts[i*4+1])));//соответсвенно заносим значения белков из файла
            }
        for (int i=0;i<CountRows;i++)
        {
            ui->Elements->setItem(i,2,new QTableWidgetItem((ListWithInformationAboutProducts[i*4+2])));//соответсвенно заносим значения жиров из файла
            }
        for (int i=0;i<CountRows;i++)
        {
            ui->Elements->setItem(i,3,new QTableWidgetItem((ListWithInformationAboutProducts[i*4+3])));//соответсвенно заносим значения углеводов из файла
            }
        file.close();
        }
    }
}

laba6::~laba6()
{
    delete ui;
}
void laba6::resizeEvent(QResizeEvent *)
{
     /// таблица филиалов
    ui->Elements->setColumnWidth(0, ui->Elements->width()/4);      // код
    ui->Elements->setColumnWidth(1, ui->Elements->width()/4);       // название филиала
    ui->Elements->setColumnWidth(2, ui->Elements->width()/4);
    ui->Elements->setColumnWidth(3, ui->Elements->width()/4);
    ui->LeftTable->setColumnWidth(0, ui->LeftTable->width()/4);      // код
    ui->LeftTable->setColumnWidth(1, ui->LeftTable->width()/4);       // название филиала
    ui->LeftTable->setColumnWidth(2, ui->LeftTable->width()/4);
    ui->LeftTable->setColumnWidth(3, ui->LeftTable->width()/4);// адрес филиала
    // адрес филиала
}
void laba6::Rewrite()//ф-ция перезаписывания в файл
{
    QFile file("D:\\ss\\laba6\\products.txt");
    if (file.open(QIODevice::WriteOnly| QIODevice::Text))//считывыем файл
    {
        QTextStream out(&file);//чтобы можно было вписывать
         out.setCodec(QTextCodec::codecForName("Windows-1251"));//UTF-8 Windows-1251
        int rows=ui->Elements->rowCount();//считываем кол-во строк
out <<rows<<"\n";
for (int i=0;i<rows;i++)//занос в файл
        {
            QString Name=ui->Elements->item(i,0)->text();//заносим  name в  элемент таблицы
            out <<Name<<"\n";
            QString Proteins=ui->Elements->item(i,1)->text();//заносим в i-й элемент массива соотв. характеристики
            out <<Proteins<<"\n";
            QString Fats=ui->Elements->item(i,2)->text();//заносим в i-й элемент массива соотв. характеристики
            out <<Fats<<"\n";
            QString Carbohydrates=ui->Elements->item(i,3)->text();//заносим в i-й элемент массива соотв. характеристики
            out <<Carbohydrates<<"\n";
}
    }
    file.close();

}
double laba6::AverageValue(Product products[],int rows)
{
    double value=SummFats(products,rows)/rows;
    return value;
}

int laba6::SummProteins(Product products[],int rows)//принимаем структуру для суммы и кол-во строк для определния кол-ва элементов
{
    int summ;//сумма для занесения в ячейку
    int temp=0;//временно храним сумму в инт
    for (int i=0;i<rows;i++)
    {
        temp+=products[i].Proteins;
    }
    return temp;
}
int laba6::SummFats(Product products[],int rows)//принимаем структуру для суммы и кол-во строк для определния кол-ва элементов
{
    int summ;//сумма для занесения в ячейку
    int temp=0;//временно храним сумму в инт
    for (int i=0;i<rows;i++)
    {
        temp+=products[i].Fats;
    }
    return temp;
}
int laba6::SummCarbohydrates(Product products[],int rows)//принимаем структуру для суммы и кол-во строк для определния кол-ва элементов
{
    int summ;//сумма для занесения в ячейку
    int temp=0;//временно храним сумму в инт
    for (int i=0;i<rows;i++)
    {
        temp+=products[i].Carbohydrates;
    }
    return temp;
}
Product laba6::Fillproducts(int row)
{
    int rows=ui->Elements->rowCount();//считываем кол-во строк
  Product products[rows];//создаем массив с продуктами
     for(int i=0;i<rows;i++)
     {
         products[i].Name=ui->Elements->item(i,0)->text();//заносим в i-й элемент массива соотв. характеристики
         products[i].Proteins=ui->Elements->item(i,1)->text().toInt();//заносим в i-й элемент массива соотв. характеристики
         products[i].Fats=ui->Elements->item(i,2)->text().toInt();//заносим в i-й элемент массива соотв. характеристики
         products[i].Carbohydrates=ui->Elements->item(i,3)->text().toInt();//заносим в i-й элемент массива соотв. характеристики
     }
     return products[row];
}
int laba6::NumbersOfRows()
{
   int i =(ui->Elements->rowCount());//maybe need -1!
   return i;
}
QString laba6::ValueProteinsForEdit(int row)
{
    row=row-1;
    QString i=ui->Elements->item(row,1)->text();
    return i;
}
QString laba6::ValueFatsForEdit(int row)
{
    row=row-1;
    QString i=ui->Elements->item(row,2)->text();
    return i;
}
QString laba6::ValueCarbohydratesForEdit(int row)
{
    row=row-1;
    QString i=ui->Elements->item(row,3)->text();
    return i;
}

void laba6::on_Add_clicked()
{
    DialogAdd dialogadd;//форма новая
    dialogadd.exec();	 	// вызов формы для отображения.
    if ((dialogadd.ValueForAdd()/*(!)если?-см.вызов*/))
    {
                int i= ui->Elements->rowCount();
                ui->Elements->insertRow(i);//добавляем строку
                ui->Elements->setItem(i,0,new QTableWidgetItem(dialogadd.ValueName()));//соответсвенно заносим значения из диалогового окна
                ui->Elements->setItem(i,1,new QTableWidgetItem(dialogadd.ValueProteins()));
                ui->Elements->setItem(i,2,new QTableWidgetItem(dialogadd.ValueFats()));
                ui->Elements->setItem(i,3,new QTableWidgetItem(dialogadd.ValueCarbohydrates()));
                Rewrite();//перезапись файла
    }
}

void laba6::on_Remove_clicked()//подключаем форму для удаления
{
    DialogRemove dialogremove;//форма новая
    dialogremove.exec();
    if (dialogremove.ValueForRemove())
    {
        ui->Elements->removeRow(dialogremove.NumberRow()-1);//удаляем соотв. строку
        Rewrite();//перезапись файла
    }
}

void laba6::on_Edit_clicked()//подключаем форму для редактирования
{
 DialogEdit dialogedit;
 dialogedit.exec();
 if (dialogedit.ValueForEdit())
 {
int i=dialogedit.NumberRow()-1;

ui->Elements->setItem(i,0,new QTableWidgetItem(dialogedit.ValueName()));//соответсвенно заносим значения из диалогового окна
ui->Elements->setItem(i,1,new QTableWidgetItem(dialogedit.ValueProteins()));
ui->Elements->setItem(i,2,new QTableWidgetItem(dialogedit.ValueFats()));
ui->Elements->setItem(i,3,new QTableWidgetItem(dialogedit.ValueCarbohydrates()));
Rewrite();//перезапись файла
 }
}

void laba6::on_Sort_clicked()//кнопка для сортировки
{
    bool CheckRows=true;      //првоерка на ноль строк
    int rows=ui->Elements->rowCount();//считываем кол-во строк
    if (rows==0)
    {
        QMessageBox::warning(this,"Предупреждение.","Добавьте продукт");
         CheckRows=false;
    }
    else
    {
       CheckRows=true;
    }
    if (CheckRows)
    {
        DialogSort dialogsort;
        dialogsort.exec();
        if (dialogsort.ValueForSort())
        {
        ui->RightTable->clearContents();
        ui->LeftTable->clearContents();
    for (int i=0;i<rows+2;i++)
    {
        ui->LeftTable->removeRow(i);//чистим нижние таблицы для записи актулаьной инфы
        ui->LeftTable->removeRow(rows-i);//чистим нижние таблицы для записи актулаьной инфы
    }
  Product products[rows];//создаем массив с продуктами
     for(int i=0;i<rows;i++)
     {
         products[i].Name=ui->Elements->item(i,0)->text();//заносим в i-й элемент массива соотв. характеристики
         int Proteins=ui->Elements->item(i,1)->text().toInt();//заносим в i-й элемент массива соотв. характеристики
         products[i].Proteins=Proteins;
         int Fats=ui->Elements->item(i,2)->text().toInt();//заносим в i-й элемент массива соотв. характеристики
         products[i].Fats=Fats;
         int Carbohydrates=ui->Elements->item(i,3)->text().toInt();//заносим в i-й элемент массива соотв. характеристики
         products[i].Carbohydrates=Carbohydrates;
     }
     //max belkov
     Product tmp;
     for (int i=rows-1;i>=0;i--)//0-min 9rows-1)-max elmnt
       {
           for (int j = 0; j<i; j++)
           {
               // сравниваем элементы массива структур по кол-ву белков
               if (products[j].Proteins>products[j+1].Proteins)
               {
                    tmp = products[j];
                   products[j] = products[j+1];
                   products[j+1] =tmp;
               }
           }
       }
     ui->RightTable->setItem(0,0,new QTableWidgetItem(QString(products[rows-1].Name)));// выставляем значение Имени max белков
     ui->RightTable->setItem(1,0,new QTableWidgetItem(QString::number(products[rows-1].Proteins)));// выставляем значение max белков
     //min углеводов
     for (int i=rows-1;i>=0;i--)//0-min 9rows-1)-max elmnt
       {
           for (int j = 0; j<i; j++)
           {
               // сравниваем элементы массива структур по кол-ву ууглеводов
               if (products[j].Carbohydrates<products[j+1].Carbohydrates)
               {
                    tmp = products[j];
                   products[j] = products[j+1];
                   products[j+1] =tmp;
               }
           }
       }
     ui->RightTable->setItem(0,1,new QTableWidgetItem(QString(products[rows-1].Name)));// выставляем значение имени min углеовдов
     ui->RightTable->setItem(1,1,new QTableWidgetItem(QString::number(products[rows-1].Carbohydrates)));// выставляем значение min углеовдов
     ui->RightTable->setItem(0,2,new QTableWidgetItem(QString::number(AverageValue(products,rows),'f', 3)));// выставляем значение средней величины жиров
     ui->RightTable->setItem(0,3,new QTableWidgetItem(QString::number(SummProteins(products,rows))));// summ белков
     ui->RightTable->setItem(0,4,new QTableWidgetItem(QString::number(SummFats(products,rows))));//summ жиров
     ui->RightTable->setItem(0,5,new QTableWidgetItem(QString::number(SummCarbohydrates(products,rows))));//summ углеводов
// в зависимости от выбранного типа сортировки в радиобаттон идут различне исходы
     if (dialogsort.StateButtonName()==true)//SortByName
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));
    QString A,B;
    char* StrA;
    char* StrB;
    Product Elements[rows];
    for (int i=0;i<rows;i++)
    {
    Elements[i]=Fillproducts(i);//заполняем массив элементами с верхней таблицы
    }
    for (int i=0;i<rows-1;i++) //соритруем по именам
    {
         A=Elements[i].Name;
        QByteArray temp = A.toLocal8Bit();//переносим строку в массив char
         StrA=temp.data();
         B=Elements[i+1].Name;
         temp = B.toLocal8Bit();//переносим строку в массив char
         StrB=temp.data();
        if((qstrcmp(StrA,StrB)==1))// если первый элемент больше второго,1-й элемент-max конечный-min
        {
            swap(Elements[i].Name,Elements[i+1].Name);//меняем местами элементы
        }

    }
    for (int k=0;k<rows;k++)//заносим в левую таблицу отсортированную
    {
        ui->LeftTable->insertRow(k);
        ui->LeftTable->setItem(k,0,new QTableWidgetItem((Elements[k].Name)));
        ui->LeftTable->setItem(k,1,new QTableWidgetItem(QString::number(Elements[k].Proteins)));//ДЛЯ ЗАНОСА INT В ЯЧЕЙКИ ТАК ИНАЧЕ ПУСТОТА БУДЕТ
        ui->LeftTable->setItem(k,2,new QTableWidgetItem(QString::number(Elements[k].Fats)));
        ui->LeftTable->setItem(k,3,new QTableWidgetItem(QString::number(Elements[k].Carbohydrates)));
    }

}
else if (dialogsort.StateButtonProteins()==true)//SortByProteins
{
         Product Elements[rows];
         for (int i=0;i<rows;i++)
         {
         Elements[i]=Fillproducts(i);//заполняем массив элементами с верхней таблицы
         }
         Product tmp;
         for (int i=rows-1;i>=0;i--)//0-min 9rows-1)-max elmnt
           {
               for (int j = 0; j<i; j++)
               {
                   // сравниваем элементы массива структур по кол-ву белков
                   if (Elements[j].Proteins<Elements[j+1].Proteins)
                   {
                        tmp = Elements[j];
                       Elements[j] = Elements[j+1];
                       Elements[j+1] =tmp;
                   }
               }
           }
         for (int k=0;k<rows;k++)//заносим в левую таблицу отсортированную
         {
             ui->LeftTable->insertRow(k);
             ui->LeftTable->setItem(k,0,new QTableWidgetItem((Elements[k].Name)));
             ui->LeftTable->setItem(k,1,new QTableWidgetItem(QString::number(Elements[k].Proteins)));//ДЛЯ ЗАНОСА INT В ЯЧЕЙКИ ТАК ИНАЧЕ ПУСТОТА БУДЕТ
             ui->LeftTable->setItem(k,2,new QTableWidgetItem(QString::number(Elements[k].Fats)));
             ui->LeftTable->setItem(k,3,new QTableWidgetItem(QString::number(Elements[k].Carbohydrates)));
         }
}
else if (dialogsort.StateButtonFats()==true)//SortByFats
{
         Product Elements[rows];
         for (int i=0;i<rows;i++)
         {
         Elements[i]=Fillproducts(i);//заполняем массив элементами с верхней таблицы
         }
         Product tmp;
         for (int i=rows-1;i>=0;i--)//0-min 9rows-1)-max elmnt
           {
               for (int j = 0; j<i; j++)
               {
                   // сравниваем элементы массива структур по кол-ву белков
                   if (Elements[j].Fats>Elements[j+1].Fats)
                   {
                        tmp = Elements[j];
                       Elements[j] = Elements[j+1];
                       Elements[j+1] =tmp;
                   }
               }
           }
         for (int k=0;k<rows;k++)//заносим в левую таблицу отсортированную
         {
             ui->LeftTable->insertRow(k);
             ui->LeftTable->setItem(k,0,new QTableWidgetItem((Elements[k].Name)));
             ui->LeftTable->setItem(k,1,new QTableWidgetItem(QString::number(Elements[k].Proteins)));//ДЛЯ ЗАНОСА INT В ЯЧЕЙКИ ТАК ИНАЧЕ ПУСТОТА БУДЕТ
             ui->LeftTable->setItem(k,2,new QTableWidgetItem(QString::number(Elements[k].Fats)));
             ui->LeftTable->setItem(k,3,new QTableWidgetItem(QString::number(Elements[k].Carbohydrates)));
         }
}
else if (dialogsort.StateButtonCarbohydrates()==true)//SortByCarbohydrates
{
         Product Elements[rows];
         for (int i=0;i<rows;i++)
         {
         Elements[i]=Fillproducts(i);//заполняем массив элементами с верхней таблицы
         }
         Product tmp;
         for (int i=rows-1;i>=0;i--)//0-min 9rows-1)-max elmnt
           {
               for (int j = 0; j<i; j++)
               {
                   // сравниваем элементы массива структур по кол-ву белков
                   if (Elements[j].Carbohydrates>Elements[j+1].Carbohydrates)
                   {
                        tmp = Elements[j];
                       Elements[j] = Elements[j+1];
                       Elements[j+1] =tmp;
                   }
               }
           }
         for (int k=0;k<rows;k++)//заносим в левую таблицу отсортированную
         {
             ui->LeftTable->insertRow(k);
             ui->LeftTable->setItem(k,0,new QTableWidgetItem((Elements[k].Name)));
             ui->LeftTable->setItem(k,1,new QTableWidgetItem(QString::number(Elements[k].Proteins)));//ДЛЯ ЗАНОСА INT В ЯЧЕЙКИ ТАК ИНАЧЕ ПУСТОТА БУДЕТ
             ui->LeftTable->setItem(k,2,new QTableWidgetItem(QString::number(Elements[k].Fats)));
             ui->LeftTable->setItem(k,3,new QTableWidgetItem(QString::number(Elements[k].Carbohydrates)));
         }
}
     //ДОБАВВВВВВВВВВВВВВВЬ ПРОВЕРКУ НА НАЖАТИЕ РАДИО КНОПОК ИНАЧЧЕ ЭТОТ МАСССИВ НЕ СОЗДАТСЯ и все крашнется т.к нечего будет заносить в массив
     Product SortedElements[rows];//создаем массив с продуктами
        for(int i=0;i<rows;i++)
        {
            SortedElements[i].Name=ui->LeftTable->item(i,0)->text();//заносим в i-й элемент массива соотв. характеристики
            SortedElements[i].Proteins=ui->LeftTable->item(i,1)->text().toInt();;
            SortedElements[i].Fats=ui->LeftTable->item(i,2)->text().toInt();;
            SortedElements[i].Carbohydrates=ui->LeftTable->item(i,3)->text().toInt();
        }
        //если надо больше каого-то значения
        if (dialogsort.Index1())
        {
     if((dialogsort.ButtonProteins())&&(!dialogsort.ButtonFats())&&(!dialogsort.ButtonCarbohydrates()))
     {
         QFont font;//сравниваем и красим
         for (int i=0;i<rows;i++)
         {
             if (SortedElements[i].Proteins>dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,1)->setFont(font);
             }
         }
     }
     if((!dialogsort.ButtonProteins())&&(dialogsort.ButtonFats())&&(!dialogsort.ButtonCarbohydrates()))
     {
         QFont font;//сравниваем и красим
         for (int i=0;i<rows;i++)
         {
             if (SortedElements[i].Fats>dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,2)->setFont(font);
             }
         }
     }

     if((!dialogsort.ButtonProteins())&&(!dialogsort.ButtonFats())&&(dialogsort.ButtonCarbohydrates()))
     {
         QFont font;//сравниваем и красим
         for (int i=0;i<rows;i++)
         {
             if (SortedElements[i].Carbohydrates>dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,3)->setFont(font);
             }
         }
     }
     if((dialogsort.ButtonProteins())&&(dialogsort.ButtonFats())&&(!dialogsort.ButtonCarbohydrates()))
     {
         QFont font;//сравниваем и красим
         for (int i=0;i<rows;i++)
         {
             if (SortedElements[i].Proteins>dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,1)->setFont(font);
             }
             if (SortedElements[i].Fats>dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,2)->setFont(font);
             }
         }
     }
     if((dialogsort.ButtonProteins())&&(!dialogsort.ButtonFats())&&(dialogsort.ButtonCarbohydrates()))
     {
         QFont font;//сравниваем и красим
         for (int i=0;i<rows;i++)
         {
             if (SortedElements[i].Proteins>dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,1)->setFont(font);
             }
             if (SortedElements[i].Carbohydrates>dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,3)->setFont(font);
             }
         }
     }
     if((!dialogsort.ButtonProteins())&&(dialogsort.ButtonFats())&&(dialogsort.ButtonCarbohydrates()))
     {
         QFont font;//сравниваем и красим
         for (int i=0;i<rows;i++)
         {
             if (SortedElements[i].Fats>dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,2)->setFont(font);
             }
             if (SortedElements[i].Carbohydrates>dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,3)->setFont(font);
             }
         }
     }
     if((dialogsort.ButtonProteins())&&(dialogsort.ButtonFats())&&(dialogsort.ButtonCarbohydrates()))
     {
         QFont font;//сравниваем и красим
         for (int i=0;i<rows;i++)
         {
             if (SortedElements[i].Proteins>dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,1)->setFont(font);
             }
             if (SortedElements[i].Fats>dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,2)->setFont(font);
             }
             if (SortedElements[i].Carbohydrates>dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,3)->setFont(font);
             }
         }
     }
        }
        //если надо меньше какго-то значения
        if (dialogsort.Index2())
        {
     if((dialogsort.ButtonProteins())&&(!dialogsort.ButtonFats())&&(!dialogsort.ButtonCarbohydrates()))
     {
         QFont font;//сравниваем и красим
         for (int i=0;i<rows;i++)
         {
             if (SortedElements[i].Proteins<dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,1)->setFont(font);
             }
         }
     }
     if((!dialogsort.ButtonProteins())&&(dialogsort.ButtonFats())&&(!dialogsort.ButtonCarbohydrates()))
     {
         QFont font;//сравниваем и красим
         for (int i=0;i<rows;i++)
         {
             if (SortedElements[i].Fats<dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,2)->setFont(font);
             }
         }
     }

     if((!dialogsort.ButtonProteins())&&(!dialogsort.ButtonFats())&&(dialogsort.ButtonCarbohydrates()))
     {
         QFont font;//сравниваем и красим
         for (int i=0;i<rows;i++)
         {
             if (SortedElements[i].Carbohydrates<dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,3)->setFont(font);
             }
         }
     }
     if((dialogsort.ButtonProteins())&&(dialogsort.ButtonFats())&&(!dialogsort.ButtonCarbohydrates()))
     {
         QFont font;//сравниваем и красим
         for (int i=0;i<rows;i++)
         {
             if (SortedElements[i].Proteins<dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,1)->setFont(font);
             }
             if (SortedElements[i].Fats>dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,2)->setFont(font);
             }
         }
     }
     if((dialogsort.ButtonProteins())&&(!dialogsort.ButtonFats())&&(dialogsort.ButtonCarbohydrates()))
     {
         QFont font;//сравниваем и красим
         for (int i=0;i<rows;i++)
         {
             if (SortedElements[i].Proteins<dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,1)->setFont(font);
             }
             if (SortedElements[i].Carbohydrates<dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,3)->setFont(font);
             }
         }
     }
     if((!dialogsort.ButtonProteins())&&(dialogsort.ButtonFats())&&(dialogsort.ButtonCarbohydrates()))
     {
         QFont font;//сравниваем и красим
         for (int i=0;i<rows;i++)
         {
             if (SortedElements[i].Fats<dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,2)->setFont(font);
             }
             if (SortedElements[i].Carbohydrates<dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,3)->setFont(font);
             }
         }
     }
     if((dialogsort.ButtonProteins())&&(dialogsort.ButtonFats())&&(dialogsort.ButtonCarbohydrates()))
     {
         QFont font;//сравниваем и красим
         for (int i=0;i<rows;i++)
         {
             if (SortedElements[i].Proteins<dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,1)->setFont(font);
             }
             if (SortedElements[i].Fats<dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,2)->setFont(font);
             }
             if (SortedElements[i].Carbohydrates<dialogsort.Number())
             {
                 font.setBold(true);
                 ui->LeftTable->item(i,3)->setFont(font);
             }
         }
     }
        }
}







    }
}

