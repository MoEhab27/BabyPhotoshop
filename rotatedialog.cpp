#include "rotatedialog.h"
#include "ui_rotatedialog.h"
#include "mainwindow.h"

rotateDialog::rotateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rotateDialog)
{
    ui->setupUi(this);
}

rotateDialog::~rotateDialog()
{
    delete ui;
}

void rotateDialog::on_buttonBox_accepted()
{
    MainWindow m;
    if (ui->one->isChecked())
    {
        m.rotate(90);
    }
    else if (ui->two->isChecked())
    {
        m.rotate(180);

    }
    else if (ui->three->isChecked())
    {
        m.rotate(270);

    }
}

