#ifndef NINE_H
#define NINE_H
#include "candys.h"

class nine:public Destroy
{
public:
    nine();
    virtual ~nine();
    virtual int condiction(basic *a[Row][Col],basic* focus);
    virtual void make(basic *a[Row][Col],basic* focus,int mode);
    virtual void boom(basic *a[Row][Col],basic* focus);

};

#endif // NINE_H
