#include "mywidget.h"
#include <QDebug>
#include <QString>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    lcd->setSegmentStyle(QLCDNumber::Outline);
    s->setValue(255);

    connect(s, SIGNAL(valueChanged(int)), this, SLOT(Slider(int)));
    connect(lineEdit, SIGNAL(editingFinished()), this, SLOT(LineEdit()));
}

MyWidget::~MyWidget()
{
}

void MyWidget::LineEdit()
{
    bool ok;
    int val = lineEdit->text().toInt(&ok);
    s->setValue(val);
}

void MyWidget::Slider(int val)
{
    lineEdit->setText(QString::number(val));
}
