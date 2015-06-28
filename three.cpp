#include "three.h"

three::three()
{

}

three::~three()
{

}

int three::condiction(basic *a[Row][Col], basic *focus)
{
    int i=focus->row;
    int j=focus->col;
    int num=focus->color%10;

    if(num!=0&&num!=50){

             if(i<Row-2&&num==a[i+1][j]->color%10&&num==a[i+2][j]->color%10)
                return 1;
            if(i<Row-1&&i>0&&num==a[i-1][j]->color%10&&num==a[i+1][j]->color%10)
                return 2;
           if(i>1&&num==a[i-1][j]->color%10&&num==a[i-2][j]->color%10)
                return 3;
            if(j<Col-2&&num==a[i][j+1]->color%10&&num==a[i][j+2]->color%10)
                return 4;
            if(j<Col-1&&j>0&&num==a[i][j-1]->color%10&&num==a[i][j+1]->color%10)
                return 5;
            if(j>1&&num==a[i][j-1]->color%10&&num==a[i][j-2]->color%10)
                return 6;


    }
    return 0;
}

void three::make(basic *a[Row][Col], basic *focus, int mode)
{
    int i=focus->row;
    int j=focus->col;
    int num=focus->color%10;
    int threenum[3]={0};


    switch (mode) {
    case 1:
        threenum[0]=a[i][j]->color/10;
        threenum[1]=a[i+1][j]->color/10;
        threenum[2]=a[i+2][j]->color/10;

        for(int k=0;k<3;k++){
            Destroy *d;

            switch(threenum[k]){
            case 0:
             a[i+k][j]->color=0;
                break;
            case 1:
                d=new fourH;
                d->boom(a,a[i+k][j]);
                delete d;
                break;
            case 2:
                d=new fourV;
                d->boom(a,a[i+k][j]);
                delete d;
                break;
            case 3:
                d=new nine;
                d->boom(a,a[i+k][j]);
                delete d;
                break;

            default:
            break;
            }


        }
        break;

    case 2:
        threenum[0]=a[i][j]->color/10;
        threenum[1]=a[i-1][j]->color/10;
        threenum[2]=a[i+1][j]->color/10;

        for(int k=-1;k<2;k++){
            Destroy *d;

            switch(threenum[k+1]){
            case 0:
            a[i+k][j]->color=0;
            break;
            case 1:
                d=new fourH;
                d->boom(a,a[i+k][j]);
                delete d;
                break;
            case 2:
                d=new fourV;
                d->boom(a,a[i+k][j]);
                delete d;
                break;
            case 3:
                d=new nine;
                d->boom(a,a[i+k][j]);
                delete d;
                break;

            default:
            break;
            }


        }
        break;
    case 3:

        threenum[0]=a[i-2][j]->color/10;
        threenum[1]=a[i-1][j]->color/10;
        threenum[2]=a[i][j]->color/10;

        for(int k=-2;k<1;k++){
            Destroy *d;

            switch(threenum[k+2]){
            case 0:
            a[i+k][j]->color=0;
            break;
            case 1:
                d=new fourH;
                d->boom(a,a[i+k][j]);
                delete d;
                break;
            case 2:
                d=new fourV;
                d->boom(a,a[i+k][j]);
                delete d;
                break;
            case 3:
                d=new nine;
                d->boom(a,a[i+k][j]);
                delete d;
                break;

            default:
            break;
            }


        }
        break;
    case 4:
        threenum[0]=a[i][j]->color/10;
        threenum[1]=a[i][j+1]->color/10;
        threenum[2]=a[i][j+2]->color/10;

        for(int k=0;k<3;k++){
            Destroy *d;

            switch(threenum[k]){
            case 0:
            a[i][j+k]->color=0;
            break;
            case 1:
                d=new fourH;
                d->boom(a,a[i][j+k]);
                delete d;
                break;
            case 2:
                d=new fourV;
                d->boom(a,a[i][j+k]);
                delete d;
                break;
            case 3:
                d=new nine;
                d->boom(a,a[i][j+k]);
                delete d;
                break;

            default:
            break;
            }


        }
        break;
    case 5:
        threenum[0]=a[i][j-1]->color/10;
        threenum[1]=a[i][j]->color/10;
        threenum[2]=a[i][j+1]->color/10;

        for(int k=-1;k<2;k++){
            Destroy *d;

            switch(threenum[k+1]){
            case 0:
            a[i][j+k]->color=0;
            break;
            case 1:
                d=new fourH;
                d->boom(a,a[i][j+k]);
                delete d;
                break;
            case 2:
                d=new fourV;
                d->boom(a,a[i][j+k]);
                delete d;
                break;
            case 3:
                d=new nine;
                d->boom(a,a[i][j+k]);
                delete d;
                break;

            default:
            break;
            }


        }
        break;
    case 6:
        threenum[0]=a[i][j-2]->color/10;
        threenum[1]=a[i][j-1]->color/10;
        threenum[2]=a[i][j]->color/10;

        for(int k=-2;k<1;k++){
            Destroy *d;

            switch(threenum[k+2]){
            case 0:
            a[i][j+k]->color=0;
            break;
            case 1:
                d=new fourH;
                d->boom(a,a[i][j+k]);
                delete d;
                break;
            case 2:
                d=new fourV;
                d->boom(a,a[i][j+k]);
                delete d;
                break;
            case 3:
                d=new nine;
                d->boom(a,a[i][j+k]);
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

void three::boom(basic *a[Row][Col], basic *focus)
{





}

