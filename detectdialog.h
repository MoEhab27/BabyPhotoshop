#ifndef DETECTDIALOG_H
#define DETECTDIALOG_H

#include <QDialog>

namespace Ui {
class DetectDialog;
}

class DetectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DetectDialog(QWidget *parent = nullptr);
    ~DetectDialog();

private slots:
    void on_horizontalSlider_actionTriggered(int action);

private:
    Ui::DetectDialog *ui;
};

#endif // DETECTDIALOG_H
