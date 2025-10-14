#ifndef GENERATEURCODEBARRE_H
#define GENERATEURCODEBARRE_H

#include <QWidget>
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include <QVector>
#include <QString>

class GenerateurCodeBarre : public QWidget
{
    Q_OBJECT

public:
    explicit GenerateurCodeBarre(QWidget *parent = 0);
    void dessiner(const QString &code);
    void imprimer();
    void paintEvent(QPaintEvent *event) ;

private:
    QString codeCourant;
    void dessinerCode39(QPainter *painter, const QString &code);
};

#endif // GENERATEURCODEBARRE_H
