#include "flipdialog.h"
#include "ui_flipdialog.h"
#include "mainwindow.cpp"

#include"Assets/bmplib.h"
#include <cstring>
#include <cmath>
#include "Assets/bmplib.cpp"

//unsigned char secondImage[SIZE][SIZE][RGB];

//void flipImage(bool H, bool V);


flipDialog::flipDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::flipDialog)
{
    ui->setupUi(this);

}

flipDialog::~flipDialog()
{
    delete ui;
}


void flipDialog::on_buttonBox_accepted()
{
    bool flipHorizontal = ui -> flipH -> isChecked();
    bool flipVertical = ui -> flipV -> isChecked();
    flipImage(flipHorizontal, flipVertical);
}

/*
void flipImage(bool H, bool V)
{

    if (H)
    {
          for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for(int k = 0; k < RGB; k++){

                secondImage[i][255 - j][k] = image[i][j][k];
            }
            }
        }
    }
    else if(V)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for(int k = 0; k < RGB; k++)
                {
                secondImage[255 - i][j][k] = image[i][j][k];
                }
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for(int k = 0; k < RGB; k++)
            {
            image[i][j][k] = secondImage[i][j][k];
            }
        }
    }
    saveImage();
}
*/
