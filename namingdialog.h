#ifndef NAMINGDIALOG_H
#define NAMINGDIALOG_H

#include <QDialog>
#include<mainwindow.h>
namespace Ui {
class namingDialog;
}

class namingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit namingDialog(QWidget *parent = nullptr);
    ~namingDialog();
    QString na;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::namingDialog *ui;
};

#endif // NAMINGDIALOG_H
