#include "namingdialog.h"
#include "ui_namingdialog.h"
#include <mainwindow.h>
namingDialog::namingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::namingDialog)
{
    ui->setupUi(this);
}

namingDialog::~namingDialog()
{
    delete ui;
}


void namingDialog::on_buttonBox_accepted()
{
    MainWindow m;
    na= ui->lineEdit->text();
}

