#ifndef FLIP_H
#define FLIP_H

#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>

class flipData;

class flip : public QWidget
{
    Q_OBJECT
public:
    explicit flip(QWidget *parent = nullptr);
    flip(const flip &);
    flip &operator=(const flip &);
    ~flip();

signals:


private:
    QSharedDataPointer<flipData> data;
};

#endif // FLIP_H
