#include "generateurcodebarre.h"
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QDebug>

GenerateurCodeBarre::GenerateurCodeBarre(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(400, 150);
}

// Met à jour le code à afficher et redessine
void GenerateurCodeBarre::dessiner(const QString &code)
{
    codeCourant = code.trimmed();
    update(); // demande un repaint
}

// Impression réelle
void GenerateurCodeBarre::imprimer()
{
    if (codeCourant.isEmpty())
        return;

    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    dialog.setWindowTitle(tr("Impression du code-barre"));

    if (dialog.exec() == QDialog::Accepted) {
        QPainter painter(&printer);
        dessinerCode39(&painter, codeCourant);
    }
}

// Dessin dans la fenêtre
void GenerateurCodeBarre::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    dessinerCode39(&painter, codeCourant);
}

// --- Fonction principale de dessin du code 39 ---
void GenerateurCodeBarre::dessinerCode39(QPainter *painter, const QString &code)
{
    if (code.isEmpty())
        return;


    static const int tableSymboles[44] = {
        0x034,0x121,0x061,0x160,0x031,0x130,0x070,
        0x025,0x124,0x064,0x109,0x049,0x148,0x019,
        0x118,0x058,0x00d,0x10c,0x04c,0x01c,0x103,
        0x043,0x142,0x013,0x112,0x052,0x007,0x106,
        0x046,0x016,0x181,0x0c1,0x1c0,0x091,0x190,
        0x0d0,0x085,0x184,0x0c4,0x094,0x0a8,0x0a2,
        0x08a,0x02a
    };

    QString caracteres = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ-. $/+%*";
    QString texte = "*" + code.toUpper() + "*";

    QPen pen(Qt::black);
    painter->setPen(pen);
    painter->setBrush(QBrush(Qt::black));

    int x = 20;
    int y = 20;
    int hauteur = 80;
    int barreFine = 2;
    int barreEpaisse = 5;
    int espace = 1;

    // Pour chaque caractère du code
    for (const QChar &ch : texte) {
        int idx = caracteres.indexOf(ch);
        if (idx < 0) continue;

        int pattern = tableSymboles[idx];

        // 9 bits par caractère
        for (int i = 8; i >= 0; --i) {
            bool bit = pattern & (1 << i);
            int largeur = bit ? barreEpaisse : barreFine;

            if ((8 - i) % 2 == 0) {
                // barre noire
                painter->fillRect(x, y, largeur, hauteur, Qt::black);
            }
            // sinon espace blanc
            x += largeur;
        }
        // espace inter-caractère
        x += espace * 4;
    }

    // Texte sous le code-barre
    QFont font("Verdana", 10);
    painter->setFont(font);
    painter->drawText(0, y + hauteur + 15, width(), 20, Qt::AlignCenter, code);
}
