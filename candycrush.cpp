
#include "candycrush.h"
#include "ui_candycrush.h"



candycrush::candycrush(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::candycrush)
{
    ui->setupUi(this);


    for(int i=0;i<Row;i++){
         for(int j=0;j<Col;j++){
             objectarray[i][j]=new basic (this,i,j);

              connect(objectarray[i][j],SIGNAL(Click(int,int)),this,SLOT(basicClick(int,int)));
    }}
    reset();
    //connect(t,SIGNAL(timeout()),this,SLOT(Time()));
    //t->start(1000);
    count=0;
    cont=SOEASY;
    QString A;
    A = QString :: number(score,10);
    ui->score->setText(A);
    QString B;
    B = QString :: number(cont,10);
    ui->count->setText(B);
}
/*
void candycrush::Time(){
    --time;
}
*/


candycrush::~candycrush()
{
    delete ui;
}

void candycrush::reset(){

    for(int i=0;i<Row;i++)
         for(int j=0;j<Col;j++){
            objectarray[i][j]->setrandcolor();
            objectarray[i][j]->setpicture();
            if(j>=2&&objectarray[i][j]->color%10==objectarray[i][j-1]->color%10 &&objectarray[i][j]->color%10==objectarray[i][j-2]->color%10)
                j--;
            if(i>=2&&objectarray[i][j]->color%10==objectarray[i-1][j]->color%10 && objectarray[i][j]->color%10==objectarray[i-2][j]->color%10)
                j--;

         }
    score=0;
    cont=SOEASY;
    QString A;
    A = QString :: number(score,10);
    ui->score->setText(A);
    QString B;
    B = QString :: number(cont,10);
    ui->count->setText(B);

}



void candycrush::basicClick(int row,int col){
     count+=1;

     if(count%2==1){

         second[0]=row;
         second[1]=col;
     }else{
         first[0]=row;
         first[1]=col;


         //上下
         if(first[0]==second[0]+1&&first[1]==second[1]){
             cont--;

             *objectarray[first[0]][first[1]]+objectarray[second[0]][second[1]];
             if(checkall(first,second)){

             }else{
                 *objectarray[second[0]][second[1]]+objectarray[first[0]][first[1]];
             }

             }

         else if(first[0]==second[0]-1&&first[1]==second[1]){
             cont--;

           *objectarray[second[0]][second[1]]+objectarray[first[0]][first[1]];
             if(checkall(first,second)){


             }
             else
                 *objectarray[second[0]][second[1]]+objectarray[first[0]][first[1]];
         }
        //左右
         else if(first[1]==second[1]+1&& first[0]==second[0]){
             cont--;

            *objectarray[first[0]][first[1]]-objectarray[second[0]][second[1]];
             if(checkall(first,second)){


             }
            else
                 *objectarray[second[0]][second[1]]-objectarray[first[0]][first[1]];
             }

          else if(first[1]==second[1]-1&& first[0]==second[0]){
             cont--;

             *objectarray[second[0]][second[1]]-objectarray[first[0]][first[1]];
             if(checkall(first,second)){



             }
             else
                *objectarray[second[0]][second[1]]-objectarray[first[0]][first[1]];
         }

         else{
             setclickpicture();
         }

     }


    /*
    int a;
    a=objectarray[first[0]][first[1]]->color;
    objectarray[first[0]][first[1]]->color=objectarray[second[0]][second[1]]->color;
    objectarray[second[0]][second[1]]->color=a;
*/


    for(int i=0;i<Row;i++)
        for(int j=0;j<Col;j++){
            objectarray[i][j]->setpicture();
        }


    QString A;
    A = QString :: number(score,10);
    ui->score->setText(A);
    QString B;
    B = QString :: number(cont,10);
    ui->count->setText(B);
    o.score=score;
    if (cont==0){
        int star=0;
        if(score<1500)
           star=0;
        if(score>=1500&&score<2000)
           star=1;
        if(score>2000&&score<2500)
            star=2;
        if(score>2500)
            star=3;
        emit quit(star,score);

        if(score>=1500)
             o.game=1;

        else
            o.game=0;

        o.score=score;
        o.gameover();
       o.show();


    }
}


void candycrush::setclickpicture(){
    for(int i=0;i<Row;i++)
        for(int j=0;j<Col;j++){
                            objectarray[i][j]->setpicture();
    }

}


