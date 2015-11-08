#include "mypoint.h"


MyPoint::MyPoint():QPoint()
{

}

MyPoint::MyPoint(int x , int y, QColor color) : QPoint(x, y)
{
    this->color_ = color;
}
QColor MyPoint::getColor(void)
{
    return this->color_;
}

