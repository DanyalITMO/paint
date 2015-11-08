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
        m_draw_buffer.append(event->pos());
         counter_++;
        event->accept();
        //this->update();
       // event->ignore();
       // mDrawMode = false;

    }
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        //m_draw_buffer.append(event->pos());
         counter_++;
        mDrawMode = false;
        m_draw_buffer.append(QPoint(0, 0));

        this->update();

        //event->accept();
    }
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (!mDrawMode) return;
    m_draw_buffer.append(event->pos());
    counter_++;
    this->update();
    event->accept();
}


void PaintWidget::paintEvent(QPaintEvent *event)
{
    if (m_draw_buffer.size()<2) return;
    QPainter painter(this);
    painter.setPen(color_);
    QList<QPoint>::iterator it = m_draw_buffer.begin();

    QPoint start = *it;
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

            QPoint end = *it;
            painter.drawLine(start,end);
            start = end;
            it++;
        }


}

void PaintWidget::setColor(QColor color)
{
    this->color_ = color;
}