bool candycrush::checkall(int one[2],int two[2]){
    int c=0;
    bool a=false;

    //50*any
    if(objectarray[one[0]][one[1]]->color==50&&objectarray[two[0]][two[1]]->color==50){
      for(int i=0;i<Row;i++)
          for(int j=0;j<Col;j++){
              objectarray[i][j]->color=0;
              objectarray[i][j]->setpicture();}
        a=true;
        score+=Row*Col*5;
    }else if(objectarray[one[0]][one[1]]->color==50){
        int color=objectarray[two[0]][two[1]]->color%10;
        for(int i=0;i<Row;i++)
            for(int j=0;j<Col;j++)
                if(objectarray[i][j]->color%10==color){
                    objectarray[i][j]->color=0;
                    objectarray[i][j]->setpicture();
                    objectarray[one[0]][one[1]]->color=0;
                    c++;
                    score+=c*5;
                }
              a=true;

    }else if(objectarray[two[0]][two[1]]->color==50){
        int color=objectarray[one[0]][one[1]]->color;
        for(int i=0;i<Row;i++)
            for(int j=0;j<Col;j++)
                if(objectarray[i][j]->color%10==color){
                    objectarray[i][j]->color=0;
                    objectarray[i][j]->setpicture();
                objectarray[two[0]][two[1]]->color=0;}
              a=true;
              c++;
              score+=c*5;
    }

    a=check5(one);
    a=check5(two);
    a=checkL(one);
    a=checkL(two);
    a=check4h(one);
    a=check4h(two);
    a=check4v(one);
    a=check4v(two);
    a=check3(one);
    a=check3(two);
   putzero();
    while(canmove()){
         remove();
         putzero();

     }
     remove();
    putzero();
     for(int i=0;i<Row;i++)
         for(int j=0;j<Col;j++)
             objectarray[i][j]->setpicture();

    return a;

}







bool candycrush::check5(int a[2]){
    bool anymake=false;
    destroy=new chocolate;
    int return_value=destroy->condiction(objectarray,objectarray[a[0]][a[1]]);
    if(return_value){
        switch (return_value) {
        case 1:
            destroy->make(objectarray,objectarray[a[0]][a[1]],1);
            anymake=true;
            break;
        case 2:
            destroy->make(objectarray,objectarray[a[0]][a[1]],2);
            anymake=true;
            break;
        default:
            break;
        }
    }
    if(anymake)
        score+=50;
    delete destroy;
    return anymake;

}
bool candycrush::check3(int a[2]){
    bool anymake=false;
    destroy=new three;
    int return_value=destroy->condiction(objectarray,objectarray[a[0]][a[1]]);
    if(return_value){
        switch (return_value) {
        case 1:
            destroy->make(objectarray,objectarray[a[0]][a[1]],1);
            anymake=true;
            break;
        case 2:
            destroy->make(objectarray,objectarray[a[0]][a[1]],2);
            anymake=true;
            break;
        case 3:
            destroy->make(objectarray,objectarray[a[0]][a[1]],3);
            anymake=true;
            break;
        case 4:
            destroy->make(objectarray,objectarray[a[0]][a[1]],4);
            anymake=true;
            break;

        case 5:
            destroy->make(objectarray,objectarray[a[0]][a[1]],5);
            anymake=true;
            break;
        case 6:
            destroy->make(objectarray,objectarray[a[0]][a[1]],6);
            anymake=true;
            break;
        case 7:
            destroy->make(objectarray,objectarray[a[0]][a[1]],7);
            anymake=true;
            break;
        case 8:
            destroy->make(objectarray,objectarray[a[0]][a[1]],8);
            anymake=true;
            break;

        case 9:
            destroy->make(objectarray,objectarray[a[0]][a[1]],9);
            anymake=true;
            break;
        case 10:
            destroy->make(objectarray,objectarray[a[0]][a[1]],10);
            anymake=true;
            break;
        case 11:
            destroy->make(objectarray,objectarray[a[0]][a[1]],11);
            anymake=true;
            break;
        case 12:
            destroy->make(objectarray,objectarray[a[0]][a[1]],12);
            anymake=true;
            break;
        default:
            break;
        }
    }
    if(anymake)
        score+=15;
    delete destroy;
    return anymake;


}


