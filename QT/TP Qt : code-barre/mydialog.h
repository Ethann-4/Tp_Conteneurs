#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QMessageBox>

#include "generateurcodebarre.h"

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = nullptr);

private:
    QLineEdit *codebarre;
    QLabel *valeur;
    QPushButton *bGenerer;
    QPushButton *bImprimer;
    QPushButton *bQuitter;

    QIntValidator *intValidator;
    GenerateurCodeBarre *generateurCodeBarre;

private slots:
    void generer();
    void imprimer();
};

#endif // MYDIALOG_H
