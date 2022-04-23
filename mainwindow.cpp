#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "Assets/bmplib.cpp"

//--------------------------
//  Functions Declerations
//--------------------------
void loadImage(char filename[200]);
void saveImage();
void blackWhite();
void updateStat();
void invert();
void darken();
void lighten();
void saveBackup();
void detectEdges();
void blur();

//--------------------------



//--------------------------
// Images and Gllobal Variables
//--------------------------

unsigned char image[SIZE][SIZE][RGB];
unsigned char secondImage[SIZE][SIZE][RGB];
char backup[200];

QString afterImage = "output/temp.bmp";
QImage afterImage2;
bool valid2 = afterImage2.load(afterImage);

QString empty1 = "Assets/empty.png";
QImage emptyImage;
bool eImage = emptyImage.load(empty1);

//--------------------------
//--------------------------


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->enlarge1->hide();
    ui->enlarge2->hide();
    ui->enlarge3->hide();
    ui->enlarge4->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}



//--------------------------
// Load Button Function
//--------------------------

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
//               loadImage(nameOfImage);//////////////////////////////////
               loadImage("/home/ahmed/BabyPhotoshop/birds.bmp");
               for (int i = 0; i < filename.length(); i++)
               {
                   backup[i] = nameOfImage[i];
               }
               ui->lbl_image->setPixmap(QPixmap::fromImage(image));
               ui->label->setText(filename);
           }
           else
           {
               //Error Handle
           }
       }
}
//--------------------------
//--------------------------



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

void detectEdges()
{
    unsigned char gsImage[SIZE][SIZE];
       int temp;

       for (int i=0; i < SIZE; i++)
       {
           for (int j=0; j < SIZE; j++)
           {
               for (int k=0; k < RGB; k++)
               {
                 temp += image[i][j][k];
               }
               temp /= 3;
               gsImage[i][j] = temp;
               temp = 0;
           }
       }

           for (int i = 0; i < SIZE - 1; i++)
       {
           for (int j = 0; j < SIZE - 1; j++)
           {
               if ((abs(gsImage[i][j] -gsImage[i][j + 1]) >= 40) || (abs(gsImage[i][j] - gsImage[i + 1][j]) >= 40))
               {
                   gsImage[i][j] = 0;
               }
               else
               {
                   gsImage[i][j] = 255;
               }
           }
       }
       for (int i = 0; i < SIZE; i++)
       {
           for (int j = 0; j < SIZE; j++)
           {
               if (gsImage[i][j] == 0)
                   {
               for (int k = 0; k < RGB; k++)
               {
                   image[i][j][k] = 0;
               }
                   }
               else
               {
                   for (int k = 0; k < RGB; k++)
                   {
                   image[i][j][k] = 255;
                   }
               }
           }
       }
}

void blur()
{
    unsigned char space[258][258][3];

            for (int i = 1; i < 258; ++i){
                for (int j = 1; j < 258; ++j){
                    for(int k = 0; k < RGB; k++){
                    space[i][j][k] = image[i-1][j-1][k];
                }
                }
            }
            for (int i = 1; i < 258; ++i){
                for (int j = 1; j < 258; ++j){
                        for (int k = 0; k < RGB; k++){
                int kernelR, kernelG, kernelB;
                if(k == 0){
                kernelR = space[i-1][j-1][k] + space[i-1][j][k] + space[i-1][j+1][k] + space[i][j-1][k] + space[i][j][k] + space[i][j+1][k] + space[i+1][j-1][k] + space[i+1][j][k] + space[i][j+1][k];
                kernelR /= 9;
                space[i][j][k] = kernelR;

                }
                if (k == 1){

                kernelG = space[i-1][j-1][k] + space[i-1][j][k] + space[i-1][j+1][k] + space[i][j-1][k] + space[i][j][k] + space[i][j+1][k] + space[i+1][j-1][k] + space[i+1][j][k] + space[i][j+1][k];
                kernelG /= 9;
                space[i][j][k] = kernelG;
                }
                if (k == 2){

                kernelB = space[i-1][j-1][k] + space[i-1][j][k] + space[i-1][j+1][k] + space[i][j-1][k] + space[i][j][k] + space[i][j+1][k] + space[i+1][j-1][k] + space[i+1][j][k] + space[i][j+1][k];
                kernelB /= 9;
                space[i][j][k] = kernelB;

                }
                        }
                }
            }
            for (int i = 1; i < 258; ++i){
                for (int j = 1; j < 258; ++j){
                    for (int k = 0; k < RGB; k++){
                     image[i-1][j-1][k] = space[i][j][k];
                }
                }
                }
}

