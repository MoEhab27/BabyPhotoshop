#include "blurdialog.h"
#include "ui_blurdialog.h"

blurDialog::blurDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::blurDialog)
{
    ui->setupUi(this);
}

blurDialog::~blurDialog()
{
    delete ui;
}
