#ifndef FLIPDIALOG_H
#define FLIPDIALOG_H

#include <QDialog>

namespace Ui {
class flipDialog;
}

class flipDialog : public QDialog
{
    Q_OBJECT

public:
    explicit flipDialog(QWidget *parent = nullptr);
    ~flipDialog();

private slots:
    void on_radioButton_3_toggled(bool checked);

    void on_buttonBox_accepted();

private:
    Ui::flipDialog *ui;
};

#endif // FLIPDIALOG_H
