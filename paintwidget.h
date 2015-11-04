#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QList>
#include <QPoint>
#include<QColor>
class PaintWidget : public QWidget
{
    Q_OBJECT
    QColor color_;
public:
    PaintWidget(QWidget *parent = 0);

    ~PaintWidget();

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);
private:
    QList<QPoint> mDrawBuffer;
    bool mDrawMode;
public slots:
    void setColor(QColor );
};

#endif // PAINTWIDGET_H
