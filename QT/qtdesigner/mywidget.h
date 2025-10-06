#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "ui_mywidget.h"

class MyWidget : public QWidget, public Ui::MyWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

public slots:
    void LineEdit();
    void Slider(int val);
};

#endif // MYWIDGET_H



