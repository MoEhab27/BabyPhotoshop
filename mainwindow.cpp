#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "Assets/bmplib.cpp"

void loadImage(char filename[200]);
void blackWhite();

unsigned char image[SIZE][SIZE][RGB];

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
           char nameOfImage[200];
           std::string name = filename.toUtf8().constData();

           if (valid)
           {
               for (int i = 0; i < filename.length(); i++)
               {
                   nameOfImage[i] = name[i];
               }
           //    image = imaged.scaledToWidth(ui->lbl_image->)
               loadImage(nameOfImage);

               ui->lbl_image->setPixmap(QPixmap::fromImage(image));
               ui->label->setText(filename);
           }
           else
           {
               //Error Handle
           }
       }
}



void loadImage(char filename[200])
{
    readRGBBMP(filename, image);
}


void blackWhite()
{

    long avg = 0;
    int temp;
    int rgb;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for(int k = 0; k < RGB; k++){
                avg += image[i][j][k];
            }

        }
    }

    avg /= SIZE*SIZE*RGB;

    cout << "The Average is: " << avg << endl;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++){
                temp += image[i][j][k];
                rgb = k;
            }
            temp /= 3;
            if (temp >= avg){
                image[i][j][rgb] = 255;
                image[i][j][rgb - 1] = 255;
                image[i][j][rgb - 2] = 255;
            }
            else {
                image[i][j][rgb] = 0;
                image[i][j][rgb - 1] = 0;
                image[i][j][rgb - 2] = 0;
            }
            temp =0;
            }
        }

}

void saveImage()
{
    char imageFileName[200] = "output/temp.bmp";
    writeRGBBMP(imageFileName, image);
}
void MainWindow::on_BW_clicked()
{
    blackWhite();
}


void MainWindow::on_save_clicked()
{
    saveImage();

}

