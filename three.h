#ifndef THREE_H
#define THREE_H
#include "candys.h"

class three:public Destroy
{
public:
    three();
    virtual ~three();
    virtual int condiction(basic *a[Row][Col],basic* focus);
    virtual void make(basic *a[Row][Col],basic* focus,int mode);
    virtual void boom(basic *a[Row][Col],basic* focus);
};

#endif // THREE_H
