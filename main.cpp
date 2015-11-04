#include<QApplication>
#include<QWidget>
#include<QHBoxLayout>
#include<QPushButton>
#include<QString>
#include<iostream>
#include<QVector>
#include<QColor>


#include "paintwidget.h"
#include"button.h"

#define COLOR_NUMBER 4
int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   QWidget wgt;
   PaintWidget paint_w;

   QString color_name[] = {"C:\\colors\\red.png", "C:\\colors\\green.png", "C:\\colors\\blue.png", "C:\\colors\\gray.png"};
   QVector <Button*> vec_button;
   QVBoxLayout* layout = new QVBoxLayout;

    for(int i = 0; i < COLOR_NUMBER; i++)
     {
      vec_button.push_back(new Button(color_name[i]));
      layout->addWidget(vec_button[i]);
     }

   QHBoxLayout* main_layout = new QHBoxLayout;

   main_layout->addLayout(layout, 1);
   main_layout->addWidget(&paint_w, 10);

   for(int i = 0; i < COLOR_NUMBER; i++)
    {
        QObject::connect(vec_button[i],  SIGNAL(clicked()), vec_button[i], SLOT(getColor()));
        QObject::connect(vec_button[i], SIGNAL(changeColor(QColor)), &paint_w, SLOT(setColor(QColor)));
    }

   wgt.setLayout(main_layout);

   wgt.show();
    return a.exec();
}

