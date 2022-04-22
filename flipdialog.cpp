#include "flipdialog.h"
#include "ui_flipdialog.h"

#include "mainwindow.h"

//#include "mainwindow.cpp"

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





void FlipDialog::on_buttonBox_accepted()
{
    MainWindow mn;
    mn.flip(ui->fliph->isChecked(),ui->flipv->isChecked());

//    QString afterImage = "output/temp.bmp";
//    QImage afterImage2;
//    bool valid2 = afterImage2.load(afterImage);
//    mn.ui->after->setPixmap(QPixmap::fromImage(afterImage2));
}





