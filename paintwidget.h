#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QList>
#include <QPoint>
#include<QColor>
#include<QPainter>

#include "mypoint.h"
class PaintWidget : public QWidget
{
    Q_OBJECT

public:
    PaintWidget(QWidget *parent = 0);

    ~PaintWidget();

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);
private:
    QColor color_;
    QList<MyPoint> m_draw_buffer;
    QList<MyPoint> line_list_;
    unsigned int counter_;

    bool mDrawMode;

    QPoint end_position_;
public slots:
    void setColor(QColor);
    QColor getColor(void);
};

#endif // PAINTWIDGET_H
