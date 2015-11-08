#ifndef MYPOINT_H
#define MYPOINT_H

#include<QPoint>
#include<QColor>

class MyPoint: public QPoint
{
public:
    MyPoint();
    MyPoint(int x, int y, QColor );
    QColor getColor(void);
private:
    QColor color_;

};

#endif // MYPOINT_H
