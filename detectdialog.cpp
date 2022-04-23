#include "detectdialog.h"
#include "ui_detectdialog.h"

DetectDialog::DetectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetectDialog)
{
    ui->setupUi(this);
}

DetectDialog::~DetectDialog()
{
    delete ui;
}

void DetectDialog::on_horizontalSlider_actionTriggered(int action)
{

}

