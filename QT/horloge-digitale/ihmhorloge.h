#ifndef IHMHORLOGE_H
#define IHMHORLOGE_H

#include <QWidget>
#include <QPushButton>
#include <QTimeEdit>
#include <QAction>
#include <QVBoxLayout>
#include <QContextMenuEvent>

class HorlogeDigitale;

class IHMHorloge : public QWidget
{
    Q_OBJECT

private:
    // les widgets
    QPushButton *boutonReglage;
    HorlogeDigitale *horloge;
    QTimeEdit *editionHeure;

    // action quitter
    QAction *actionQuitter;

public:
    IHMHorloge(QWidget *parent = nullptr);
    ~IHMHorloge();

private slots:
    void regler();
    void quitter();

signals:
    void depart(int);
    void arret();
};

#endif // IHMHORLOGE_H
