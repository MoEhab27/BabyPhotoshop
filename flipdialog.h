#ifndef FLIPDIALOG_H
#define FLIPDIALOG_H

#include <QDialog>

namespace Ui {
class FlipDialog;
}

class FlipDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FlipDialog(QWidget *parent = nullptr);
    ~FlipDialog();

private:
    Ui::FlipDialog *ui;
};

#endif // FLIPDIALOG_H
