#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "Assets/bmplib.cpp"



void loadImage(char filename[200]);
void saveImage();
void blackWhite();
void updateStat();
void invert();
void darken();
void lighten();


unsigned char image[SIZE][SIZE][RGB];

QString afterImage = "output/temp.bmp";
QImage afterImage2;
bool valid2 = afterImage2.load(afterImage);

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
//                   nameOfImage[i] = name[i];
               }
           //    image = imaged.scaledToWidth(ui->lbl_image->)
               loadImage("/home/ahmed/BabyPhotoshop/birds.bmp");

               ui->lbl_image->setPixmap(QPixmap::fromImage(image));
               ui->after->setPixmap(QPixmap::fromImage(afterImage2));
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

void invert()
{
    for (int i = 0; i < SIZE; i++)
{
    for (int j = 0; j < SIZE; j++)
    {
        for (int k = 0; k < RGB; k++){

        image[i][j][k] = 255 - image[i][j][k];
        }
    }
}
}

void darken()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k =0; k < RGB; k++){
            image[i][j][k] = image[i][j][k] / 2;

        }

        }
    }
}

void lighten()
{
    int num = 0;
    int i, j;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++){
            if ((image[i][j][k] + (image[i][j][k] / 2)) > 255)
            {
                image[i][j][k] = 255;
            }
            else
            {
                image[i][j][k] = image[i][j][k] + (image[i][j][k] / 2);
            }
            }
        }
    }
}


void MainWindow::flip(bool h,bool v){
    int x;

   if (v)
   {

    for(int i=0; i < SIZE; i++)
    {
     for(int j=0; j < SIZE/2; j++)
     {
         for (int k = 0; k < 3; k++)
         {

        // to Swap the first pixel with last pixel in the coulmn
            x = image[i][j][k];
            image[i][j][k]=image[i][SIZE-1-j][k];
            image[i][SIZE-1-j][k]= x;
         }

      }
    }
    saveImage();
     ui->after->setPixmap(QPixmap::fromImage(afterImage2));
   }
   else if(h)
   {

   for(int i=0; i < SIZE/2; i++)
   {
     for(int j=0; j < SIZE; j++)
     {
         for (int k = 0; k < 3; k++)
         {

   // to Swap the first pixel with last pixel in the coulmn
            x = image[i][j][k];
            image[i][j][k]=image[SIZE-1-i][j][k];
            image[SIZE-1-i][j][k]= x;
         }
      }
    }
   saveImage();
   ui->after->setPixmap(QPixmap::fromImage(afterImage2));
   }

   else //to avoid error
   {
     cout<<"unvalid input!";
   }

}


void saveImage()
{
    char imageFileName[200] = "output/temp.bmp";
    writeRGBBMP(imageFileName, image);
    bool valid2 = afterImage2.load(afterImage);
}




//void load()
//{
//    ui->after->setPixmap(QPixmap::fromImage(afterImage2));

//}


void MainWindow::on_BW_clicked()
{
    blackWhite();
    saveImage();
    ui->after->setPixmap(QPixmap::fromImage(afterImage2));
}


void MainWindow::on_save_clicked()
{

    saveImage();
    ui->after->setPixmap(QPixmap::fromImage(afterImage2));

}

void MainWindow::on_invert_btn_clicked()
{
    invert();
    saveImage();
    ui->after->setPixmap(QPixmap::fromImage(afterImage2));
}


void MainWindow::on_darken_btn_clicked()
{
    darken();
    saveImage();
    ui->after->setPixmap(QPixmap::fromImage(afterImage2));
}


void MainWindow::on_lighten_btn_clicked()
{
    lighten();
    saveImage();
    ui->after->setPixmap(QPixmap::fromImage(afterImage2));
}


void MainWindow::on_flip_btn_clicked()
{
    FlipDialog flip;
    flip.setModal(true);
    flip.exec();
}




