#include "flip.h"

class flipData : public QSharedData
{
public:

};

flip::flip(QWidget *parent)
    : QWidget{parent}, data(new flipData)
{

}

flip::flip(const flip &rhs)
    : data{rhs.data}
{

}

flip &flip::operator=(const flip &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

flip::~flip()
{

}
