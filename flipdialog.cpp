#include "flipdialog.h"
#include "ui_flipdialog.h"

FlipDialog::FlipDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FlipDialog)
{
    ui->setupUi(this);
}

FlipDialog::~FlipDialog()
{
    delete ui;
}
