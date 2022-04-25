#ifndef BLURDIALOG_H
#define BLURDIALOG_H

#include <QDialog>

namespace Ui {
class blurDialog;
}

class blurDialog : public QDialog
{
    Q_OBJECT

public:
    explicit blurDialog(QWidget *parent = nullptr);
    ~blurDialog();

private:
    Ui::blurDialog *ui;
};

#endif // BLURDIALOG_H
