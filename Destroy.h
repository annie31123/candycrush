#ifndef DESTROY_H
#define DESTROY_H

#include "basic.h"

class Destroy
{
public:
    Destroy();
    virtual ~Destroy();
    virtual int condiction(basic *a[Row][Col],basic* focus)=0;
    virtual void make(basic *a[Row][Col],basic* focus,int mode)=0;
    virtual void boom(basic *a[Row][Col],basic* focus)=0;

};

#endif // DESTORY_H
