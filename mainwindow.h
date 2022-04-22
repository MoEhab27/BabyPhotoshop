#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_BW_clicked();

    void on_save_clicked();

    void on_invert_btn_clicked();

    void on_darken_btn_clicked();

    void on_lighten_btn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