void MainWindow::rotate(int angle)
{

     if (angle == 90)
     {
         for (int i = 0; i < SIZE; ++i)
         {
             for (int j = 0; j < SIZE; ++j)
             {
                 for (int k =0; k < RGB; k++){
                 secondImage[255 - j][i][k] = image[i][j][k];
             }
         }
         }
         for (int i = 0; i < SIZE; ++i)
         {
             for (int j = 0; j < SIZE; ++j)
             {
                 for (int k = 0; k < RGB; k++){
                 image[i][j][k] = secondImage[i][j][k];
             }
             }
         }
     }
     if (angle == 180)
     {
         for (int i = 0; i < SIZE; ++i)
         {
             for (int j = 0; j < SIZE; ++j)
             {
                 for(int k = 0; k< RGB; k++){
                 secondImage[255 - i][255 - j][k] = image[i][j][k];
             }
             }
         }
         for (int i = 0; i < SIZE; ++i)
         {
             for (int j = 0; j < SIZE; ++j)
             {
                 for(int k = 0; k <RGB; k++){
                 image[i][j][k] = secondImage[i][j][k];
             }
             }
         }
     }
     if (angle == 270)
     {
         for (int i = 0; i < SIZE; ++i)
         {
             for (int j = 0; j < SIZE; ++j)
             {
                 for (int k = 0; k <RGB; k++){
                 secondImage[255 - j][i][k] = image[i][j][k];
             }
             }
         }
         for (int i = 0; i < SIZE; ++i)
         {
             for (int j = 0; j < SIZE; ++j)
             {
                 for (int k = 0; k < RGB; k++){
                 image[i][j][k] = secondImage[i][j][k];
             }
             }

     }
 }
}

void MainWindow::flip(bool h,bool v){
    int x;

   if (h)
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
   else if(v)
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

//--------------------------
// Enlarge Filter
//--------------------------

unsigned char img2[SIZE][SIZE][3] ;//declear new imagr aaray
int x=0,y=0;

void copyRGBimage(unsigned char img2[SIZE][SIZE][3]){ //function to take a copy from the origianl image
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
        for (int k = 0; k < 3; k++)
        {
            img2[i][j][k]=image[i][j][k];
        }
        }
   }
}

void enlargeFirstQ(){// function for enlarge first Quarter
    copyRGBimage(img2);
    for (int i = 0; i < SIZE/2; i++) {
      for (int j = 0; j< SIZE/2; j++) {
        for (int k = 0; k < 3; k++)
        {
        image[x][y][k] = img2[i][j][k];//take first pixel and assign it to first pixel in image
        image[x][y+1][k]= img2[i][j][k];//take second on right pixel and assign it to  second on right pixel in image
        image[x+1][y+1][k]= img2[i][j][k];//take last pixel and assign it to last pixel in image
        image[x+1][y][k]= img2[i][j][k];//take dwon pixel and assign it to dawon pixel in image
        }
        y+=2;
      }
      x+=2;
      y=0;
    }
}

void enlargeSecondQ(){// function for enlarge second Quarter
    copyRGBimage(img2);
   for (int i = 0; i < SIZE/2; i++) {
      for (int j = (SIZE/2); j< SIZE; j++) {
         for (int k = 0; k < 3; k++)
        {
        image[x][y][k] = img2[i][j][k];//take first pixel and assign it to first pixel in image
        image[x][y+1][k]= img2[i][j][k];//take second on right pixel and assign it to  second on right pixel in image
        image[x+1][y+1][k]= img2[i][j][k];//take last pixel and assign it to last pixel in image
        image[x+1][y][k]= img2[i][j][k];//take dwon pixel and assign it to dawon pixel in image
        }
        y+=2;

      }
      x+=2;
      y=0;
    }
}

