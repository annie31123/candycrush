#include "nine.h"

nine::nine()
{

}
int nine::condiction(basic *a[Row][Col], basic *focus){
    int i=focus->row;
    int j=focus->col;
    int num=focus->color;

    if(num!=0&&num!=50){

            if(i<Row-2&&i<Row-2&& num%10==a[i][j+1]->color%10 &&num==a[i][j+2]->color%10&&num%10==a[i+1][j]->color%10 &&num%10==a[i+2][j]->color%10)
                return 4;
            if(i<Row-2&&j>1&&num%10==a[i][j-1]->color%10 && num%10==a[i][j-2]->color%10&&num%10==a[i+1][j]->color%10 && num%10==a[i+2][j]->color%10)
                return 2;
            if(i>1&&j<Row-2&&num%10==a[i][j+1]->color%10 && num%10==a[i][j+2]->color%10&&num%10==a[i-1][j]->color%10 && num%10==a[i-2][j]->color%10)
                return 3;
            if(i>1&&j>1&&num%10==a[i][j-1]->color%10 && num%10==a[i][j-2]->color%10&&num%10==a[i-1][j]->color%10 && num%10==a[i-2][j]->color%10)
                return 1;
            if(i<Col-2&&j>0&&j<Col-1&&num%10==a[i][j-1]->color%10&&num%10==a[i][j+1]->color%10&&num%10==a[i+1][j]->color%10&&num%10==a[i+2][j]->color%10)
                return 8;
            if(i>1&&j>0&&j<Col-1&&num%10==a[i][j-1]->color%10&&num%10==a[i][j+1]->color%10&&num%10==a[i-1][j]->color%10&&num%10==a[i-2][j]->color%10)
                return 7;
            if(i>0&&i<Row-1&&j>1&&num%10==a[i][j-1]->color%10&&num%10==a[i][j-2]->color%10&&num%10==a[i+1][j]->color%10&&num%10==a[i-1][j]->color%10)
                return 5;
            if(i>0&&i<Row-1&&j<Col-2&&num%10==a[i][j+1]->color%10&&num%10==a[i][j+2]->color%10&&num%10==a[i+1][j]->color%10&&num%10==a[i-1][j]->color%10)
                return 6;


}
    return 0;
}

