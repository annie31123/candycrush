#ifndef FOURV_H
#define FOURV_H
#include "candys.h"


class fourV:public Destroy
{
public:
    fourV();
    virtual ~fourV();
    virtual int condiction(basic *a[Row][Col],basic* focus);
    virtual void make(basic *a[Row][Col],basic* focus,int mode);
    virtual void boom(basic *a[Row][Col],basic* focus);
};

#endif // FOURV_H
