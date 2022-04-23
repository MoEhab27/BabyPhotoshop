#ifndef ROTATEDIALOG_H
#define ROTATEDIALOG_H

#include <QDialog>
#include <mainwindow.h>


namespace Ui {
class rotateDialog;
}

class rotateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit rotateDialog(QWidget *parent = nullptr);
    ~rotateDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::rotateDialog *ui;
};

#endif // ROTATEDIALOG_H
