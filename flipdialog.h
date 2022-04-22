#ifndef FLIPDIALOG_H
#define FLIPDIALOG_H



#include <QDialog>
#include <mainwindow.h>


namespace Ui {
class FlipDialog;
}

class FlipDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FlipDialog(QWidget *parent = nullptr);
    ~FlipDialog();
    bool data();



private slots:
//    void on_buttonBox_accepted();

    void on_buttonBox_accepted();


private:
    Ui::FlipDialog *ui;
};

#endif // FLIPDIALOG_H
