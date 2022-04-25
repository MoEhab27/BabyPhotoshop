#ifndef MIRRORDIALOG_H
#define MIRRORDIALOG_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class mirrorDialog;
}

class mirrorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit mirrorDialog(QWidget *parent = nullptr);
    ~mirrorDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::mirrorDialog *ui;
};

#endif // MIRRORDIALOG_H
