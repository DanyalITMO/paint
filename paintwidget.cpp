#include "paintwidget.h"

#include <QtCore/QLine>
#include <QtGui/QPainter>
#include <QtGui/QMouseEvent>
#include<iostream>

PaintWidget::PaintWidget(QWidget *parent)
    : QWidget(parent)
{
    mDrawMode = false;
    color_ = Qt::green;
    painter = new QPainter(this);

    mDrawBuffer.append(QPoint(0,0));

}

PaintWidget::~PaintWidget()
{

}

void PaintWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        mDrawMode = true;
        mDrawBuffer.append(event->pos());
        event->accept();
        //this->update();
       // event->ignore();
       // mDrawMode = false;

    }
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mDrawMode = false;
        mDrawBuffer.append(event->pos());
        this->update();
        event->accept();
    }
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (!mDrawMode) return;
    mDrawBuffer.append(event->pos());
    this->update();
    event->accept();
}

void PaintWidget::paintEvent(QPaintEvent *event)
{

    painter->begin(this);

    painter->setPen(color_);
    it = mDrawBuffer.begin();
    while(it != mDrawBuffer.end()) {
        painter->drawPoint(*it);
        it++;
    }
    painter->end();
}

void PaintWidget::setColor(QColor color)
{
    this->color_ = color;
    std::cout<<"fdgfd"<<std::endl;
}