void enlargeThirdQ(){// function for enlarge third Quarter
    copyRGBimage(img2);
   for (int i = (SIZE/2); i < SIZE; i++) {
      for (int j = 0; j< SIZE/2; j++) {
        for (int k = 0; k < 3; k++)
        {
        image[x][y][k] = img2[i][j][k];//take first pixel and assign it to first pixel in image
        image[x][y+1][k]= img2[i][j][k]; //take second on right pixel and assign it to  second on right pixel in image
        image[x+1][y+1][k]= img2[i][j][k];//take last pixel and assign it to last pixel in image
        image[x+1][y][k]= img2[i][j][k];//take dwon pixel and assign it to dawon pixel in image
        }
        y+=2;
      }
      x+=2;
      y=0;
    }
}

void enlargeFourthQ(){// function for enlarge fourth Quarter
    copyRGBimage(img2);
  for (int i = (SIZE/2); i < SIZE; i++) {
      for (int j = (SIZE/2); j< SIZE; j++) {
         for (int k = 0; k < 3; k++)
        {
        image[x][y][k] = img2[i][j][k];//take first pixel and assign it to first pixel in image
        image[x][y+1][k]= img2[i][j][k];//take second on right pixel and assign it to  second on right pixel in image
        image[x+1][y+1][k]= img2[i][j][k];//take last pixel and assign it to last pixel in image
        image[x+1][y][k]= img2[i][j][k];//take dwon pixel and assign it to dawon pixel in image
        }
        y+=2;
      }
      x+=2;
      y=0;
    }
}




void saveImage()
{
    char imageFileName[200] = "output/temp.bmp";
    writeRGBBMP(imageFileName, image);
    bool valid2 = afterImage2.load(afterImage);
}

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
    FlipDialog flip; // Calls The Dialog to open the flip window
    flip.setModal(true);
    flip.exec();     // Stops the app till we get a result from the dialog
    ui->after->setPixmap(QPixmap::fromImage(afterImage2));  // Displays the result in the After window
}

void MainWindow::on_rotate_btn_clicked()
{
    rotateDialog rotate;
    rotate.setModal(true);
    rotate.exec();
    saveImage();
    ui->after->setPixmap(QPixmap::fromImage(afterImage2));
}

void MainWindow::on_clear_btn_clicked()
{
    ui->after->setPixmap(QPixmap::fromImage(emptyImage));
    loadImage(backup);
}

void MainWindow::on_detect_btn_clicked()
{
    detectEdges();
    saveImage();
    ui->after->setPixmap(QPixmap::fromImage(afterImage2));
}

void MainWindow::on_blur_btn_clicked()
{
    blur();
    saveImage();
    ui->after->setPixmap(QPixmap::fromImage(afterImage2));

}

void MainWindow::on_enlarge_btn_clicked()
{
    ui->enlarge1->show();
    ui->enlarge2->show();
    ui->enlarge3->show();
    ui->enlarge4->show();
}

void MainWindow::on_enlarge1_clicked()
{
    enlargeFirstQ();
    saveImage();
    ui->after->setPixmap(QPixmap::fromImage(afterImage2));
    ui->enlarge1->hide();
    ui->enlarge2->hide();
    ui->enlarge3->hide();
    ui->enlarge4->hide();
}

void MainWindow::on_enlarge2_clicked()
{
    enlargeSecondQ();
    saveImage();
    ui->after->setPixmap(QPixmap::fromImage(afterImage2));
    ui->enlarge1->hide();
    ui->enlarge2->hide();
    ui->enlarge3->hide();
    ui->enlarge4->hide();
}

void MainWindow::on_enlarge3_clicked()
{
    enlargeThirdQ();
    saveImage();
    ui->after->setPixmap(QPixmap::fromImage(afterImage2));
    ui->enlarge1->hide();
    ui->enlarge2->hide();
    ui->enlarge3->hide();
    ui->enlarge4->hide();
}

void MainWindow::on_enlarge4_clicked()
{
    enlargeFourthQ();
    saveImage();
    ui->after->setPixmap(QPixmap::fromImage(afterImage2));
    ui->enlarge1->hide();
    ui->enlarge2->hide();
    ui->enlarge3->hide();
    ui->enlarge4->hide();
}


