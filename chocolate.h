#ifndef CHOCOLATE_H
#define CHOCOLATE_H

#include "candys.h"
class chocolate: public Destroy
{
public:
    chocolate();
    virtual ~chocolate();
    virtual int condiction(basic *a[Row][Col],basic* focus);
    virtual void make(basic *a[Row][Col],basic* focus,int mode);
    virtual void boom(basic *a[Row][Col],basic* focus);
};

#endif // CHOCOLATE_H
