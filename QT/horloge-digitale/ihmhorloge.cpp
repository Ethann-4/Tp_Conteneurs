#include "ihmhorloge.h"
#include "horlogedigitale.h"
#include <QDebug>

#define PERIODE 1000   // 1 seconde (ms)

IHMHorloge::IHMHorloge(QWidget *parent) : QWidget(parent)
{
    // Les widgets
    horloge = new HorlogeDigitale(this);
    editionHeure = new QTimeEdit(QTime::currentTime(), this);
    editionHeure->setDisplayFormat("HH:mm:ss");

    boutonReglage = new QPushButton("Régler");
    boutonReglage->setDefault(true);

    actionQuitter = new QAction("&Quitter", this);
    actionQuitter->setShortcut(QKeySequence(QKeySequence::Quit)); // Ctrl+Q
    addAction(actionQuitter);

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(horloge);
    layoutPrincipal->addWidget(editionHeure);
    layoutPrincipal->addWidget(boutonReglage);
    setLayout(layoutPrincipal);

    // Connexions signaux
    connect(this, SIGNAL(depart(int)), horloge, SLOT(demarrer(int)));
    connect(this, SIGNAL(arret()), horloge, SLOT(arreter()));
    connect(boutonReglage, SIGNAL(clicked()), this, SLOT(regler()));
    connect(actionQuitter, SIGNAL(triggered()), this, SLOT(quitter()));

    setWindowTitle("Horloge digitale");
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    setContextMenuPolicy(Qt::ActionsContextMenu);

    // Initialisation
    horloge->fixer(editionHeure->time().hour(),
                   editionHeure->time().minute(),
                   editionHeure->time().second());  // secondes initiales
    emit depart(PERIODE);
}

IHMHorloge::~IHMHorloge()
{
    emit arret();
    qDebug() << "~IHMHorloge()";
}

void IHMHorloge::regler()
{
    emit arret(); // arrêt de l’horloge

    int heures   = editionHeure->time().hour();
    int minutes  = editionHeure->time().minute();
    int secondes = editionHeure->time().second();  // On récupère aussi les secondes
    horloge->fixer(heures, minutes, secondes);

    emit depart(PERIODE); // redémarrage
}


void IHMHorloge::quitter()
{
    close();
}


