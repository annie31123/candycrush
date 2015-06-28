#include "fourV.h"

fourV::fourV()
{

}
int fourV::condiction(basic *a[Row][Col], basic *focus){
    int i=focus->row;
    int j=focus->col;
    int num=focus->color;

    if(num!=0&&num!=50){


        if(num/10==0){

            if(i<Col-2&&i>0&&num%10==a[i+1][j]->color%10 && num%10==a[i+2][j]->color%10 && num%10 == a[i-1][j]->color%10)
                return 1;
            if(i<Col-1&&i>1&&num%10==a[i+1][j]->color%10 && num%10==a[i-2][j]->color%10 && num%10 == a[i-1][j]->color%10)
                return 2;

        }else{
            if(i<Col-2&&i>0&&num%10==a[i+1][j]->color%10 && num%10==a[i+2][j]->color%10 && num%10 == a[i-1][j]->color%10)
                return 3;
            if(i<Col-1&&i>1&&num%10==a[i+1][j]->color%10 && num%10==a[i-2][j]->color%10 && num%10 == a[i-1][j]->color%10)
                return 4;
        }


    }
    return 0;
}

void fourV::make(basic *a[Row][Col], basic *focus, int mode){
    int i=focus->row;
    int j=focus->col;
    int num=focus->color;
    int fivenum[4]={0};
    num%=10;

    if(mode==0)
        return ;

    switch (mode) {
    case 1:
num%=10;


        if( a[i-1][j]->color/10!=0) { fivenum[0]=a[i-1][j]->color/10;}
        fivenum[1]=a[i][j]->color/10;
        if( a[i+1][j]->color/10!=0) { fivenum[2]=a[i+1][j]->color/10;}
        if( a[i+2][j]->color/10!=0) { fivenum[3]=a[i+2][j]->color/10;}


        for(int k=0;k<4;k++){
            Destroy *d;

            switch(fivenum[k]){
            case 0:
            a[i-1+k][j]->color=0;
            break;
            case 1:
                d=new fourH;
                d->boom(a,a[i-1+k][j]);
                delete d;
                break;
            case 2:
                d=new fourV;
                d->boom(a,a[i-1+k][j]);
                delete d;
                break;
            case 3:
                d=new nine;
                d->boom(a,a[i-1+k][j]);
                delete d;
                break;

            default:
            break;
            }


        }


        break;

    case 2:
        num%=10;

        if( a[i-2][j]->color/10!=0) { fivenum[0]=a[i-2][j]->color/10;}
        if( a[i-1][j]->color/10!=0) { fivenum[1]=a[i-1][j]->color/10;}
        fivenum[2]=a[i][j]->color/10;
        if( a[i+1][j]->color/10!=0) { fivenum[3]=a[i+1][j]->color/10;}



        for(int k=0;k<4;k++){
            Destroy *d;

            switch(fivenum[k]){
            case 0:
            a[i-2+k][j]->color=0;
            break;
            case 1:
                d=new fourH;
                d->boom(a,a[i-2+k][j]);
                delete d;
                break;
            case 2:
                d=new fourV;
                d->boom(a,a[i-2+k][j]);
                delete d;
                break;
            case 3:
                d=new nine;
                d->boom(a,a[i-2+k][j]);
                delete d;
                break;

            default:
            break;
            }


        }

        break;
    case 3:


        if( a[i-1][j]->color/10!=0) { fivenum[0]=a[i-1][j]->color/10;}
        fivenum[1]=a[i][j]->color/10;
        if( a[i+1][j]->color/10!=0) { fivenum[2]=a[i+1][j]->color/10;}
        if( a[i+2][j]->color/10!=0) { fivenum[3]=a[i+2][j]->color/10;}
        num%=10;


        for(int k=0;k<4;k++){
            Destroy *d;

            switch(fivenum[k]){
            case 0:
            a[i-1+k][j]->color=0;
            break;
            case 1:
                d=new fourH;
                d->boom(a,a[i-1+k][j]);
                delete d;
                break;
            case 2:
                d=new fourV;
                d->boom(a,a[i-1+k][j]);
                delete d;
                break;
            case 3:
                d=new nine;
                d->boom(a,a[i-1+k][j]);
                delete d;
                break;

            default:
            break;
            }


        }


        break;

    case 4:


        if( a[i-2][j]->color/10!=0) { fivenum[0]=a[i-2][j]->color/10;}
        if( a[i-1][j]->color/10!=0) { fivenum[1]=a[i-1][j]->color/10;}
        fivenum[2]=a[i][j]->color/10;
        if( a[i+1][j]->color/10!=0) { fivenum[3]=a[i+1][j]->color/10;}

        num%=10;


        for(int k=0;k<4;k++){
            Destroy *d;

            switch(fivenum[k]){

            case 0:
            a[i-2+k][j]->color=0;
            break;
            case 1:
                d=new fourH;
                d->boom(a,a[i-2+k][j]);
                delete d;
                break;
            case 2:
                d=new fourV;
                d->boom(a,a[i-2+k][j]);
                delete d;
                break;
            case 3:
                d=new nine;
                d->boom(a,a[i-2+k][j]);
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

focus->color=num+20;

}

void fourV::boom(basic *a[Row][Col], basic *focus){
    int j=focus->col;
    focus->color=0;
    int tenarr[Row]={0};
    Destroy *d;
    for(int k=0;k<Row;k++){
        if(a[k][j]->color/10!=0)
        {tenarr[k]=a[k][j]->color/10;}
    }

    for(int k=0;k<Row;k++)
        switch(tenarr[k]){
        case 0:
            a[k][j]->color=0;
            break;
        case 1:
            d=new fourH;
            d->boom(a, a[k][j]);
            delete d;
            break;
        case 2:
            d=new fourV;
            d->boom(a, a[k][j]);
            delete d;
            break;

        case 3:
            d=new nine;
            d->boom(a, a[k][j]);
            delete d;
            break;
        default:
        break;
        }
}


fourV::~fourV()
{

}
