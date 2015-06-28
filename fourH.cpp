#include "fourH.h"

fourH::fourH()
{

}
int fourH::condiction(basic *a[Row][Col], basic *focus){
    int i=focus->row;
    int j=focus->col;
    int num=focus->color;

    if(num!=0&&num!=50){

        if(num/10==0){

            if(j<Col-2&&j>0&&num%10==a[i][j+1]->color%10 && num%10==a[i][j+2]->color%10 && num%10 == a[i][j-1]->color%10)
                return 1;
            if(j<Col-1&&j>1&&num%10==a[i][j+1]->color%10 && num%10==a[i][j-2]->color%10 && num%10 == a[i][j-1]->color%10)
                return 2;

        }else{

            if(j<Col-2&&j>0&&num%10==a[i][j+1]->color%10 && num%10==a[i][j+2]->color%10 && num%10 == a[i][j-1]->color%10)
                return 3;
            if(j<Col-1&&j>1&&num%10==a[i][j+1]->color%10 && num%10==a[i][j-2]->color%10 && num%10 == a[i][j-1]->color%10)
                return 4;
        }


    }
    return 0;

}

void fourH::make(basic *a[Row][Col], basic *focus, int mode){
    int i=focus->row;
    int j=focus->col;
    int num=focus->color;
    int fivenum[4]={0};

    if(mode==0)
        return ;

    switch (mode) {
    case 1:



        if( a[i][j-1]->color/10!=0) { fivenum[0]=a[i][j-1]->color/10;}
        fivenum[1]=a[i][j]->color/10;
        if( a[i][j+1]->color/10!=0) { fivenum[2]=a[i][j+1]->color/10;}
        if( a[i][j+2]->color/10!=0) { fivenum[3]=a[i][j+2]->color/10;}


        for(int k=0;k<4;k++){
            Destroy *d;

            switch(fivenum[k]){
            case 0:
            a[i][j-1+k]->color=0;
            break;
            case 1:
                d=new fourH;
                d->boom(a,a[i][j-1+k]);
                delete d;
                break;
            case 2:
                d=new fourV;
                d->boom(a,a[i][j-1+k]);
                delete d;
                break;
            case 3:
                d=new nine;
                d->boom(a,a[i][j-1+k]);
                delete d;
                break;

            default:
            break;
            }


        }


        break;

    case 2:


        if( a[i][j-2]->color/10!=0) { fivenum[0]=a[i][j-2]->color/10;}
        if( a[i][j-1]->color/10!=0) { fivenum[1]=a[i][j-1]->color/10;}
        fivenum[2]=a[i][j]->color/10;
        if( a[i][j+1]->color/10!=0) { fivenum[3]=a[i][j+1]->color/10;}



        for(int k=0;k<4;k++){
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
    case 3:


        if( a[i][j-1]->color/10!=0) { fivenum[0]=a[i][j-1]->color/10;}
        fivenum[1]=a[i][j]->color/10;
        if( a[i][j+1]->color/10!=0) { fivenum[2]=a[i][j+1]->color/10;}
        if( a[i][j+2]->color/10!=0) { fivenum[3]=a[i][j+2]->color/10;}
        num%=10;


        for(int k=0;k<4;k++){
            Destroy *d;

            switch(fivenum[k]){
            case 0:
            a[i][j-1+k]->color=0;
            break;
            case 1:
                d=new fourH;
                d->boom(a,a[i][j-1+k]);
                delete d;
                break;
            case 2:
                d=new fourV;
                d->boom(a,a[i][j-1+k]);
                delete d;
                break;
            case 3:
                d=new nine;
                d->boom(a,a[i][j-1+k]);
                delete d;
                break;

            default:
            break;
            }


        }


        break;

    case 4:


        if( a[i][j-2]->color/10!=0) { fivenum[0]=a[i][j-2]->color/10;}
        if( a[i][j-1]->color/10!=0) { fivenum[1]=a[i][j-1]->color/10;}
        fivenum[2]=a[i][j]->color/10;
        if( a[i][j+1]->color/10!=0) { fivenum[3]=a[i][j+1]->color/10;}

        num%=10;


        for(int k=0;k<4;k++){
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


        default:
            break;



}
focus->color=num+10;


}

void fourH::boom(basic *a[Row][Col], basic *focus){
    int i=focus->row;
    focus->color=0;
    int tenarr[Row]={0};
    Destroy *d;
    for(int k=0;k<Row;k++){
        if(a[i][k]->color/10!=0)
        {tenarr[k]=a[i][k]->color/10;}
    }

    for(int k=0;k<Row;k++)
        switch(tenarr[k]){
        case 0:
            a[i][k]->color=0;
            break;
        case 1:
            d=new fourH;
            d->boom(a, a[i][k]);
            delete d;
            break;
        case 2:
            d=new fourV;
            d->boom(a, a[i][k]);
            delete d;
            break;

        case 3:
            d=new nine;
            d->boom(a, a[i][k]);
            delete d;
            break;
        default:
        break;
        }
}


fourH::~fourH()
{

}
