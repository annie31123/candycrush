#ifndef FOURH_H
#define FOURH_H
#include "candys.h"

class fourH:public Destroy
{
public:
    fourH();
    virtual ~fourH();
    virtual int condiction(basic *a[Row][Col],basic* focus);
    virtual void make(basic *a[Row][Col],basic* focus,int mode);
    virtual void boom(basic *a[Row][Col],basic* focus);
};

#endif // FOUR_H
