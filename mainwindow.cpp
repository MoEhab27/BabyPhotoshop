#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.bmp)"));
    if (QString::compare(filename, QString()) != 0 )
    {
        QImage image;
        bool valid = image.load(filename);
        if (valid)
        {
        //    image = imaged.scaledToWidth(ui->lbl_image->)
            ui->lbl_image->setPixmap(QPixmap::fromImage(image));
            ui->label->setText(filename);
        }
        else
        {
            //Error Handle
        }
    }
}


void MainWindow::on_BW_clicked()
{

}

