#include "button.h"
#include<iostream>
#include<QPixmap>
#include<QWidget>
#include<QString>

Button::Button(const QString name, QWidget *parent):QPushButton(parent)
{
    //pcmdFlat = new QPushButton;
    this->setFlat(true);

    if(name == "C:\\colors\\green.png")
        this->color_ = Qt::green;

    if(name == "C:\\colors\\red.png")
        this->color_ = Qt::red;

    if(name == "C:\\colors\\blue.png")
        this->color_ = Qt::blue;

    if(name == "C:\\colors\\blue.png")
        this->color_ = Qt::gray;

     QPixmap pix(name);
     this->setIcon(pix);
     QSize size_i(50, 50);
     this->setIconSize(size_i);
     this->setFixedSize(size_i);
      /*QVBoxLayout* vLayout = new QVBoxLayout;
      vLayout->addWidget(this);
      setLayout(vLayout);*/
}
void Button::getColor()
{
    emit changeColor(color_);
}