void candycrush::putzero()
{
    for(int j=0;j<10;j++ ){
          for(int i=8;i>-1;i--){
            if(objectarray[i][j]->color!=0)
              for(int k=1;k<=9-i;k++)
            if(objectarray[i+k][j]->color==0){
                objectarray[i+k][j]->color=objectarray[i+k-1][j]->color;
                objectarray[i+k-1][j]->color=0;

            }
         }}

    for(int i=0;i<Row;i++)
        for(int j=0;j<Col;j++){
            if(objectarray[i][j]->color==0){
                objectarray[i][j]->color=rand()%5+1;
                if(j>=2&&objectarray[i][j]->color%10==objectarray[i][j-1]->color%10 &&objectarray[i][j]->color%10==objectarray[i][j-2]->color%10)
                    j--;
                if(i>=2&&objectarray[i][j]->color%10==objectarray[i-1][j]->color%10 && objectarray[i][j]->color%10==objectarray[i-2][j]->color%10)
                    j--;
            }

                objectarray[i][j]->setpicture();
    }

}
bool candycrush::checkL(int a[2]){
    bool anymake=false;
    destroy=new nine;
    int return_value=destroy->condiction(objectarray,objectarray[a[0]][a[1]]);
    if(return_value){
        switch (return_value) {
        case 1:
            destroy->make(objectarray,objectarray[a[0]][a[1]],1);
            anymake=true;
            break;
        case 2:
            destroy->make(objectarray,objectarray[a[0]][a[1]],2);
            anymake=true;
            break;
        case 3:
            destroy->make(objectarray,objectarray[a[0]][a[1]],3);
            anymake=true;
            break;
        case 4:
            destroy->make(objectarray,objectarray[a[0]][a[1]],4);
            anymake=true;
            break;
        case 5:
            destroy->make(objectarray,objectarray[a[0]][a[1]],5);
            anymake=true;
            break;
        case 6:
            destroy->make(objectarray,objectarray[a[0]][a[1]],6);
            anymake=true;
            break;
        case 7:
            destroy->make(objectarray,objectarray[a[0]][a[1]],7);
            anymake=true;
            break;
        case 8:
            destroy->make(objectarray,objectarray[a[0]][a[1]],8);
            anymake=true;
            break;
        default:
            break;
        }
    }
    if(anymake)
        score+=45;
    delete destroy;
    return anymake;

}
bool candycrush::canmove(){

    for(int i=0;i<Row;i++)
        for(int j=0;j<Col-2;j++)
            if(objectarray[i][j]->color!=0&&objectarray[i][j]->color%10==objectarray[i][j+1]->color%10&&objectarray[i][j]->color%10==objectarray[i][j+2]->color%10)
            {
                return true;
            }

    for(int j=0;j<Col;j++)
        for(int i=0;i<Col-2;i++)
            if(objectarray[i][j]->color!=0&&objectarray[i][j]->color%10==objectarray[i+1][j]->color%10&&objectarray[i][j]->color%10==objectarray[i+2][j]->color%10)
            {

                return true;
            }

    return false;
}
void candycrush::remove(){

    for(int i=0;i<Row;i++)
          for(int j=0;j<Col-2;j++)
              if(objectarray[i][j]->color!=0&&objectarray[i][j]->color%10==objectarray[i][j+1]->color%10&&objectarray[i][j]->color%10==objectarray[i][j+2]->color%10)
              {

                  objectarray[i][j]->color=0;
                  objectarray[i][j+1]->color=0;
                  objectarray[i][j+2]->color=0;
                  score+=15;
              }

      for(int j=0;j<Col;j++)
          for(int i=0;i<Col-2;i++)
              if(objectarray[i][j]->color!=0&&objectarray[i][j]->color%10==objectarray[i+1][j]->color%10&&objectarray[i][j]->color%10==objectarray[i+2][j]->color%10)
              {
                  objectarray[i][j]->color=0;
                  objectarray[i+1][j]->color=0;
                  objectarray[i+2][j]->color=0;

                      score+=15;
              }

}

bool candycrush::check4h(int a[2]){
    bool anymake=false;
    destroy=new fourH;
    int return_value=destroy->condiction(objectarray,objectarray[a[0]][a[1]]);
    if(return_value){
        switch (return_value) {
        case 1:
            destroy->make(objectarray,objectarray[a[0]][a[1]],1);
            anymake=true;
            break;
        case 2:
            destroy->make(objectarray,objectarray[a[0]][a[1]],2);
            anymake=true;
            break;
        case 3:
            destroy->make(objectarray,objectarray[a[0]][a[1]],3);
            anymake=true;
            break;
        case 4:
            destroy->make(objectarray,objectarray[a[0]][a[1]],4);
            anymake=true;
            break;
        default:
            break;
        }
    }
    if(anymake)
        score+=40;

    delete destroy;
    return anymake;

}





bool candycrush::check4v(int a[2]){
    bool anymake=false;
    destroy=new fourV;
    int return_value=destroy->condiction(objectarray,objectarray[a[0]][a[1]]);
    if(return_value){
        switch (return_value) {
        case 1:
            destroy->make(objectarray,objectarray[a[0]][a[1]],1);
            anymake=true;
            break;
        case 2:
            destroy->make(objectarray,objectarray[a[0]][a[1]],2);
            anymake=true;
            break;
        case 3:
            destroy->make(objectarray,objectarray[a[0]][a[1]],3);
            anymake=true;
            break;
        case 4:
            destroy->make(objectarray,objectarray[a[0]][a[1]],4);
            anymake=true;
            break;
        default:
            break;
        }
    }
        if(anymake)
            score+=40;
    delete destroy;
    return anymake;

}




void candycrush::on_pushButton_clicked()
{
    reset();
}
