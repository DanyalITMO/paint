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
}

PaintWidget::~PaintWidget()
{

}

void PaintWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mDrawMode = true;
        mDrawBuffer.append(event->pos());
        event->accept();
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
    if (mDrawBuffer.size()<2) return;
    QPainter painter(this);
    painter.setPen(color_);
    QList<QPoint>::const_iterator it = mDrawBuffer.begin();
    QPoint start = *it;
    it++;
    while(it != mDrawBuffer.end()) {
        QPoint end = *it;
        painter.drawLine(start,end);
        start = end;
        it++;
    }
}

void PaintWidget::setColor(QColor color)
{
    this->color_ = color;
    std::cout<<"fdgfd"<<std::endl;
}
