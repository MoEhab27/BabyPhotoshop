#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <flipdialog.h>
#include <rotatedialog.h>
#include <mirrordialog.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void flip(bool h,bool v);
    void rotate(int angle);
    void mirrorImage(int side);
    QString aloo;


private slots:
    void on_pushButton_clicked();

    void on_BW_clicked();

    void on_save_clicked();

    void on_invert_btn_clicked();

    void on_darken_btn_clicked();

    void on_lighten_btn_clicked();

    void on_flip_btn_clicked();



    void on_rotate_btn_clicked();

    void on_clear_btn_clicked();

    void on_detect_btn_clicked();

    void on_blur_btn_clicked();

    void on_enlarge1_clicked();

    void on_enlarge2_clicked();

    void on_enlarge3_clicked();

    void on_enlarge4_clicked();

    void on_enlarge_btn_clicked();

    void on_applyBlur_clicked();


 //   void on_blurSlider_valueChanged(int value);

    void on_merge_btn_clicked();

    void on_mirror_clicked();



    void on_shuffle_btn_clicked();

    void on_shuffle1_clicked();

    void on_shuffle2_clicked();

    void on_shuffle3_clicked();

    void on_shuffle4_clicked();

    void on_cancelShuffle_clicked();

    void on_applyShuffle_clicked();

    void on_shrink_clicked();

    void on_cancelShrink_clicked();

    void on_shrinkHalf_clicked();

    void on_shrinkThird_clicked();

    void on_shrinkFourth_clicked();


private:
    Ui::MainWindow *ui;

//    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
