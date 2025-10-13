#include "mydialog.h"
#include "generateurcodebarre.h"

MyDialog::MyDialog(QWidget *parent) : QDialog(parent)
{
    valeur = new QLabel("Code barre :", this);
    codebarre = new QLineEdit(this);
    bGenerer = new QPushButton("Générer", this);
    bImprimer = new QPushButton("Imprimer", this);
    bQuitter = new QPushButton("Quitter", this);

    intValidator = new QIntValidator(0, 9999999, this);
    codebarre->setValidator(intValidator);

    generateurCodeBarre = new GenerateurCodeBarre(this);

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    QHBoxLayout *layoutCode = new QHBoxLayout;
    layoutCode->addWidget(valeur);
    layoutCode->addWidget(codebarre);

    QHBoxLayout *layoutBoutons = new QHBoxLayout;
    layoutBoutons->addWidget(bGenerer);
    layoutBoutons->addWidget(bImprimer);
    layoutBoutons->addWidget(bQuitter);

    layoutPrincipal->addLayout(layoutCode);
    layoutPrincipal->addWidget(generateurCodeBarre);
    layoutPrincipal->addLayout(layoutBoutons);

    setLayout(layoutPrincipal);
    setWindowTitle(tr("TP Code-barre"));
    resize(500, 300);

    connect(bGenerer, &QPushButton::clicked, this, &MyDialog::generer);
    connect(bImprimer, &QPushButton::clicked, this, &MyDialog::imprimer);
    connect(bQuitter, &QPushButton::clicked, this, &QDialog::close);
}

void MyDialog::generer()
{
    QString texte = codebarre->text();
    if (texte.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir un code-barre !");
        return;
    }
    generateurCodeBarre->dessiner(texte);
}

void MyDialog::imprimer()
{
    generateurCodeBarre->imprimer();
}
