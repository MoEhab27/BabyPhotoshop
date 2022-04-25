#include "mirrordialog.h"
#include "ui_mirrordialog.h"
#include "mainwindow.h"

mirrorDialog::mirrorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mirrorDialog)
{
    ui->setupUi(this);
}

mirrorDialog::~mirrorDialog()
{
    delete ui;
}

void mirrorDialog::on_buttonBox_accepted()
{
    MainWindow m;
    if (ui->mrL->isChecked())
    {
        m.mirrorImage(2);
    }
    else if (ui->mrR->isChecked())
    {
        m.mirrorImage(1);

    }
    else if (ui->mrU->isChecked())
    {
        m.mirrorImage(3);

    }
    else if (ui->mrD->isChecked())
    {
        m.mirrorImage(4);

    }
}

