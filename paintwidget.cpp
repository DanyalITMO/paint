#include "paintwidget.h"

#include <QtCore/QLine>
#include <QtGui/QPainter>
#include <QtGui/QMouseEvent>

#include<algorithm>
#include<iostream>
#include<QDebug>

PaintWidget::PaintWidget(QWidget *parent)
    : QWidget(parent)
{
    mDrawMode = false;
    color_ = Qt::green;
    counter_ = 0;


}

PaintWidget::~PaintWidget()
{

}

void PaintWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        mDrawMode = true;
        m_draw_buffer.append(MyPoint(event->pos().x(), event->pos().y(), color_));
        counter_++;
        event->accept();

    }
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        counter_++;
        mDrawMode = false;
        m_draw_buffer.append(MyPoint(0, 0, color_));
        this->update();
    }
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (!mDrawMode) return;
    m_draw_buffer.append(MyPoint(event->pos().x(), event->pos().y(), color_));
    counter_++;
    this->update();
    event->accept();
}


void PaintWidget::paintEvent(QPaintEvent *event)
{
    if (m_draw_buffer.size()<2) return;
    QPainter painter(this);
    painter.setPen(color_);
    QList<MyPoint>::iterator it = m_draw_buffer.begin();

    MyPoint start = *it;
    it++;


        while(it != m_draw_buffer.end())
        {
            if(it->x() == 0 && it->y() == 0)
            {
                if(counter_ - std::distance(m_draw_buffer.begin(), it) - 1 > 0)
                {
                    it++;
                    start = *it;
                }
                else
                {
                    break;
                }


            }

            MyPoint end = *it;

            painter.setPen(start.getColor());
            painter.drawLine(start,end);
            start = end;
            it++;
        }


}

void PaintWidget::setColor(QColor color)
{
    this->color_ = color;
}

QColor PaintWidget::getColor(void)
{
    return this->color_;
}
