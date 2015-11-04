#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include<QString>
#include<QPushButton>
#include<QVBoxLayout>
#include<QColor>

class Button: public QPushButton
{
Q_OBJECT
        private:
        QColor color_;
public:
     Button(const QString, QWidget *parent = 0 );


public slots:
  void   getColor();
signals:
   void changeColor(QColor);

};

#endif // BUTTON_H
