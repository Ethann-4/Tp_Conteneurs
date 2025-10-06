#include "horlogedigitale.h"
#include <QString>
#include <QDebug>

HorlogeDigitale::HorlogeDigitale(QWidget *parent) : QLCDNumber(parent)
{
    m_valeur = 0;
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(tic()));

#if QT_VERSION >= 0x050000
    setDigitCount(8); // HH:mm:ss
#else
    setNumDigits(8);
#endif
    setSegmentStyle(QLCDNumber::Filled);
    setFixedSize(this->width()*1.5, this->height()*1.5);
}

HorlogeDigitale::~HorlogeDigitale()
{
    qDebug() << "~HorlogeDigitale()";
}

long HorlogeDigitale::getSeconde()
{
    return (m_valeur % 600) / 10;
}

long HorlogeDigitale::getMinute()
{
    return (m_valeur % 36000) / 600;
}

long HorlogeDigitale::getHeure()
{
    return m_valeur / 36000;
}

void HorlogeDigitale::fixer(int h, int m, int s)
{
    m_valeur = h * 36000 + m * 600 + s * 10; // conversion en dixièmes
}

void HorlogeDigitale::update()
{
    QString heure, minute, seconde;

    heure = QString("%1").arg(getHeure(), 2, 10, QChar('0'));
    minute = QString("%1").arg(getMinute(), 2, 10, QChar('0'));
    seconde = QString("%1").arg(getSeconde(), 2, 10, QChar('0'));

    QString text = heure + ":" + minute + ":" + seconde;
    display(text);
}

void HorlogeDigitale::tic()
{
    m_valeur++; // chaque PERIODE = 100ms
    update();
}

void HorlogeDigitale::demarrer(int top)
{
    qDebug() << "HorlogeDigitale::demarrer()";
    m_timer->start(top);
}

void HorlogeDigitale::arreter()
{
    m_timer->stop();
    qDebug() << "HorlogeDigitale::arreter()";
}