void nine::make(basic *a[Row][Col], basic *focus, int mode){
    int i=focus->row;
    int j=focus->col;
    int num=focus->color%10;
    int fivenum[5]={0};

    switch(mode){
    case 1:
        if(j<Col-1&&num==a[i][j+1]->color%10)
            a[i][j+1]->color=0;
        if(i<Row-1&&num==a[i+1][j]->color%10)
            a[i+1][j]->color=0;
        fivenum[0]=a[i][j-2]->color/10;
        fivenum[1]=a[i][j-1]->color/10;
        fivenum[2]=a[i][j]->color/10;
        fivenum[3]=a[i-1][j]->color/10;
        fivenum[4]=a[i-2][j]->color/10;


        for(int k=0;k<2;k++){
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
        for(int k=0;k<2;k++){
            Destroy *d;

            switch(fivenum[k+3]){
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
    case 2:
        if(j<Col-1&&num==a[i][j+1]->color%10)
            a[i][j+1]->color=0;

        if(i>0&&num==a[i-1][j]->color%10)
            a[i-1][j]->color=0;

        fivenum[0]=a[i][j-2]->color/10;
        fivenum[1]=a[i][j-1]->color/10;
        fivenum[2]=a[i][j]->color/10;
        fivenum[3]=a[i+1][j]->color/10;
        fivenum[4]=a[i+2][j]->color/10;


        for(int k=0;k<2;k++){
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
        for(int k=0;k<2;k++){
            Destroy *d;

            switch(fivenum[k+3]){
            case 0:
            a[i+k+1][j]->color=0;
            break;
            case 1:
                d=new fourH;
                d->boom(a,a[i+k+1][j]);
                delete d;
                break;
            case 2:
                d=new fourV;
                d->boom(a,a[i+k+1][j]);
                delete d;
                break;
            case 3:
                d=new nine;
                d->boom(a,a[i+k+1][j]);
                delete d;
                break;

            default:
            break;
            }
            }
        break;
    case 3:
        if(j>0&&num==a[i][j-1]->color%10)
            a[i][j-1]->color=0;
        if(i<9&&num==a[i+1][j]->color%10)
            a[i+1][j]->color=0;
        fivenum[0]=a[i][j+1]->color/10;
        fivenum[1]=a[i][j+2]->color/10;
        fivenum[2]=a[i][j]->color/10;
        fivenum[3]=a[i-2][j]->color/10;
        fivenum[4]=a[i-1][j]->color/10;

        focus->color+=30;
        for(int k=0;k<2;k++){
            Destroy *d;

            switch(fivenum[k]){
            case 0:
            a[i][j+k+1]->color=0;
            break;
            case 1:
                d=new fourH;
                d->boom(a,a[i][j+k+1]);
                delete d;
                break;
            case 2:
                d=new fourV;
                d->boom(a,a[i][j+1+k]);
                delete d;
                break;
            case 3:
                d=new nine;
                d->boom(a,a[i][j+1+k]);
                delete d;
                break;

            default:
            break;
            }
            }
        for(int k=0;k<2;k++){
            Destroy *d;

            switch(fivenum[k+3]){
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

    case 4:
        if(j>0&&num==a[i][j-1]->color%10)
            a[i][j-1]->color=0;
        if(i>0&&num==a[i-1][j]->color%10)
            a[i-1][j]->color=0;
        fivenum[0]=a[i][j+1]->color/10;
        fivenum[1]=a[i][j+2]->color/10;
        fivenum[2]=a[i][j]->color/10;
        fivenum[3]=a[i+1][j]->color/10;
        fivenum[4]=a[i+2][j]->color/10;

        for(int k=0;k<2;k++){
            Destroy *d;

            switch(fivenum[k]){
            case 0:
            a[i][j+k+1]->color=0;
            break;
            case 1:
                d=new fourH;
                d->boom(a,a[i][j+k+1]);
                delete d;
                break;
            case 2:
                d=new fourV;
                d->boom(a,a[i][j+k+1]);
                delete d;
                break;
            case 3:
                d=new nine;
                d->boom(a,a[i][j+1+k]);
                delete d;
                break;

            default:
            break;
            }
            }
        for(int k=0;k<2;k++){
            Destroy *d;

            switch(fivenum[k+3]){
            case 0:
            a[i+k+1][j]->color=0;
            break;
            case 1:
                d=new fourH;
                d->boom(a,a[i+k+1][j]);
                delete d;
                break;
            case 2:
                d=new fourV;
                d->boom(a,a[i+k+1][j]);
                delete d;
                break;
            case 3:
                d=new nine;
                d->boom(a,a[i+k+1][j]);
                delete d;
                break;

            default:
            break;
            }
            }
        break;
       case 5:

            fivenum[0]=a[i][j-2]->color/10;
            fivenum[1]=a[i][j-1]->color/10;
            fivenum[2]=a[i][j]->color/10;
            fivenum[3]=a[i-1][j]->color/10;
             fivenum[4]=a[i+1][j]->color/10;


            for(int k=0;k<2;k++){
                Destroy *d;

                switch(fivenum[k]){
                case 0:
                a[i][j+k-2]->color=0;
                break;
                case 1:
                    d=new fourH;
                    d->boom(a,a[i][j+k-2]);
                    delete d;
                    break;
                case 2:
                    d=new fourV;
                    d->boom(a,a[i][j+k-2]);
                    delete d;
                    break;
                case 3:
                    d=new nine;
                    d->boom(a,a[i][j+k-2]);
                    delete d;
                    break;

                default:
                break;
                }

            }
            for(int k=0;k<2;k=k++){
                Destroy *d;

                switch(fivenum[k+3]){
                case 0:
                a[i+k-1][j]->color=0;
                break;
                case 1:
                    d=new fourH;
                    d->boom(a,a[i+2*k-1][j]);
                    delete d;
                    break;
                case 2:
                    d=new fourV;
                    d->boom(a,a[i+2*k-1][j]);
                    delete d;
                    break;
                case 3:
                    d=new nine;
                    d->boom(a,a[i+2*k-1][j]);
                    delete d;
                    break;

                default:
                break;
                }

            }
        break;

    case 6:

         fivenum[0]=a[i][j+1]->color/10;
         fivenum[1]=a[i][j+2]->color/10;
         fivenum[2]=a[i][j]->color/10;
         fivenum[3]=a[i-1][j]->color/10;
         fivenum[4]=a[i+1][j]->color/10;


         for(int k=0;k<2;k++){
             Destroy *d;

             switch(fivenum[k]){
             case 0:
             a[i][j+k+1]->color=0;
             break;
             case 1:
                 d=new fourH;
                 d->boom(a,a[i][j+k+1]);
                 delete d;
                 break;
             case 2:
                 d=new fourV;
                 d->boom(a,a[i][j+k+1]);
                 delete d;
                 break;
             case 3:
                 d=new nine;
                 d->boom(a,a[i][j+k+1]);
                 delete d;
                 break;

             default:
             break;
             }

         }
         for(int k=0;k<2;k++){
             Destroy *d;

             switch(fivenum[k+3]){
             case 0:
             a[i+2*k-1][j]->color=0;
             break;
             case 1:
                 d=new fourH;
                 d->boom(a,a[i+2*k-1][j]);
                 delete d;
                 break;
             case 2:
                 d=new fourV;
                 d->boom(a,a[i+2*k-1][j]);
                 delete d;
                 break;
             case 3:
                 d=new nine;
                 d->boom(a,a[i+2*k-1][j]);
                 delete d;
                 break;

             default:
             break;
             }

         }
     break;
    case 7:

         fivenum[0]=a[i][j-1]->color/10;
          fivenum[1]=a[i][j+1]->color/10;
         fivenum[2]=a[i][j]->color/10;
          fivenum[3]=a[i-2][j]->color/10;
          fivenum[4]=a[i-1][j]->color/10;


         for(int k=0;k<2;k++){
             Destroy *d;

             switch(fivenum[k]){
             case 0:
             a[i][j+2*k-1]->color=0;
             break;
             case 1:
                 d=new fourH;
                 d->boom(a,a[i][j+2*k-1]);
                 delete d;
                 break;
             case 2:
                 d=new fourV;
                 d->boom(a,a[i][j+2*k-1]);
                 delete d;
                 break;
             case 3:
                 d=new nine;
                 d->boom(a,a[i][j+2*k-1]);
                 delete d;
                 break;

             default:
             break;
             }

         }
         for(int k=0;k<2;k++){
             Destroy *d;

             switch(fivenum[k+3]){
             case 0:
             a[i+k-2][j]->color=0;
             break;
             case 1:
                 d=new fourH;
                 d->boom(a,a[i+k-2][j]);
                 delete d;
                 break;
             case 2:
                 d=new fourV;
                 d->boom(a,a[i+k-2][j]);
                 delete d;
                 break;
             case 3:
                 d=new nine;
                 d->boom(a,a[i+k-2][j]);
                 delete d;
                 break;

             default:
             break;
             }

         }
     break;

    case 8:

         fivenum[0]=a[i][j-1]->color/10;
         fivenum[1]=a[i][j+1]->color/10;
         fivenum[2]=a[i][j]->color/10;
         fivenum[3]=a[i+1][j]->color/10;
         fivenum[4]=a[i+2][j]->color/10;

         for(int k=0;k<2;k++){
             Destroy *d;

             switch(fivenum[k]){
             case 0:
             a[i][j+2*k-1]->color=0;
             break;
             case 1:
                 d=new fourH;
                 d->boom(a,a[i][j+2*k-1]);
                 delete d;
                 break;
             case 2:
                 d=new fourV;
                 d->boom(a,a[i][j+2*k-1]);
                 delete d;
                 break;
             case 3:
                 d=new nine;
                 d->boom(a,a[i][j+2*k-1]);
                 delete d;
                 break;

             default:
             break;
             }

         }
         for(int k=0;k<2 ;k++){
             Destroy *d;

             switch(fivenum[k+3]){
             case 0:
             a[i+k+1][j]->color=0;
             break;
             case 1:
                 d=new fourH;
                 d->boom(a,a[i+k+1][j]);
                 delete d;
                 break;
             case 2:
                 d=new fourV;
                 d->boom(a,a[i+k+1][j]);
                 delete d;
                 break;
             case 3:
                 d=new nine;
                 d->boom(a,a[i+k+1][j]);
                 delete d;
                 break;

             default:
             break;
             }

         }
     break;


    }
focus->color+=30;
}

void nine::boom(basic *a[Row][Col], basic *focus){
    Destroy *d;
    int i=focus->row;
    int j=focus->col;

    focus->color=0;
    int eightnum[8]={0};
    if(i>0&&j>0&&a[i-1][j-1]->color/10!=0)    {eightnum[0]=a[i-1][j-1]->color/10;}
    if(i>0&&a[i-1][j]->color/10!=0)           {eightnum[1]=a[i-1][j]->color/10;}
    if(i>0&&j<Col-1&&a[i-1][j+1]->color/10!=0){eightnum[2]=a[i-1][j+1]->color/10;}
    if(j>0&&a[i][j-1]->color/10!=0)           {eightnum[3]=a[i][j]->color/10;}
    if(j<Col-1&&a[i][j+1]->color/10!=0)       {eightnum[4]=a[i][j]->color/10;}
    if(i<Row-1&&j>0&&a[i+1][j-1]->color/10!=0){eightnum[5]=a[i][j]->color/10;}
    if(i<Row-1&&a[i+1][j]->color/10!=0)       {eightnum[6]=a[i][j]->color/10;}
    if(i<Row-1&&j<Row-1&&a[i+1][j+1]->color/10!=0){eightnum[7]=a[i][j]->color/10;}

    if(i>0&&j>0){
        switch (eightnum[0]) {
        case 0:
            a[i-1][j-1]->color=0;
            break;
        case 1:
            d=new fourH;
            d->boom(a, a[i-1][j-1]);
            delete d;
            break;
        case 2:
            d=new fourV;
            d->boom(a, a[i-1][j-1]);
            delete d;
            break;

        case 3:
            d=new nine;
            d->boom(a, a[i-1][j-1]);
            delete d;
            break;
        default:
            break;
        }
    }

    if(i>0){
        switch (eightnum[1]) {
        case 0:
            a[i-1][j]->color=0;
            break;
        case 1:
            d=new fourH;
            d->boom(a, a[i-1][j]);
            delete d;
            break;
        case 2:
            d=new fourV;
            d->boom(a, a[i-1][j]);
            delete d;
            break;

        case 3:
            d=new nine;
            d->boom(a, a[i-1][j]);
            delete d;
            break;
        default:
            break;
        }
    }
    if(i>0&&j<Col-1){
        switch (eightnum[2]) {
        case 0:
            a[i-1][j+1]->color=0;
            break;
        case 1:
            d=new fourH;
            d->boom(a, a[i-1][j+1]);
            delete d;
            break;
        case 2:
            d=new fourV;
            d->boom(a, a[i-1][j+1]);
            delete d;
            break;

        case 3:
            d=new nine;
            d->boom(a, a[i-1][j+1]);
            delete d;
            break;
        default:
            break;
        }
    }

    if(j>0){
        switch (eightnum[3]) {
        case 0:
            a[i][j-1]->color=0;
            break;
        case 1:
            d=new fourH;
            d->boom(a, a[i][j-1]);
            delete d;
            break;
        case 2:
            d=new fourV;
            d->boom(a, a[i][j-1]);
            delete d;
            break;

        case 3:
            d=new nine;
            d->boom(a, a[i][j-1]);
            delete d;
            break;
        default:
            break;
        }
    }
    if(j<Col-1){
        switch (eightnum[4]) {
        case 0:
            a[i][j+1]->color=0;
            break;
        case 1:
            d=new fourH;
            d->boom(a, a[i][j+1]);
            delete d;
            break;
        case 2:
            d=new fourV;
            d->boom(a, a[i][j+1]);
            delete d;
            break;

        case 3:
            d=new nine;
            d->boom(a, a[i][j+1]);
            delete d;
            break;
        default:
            break;
        }
    }
    if(i<Row-1&&j>0){
        switch (eightnum[5]) {
        case 0:
            a[i+1][j-1]->color=0;
            break;
        case 1:
            d=new fourH;
            d->boom(a, a[i+1][j-1]);
            delete d;
            break;
        case 2:
            d=new fourV;
            d->boom(a, a[i+1][j-1]);
            delete d;
            break;

        case 3:
            d=new nine;
            d->boom(a, a[i+1][j-1]);
            delete d;
            break;
        default:
            break;
        }
    }

    if(i<Row-1){
        switch (eightnum[6]) {
        case 0:
            a[i+1][j]->color=0;
            break;
        case 1:
            d=new fourH;
            d->boom(a, a[i+1][j]);
            delete d;
            break;
        case 2:
            d=new fourV;
            d->boom(a, a[i+1][j]);
            delete d;
            break;

        case 3:
            d=new nine;
            d->boom(a, a[i+1][j]);
            delete d;
            break;
        default:
            break;
        }
    }


    if(i<Row-1&&j<Col-1){
        switch (eightnum[7]) {
        case 0:
            a[i+1][j+1]->color=0;
            break;
        case 1:
            d=new fourH;
            d->boom(a, a[i+1][j+1]);
            delete d;
            break;
        case 2:
            d=new fourV;
            d->boom(a, a[i+1][j+1]);
            delete d;
            break;

        case 3:
            d=new nine;
            d->boom(a, a[i+1][j+1]);
            delete d;
            break;
        default:
            break;
        }
    }


}


nine::~nine()
{

}

