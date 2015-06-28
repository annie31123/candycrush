#include "chocolate.h"

chocolate::chocolate()
{

}

chocolate::~chocolate()
{

}

int chocolate::condiction(basic *a[Row][Col], basic *focus)
{
    int i=focus->row;
    int j=focus->col;
    int num=focus->color;

    if(num!=0&&num!=50){



            if(j<Col-2&&j>1&&num%10==a[i][j+1]->color%10 &&num%10==a[i][j+2]->color%10 &&num%10==a[i][j-1]->color%10&&num%10==a[i][j-2]->color%10)
                return 1; //水平*/
            if(i<Row-2&&i>1&& num%10==a[i+1][j]->color%10 &&  num%10==a[i+2][j]->color%10 & num%10==a[i-1][j]->color%10&& num%10==a[i-2][j]->color%10)
                return 2; //鉛直

    }

    return 0;
}

void chocolate::make(basic *a[Row][Col], basic *focus,int mode)
{
    int i=focus->row;
    int j=focus->col;
    int num=focus->color;
    int fivenum[5]={0};

    switch (mode) {
    case 1: //水平
        focus->color=50;
        if(i>1&&num==a[i-2][j]->color%10&&num==a[i-1][j]->color%10){
        a[i-2][j]->color=0;
        a[i-1][j]->color=0;
        }
        if(i<Row-2&&num==a[i+1][j]->color%10&&num==a[i+2][j]->color%10){
            a[i+2][j]->color=0;
            a[i+1][j]->color=0;
        }

         fivenum[0]=a[i][j-2]->color/10;
         fivenum[1]=a[i][j-1]->color/10;
        fivenum[2]=a[i][j]->color/10;
        fivenum[3]=a[i][j+1]->color/10;
         fivenum[4]=a[i][j+2]->color/10;


        for(int k=0;k<5;k++){
            Destroy *d;

            switch(fivenum[k]){
            case 0:
            a[i][j-2+k]->color=0;
            break;
            case 1:
                d=new fourH;
                d->boom(a,a[i][j-2+k]);
                delete d;
                break;
            case 2:
                d=new fourV;
                d->boom(a,a[i][j-2+k]);
                delete d;
                break;
            case 3:
                d=new nine;
                d->boom(a,a[i][j-2+k]);
                delete d;
                break;

            default:
            break;
            }


        }


        break;

    case 2:
        focus->color=50;
        if(j>1&&num==a[i][j-2]->color%10&&num==a[i][j-1]->color%10){
        a[i][j-2]->color=0;
        a[i][j-1]->color=0;
        }
        if(j<Row-2&&num==a[i][j+1]->color%10&&num==a[i][j+2]->color%10){
            a[i][j+2]->color=0;
            a[i][j+1]->color=0;
        }

         fivenum[0]=a[i-2][j]->color/10;
         fivenum[1]=a[i-1][j]->color/10;
        fivenum[2]=a[i][j]->color/10;

         fivenum[3]=a[i+1][j]->color/10;
         fivenum[4]=a[i+2][j]->color/10;

        for(int k=0;k<5;k++){
            Destroy *d;

            switch(fivenum[k]){
            case 0:
            a[i-2+k][j]->color=0;
            break;
            case 1:
                d=new fourH;
                d->boom(a, a[i-2+k][j]);
                delete d;
                break;
            case 2:
                d=new fourV;
                d->boom(a, a[i-2+k][j]);
                delete d;
                break;
            case 3:
                d=new nine;
                d->boom(a, a[i-2+k][j]);
                delete d;
                break;
            default:
            break;
            }

        }
        break;




    default:
        break;


}

}
void chocolate::boom(basic *a[Row][Col], basic *focus)
{

}

