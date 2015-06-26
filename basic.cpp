#include "basic.h"



int boardarray[Row][Col]={{2,1,3,4,3,1,5,3,5},
                       {1,2,2,4,3,5,3,4,3},
                       {5,2,4,2,5,3,3,5,1},
                       {2,4,5,3,3,1,1,2,2},
                       {1,2,4,5,5,2,2,1,2},
                       {3,3,2,5,3,4,1,2,5},
                       {3,4,3,2,4,5,5,3,1},
                       {2,3,1,5,5,3,1,1,5},
                       {5,3,1,5,3,1,4,4,3}};
int first[2]={10,10};
int second[2]={10,10};

basic::basic(QWidget *parent ,int i,int j): QObject(parent),row(i),
col(j)
{

    button=new QPushButton(parent);
    button->setGeometry(50*row+50,50*col+50,50,50);
    button->setFlat(true);
    button->setStyleSheet("border:1px solid;");
    button->setIconSize(button->size());
    //Turn=turn;

    //QString s;
    //s = QString :: number(boardarray[i][j],10);
    //button->setIcon(QIcon(QPixmap("/Porotorayado")));;

    switch (boardarray[row][col]) {
    case 1:
        button->setIcon(QIcon(QPixmap(":/red.png")));
        break;
    case 2:
        button->setIcon(QIcon(QPixmap(":/orange.png")));
        break;
    case 3:
        button->setIcon(QIcon(QPixmap(":/yellow.png")));
        break;
    case 4:
        button->setIcon(QIcon(QPixmap(":/green.png")));
        break;
    case 5:
        button->setIcon(QIcon(QPixmap(":/blue.png")));
        break;
    default:
        break;
    }


    //button->setText(s);
    connect(button,SIGNAL(clicked()),this ,SLOT(click()));


}

basic::~basic()
{

}

int basic::giveboardarray(int i, int j){
    return boardarray[i][j];
}

void basic::click()
{   first[0]=second[0];
    first[1]=second[1];
    second[1]=row;
    second[2]=col;

    if (first[0]==10||first[1]==10)
        return;

    if(first[0]==second[0]+1||first[0]==second[0]-1){
        if(first[1]==second[1]){
            int a[2];
            a[0]=first[0];
            a[1]=first[1];
            first[1]=second[1];
            first[0]=second[2];
            second[0]=a[0];
            second[1]=a[1];
            if(!checkall()){

                int a[2];
                a[0]=first[0];
                a[1]=first[1];
                first[1]=second[1];
                first[0]=second[2];
                second[0]=a[0];
                second[1]=a[1];
            }
        }
    }else if(first[1]==second[1]+1||first[1]==second[1]-1)
        if(first[0]==second[0]){

            int a[2];
            a[0]=first[0];
            a[1]=first[1];
            first[1]=second[1];
            first[0]=second[2];
            second[0]=a[0];
            second[1]=a[1];

            if(!checkall()){

                int a[2];
                a[0]=first[0];
                a[1]=first[1];
                first[1]=second[1];
                first[0]=second[2];
                second[0]=a[0];
                second[1]=a[1];
            }
        }
    emit Click();
}

bool basic::checkall(){
    bool a=false;
    a=check5();
    a=checkL();
    a=check4();
    a=check3();

    if(a==true)
        return true;
    else
        return false;
}


bool basic::check3(){
    bool a=false;
    for (int i=0;i<Row;i++)
        for(int j=0;j<Col-2;j++)
            if(boardarray[i][j])
            if(boardarray[i][j]%10==boardarray[i][j+1]%10 && boardarray[i][j+1]%10==boardarray[i][j+2]%10)
            {
                a=true;
                for(int k=0;k<3;k++)
                    breakspecial(i,j+k);
            }


    for (int j=0;j<Col;j++)
        for(int i=0;i<Row-2;i++)
            if(boardarray[i][j])
            if(boardarray[i][j]%10==boardarray[i+1][j]%10 && boardarray[i+1][j]%10==boardarray[i+2][j]%10)
            {
                a=true;
                for(int k=0;k<3;k++)
                    breakspecial(i+k,j);
            }

    if(a==true)
        return true;
    else
        return false;

}


bool basic::check4(){
    bool a=false;
    int savecolor=0;
    for (int i=0;i<Row;i++)
        for(int j=0;j<Col-3;j++)
            if(boardarray[i][j])
            if(boardarray[i][j]%10==boardarray[i][j+1]%10 && boardarray[i][j+1]%10==boardarray[i][j+2]%10 &&boardarray[i][j+2]%10==boardarray[i][j+3]%10)
            {
                a=true;
                savecolor=boardarray[i][j];
                for(int k=0;k<4;k++)
                    breakspecial(i,j+k);
                boardarray[i][j]=savecolor+10;
                savecolor=0;
            }

    for (int j=0;j<Col;j++)
        for(int i=0;i<Row-3;i++)
            if(boardarray[i][j])
            if(boardarray[i][j]%10==boardarray[i+1][j]%10 && boardarray[i][j]%10==boardarray[i+2][j]%10 &&boardarray[i][j]%10==boardarray[i+3][j]%10)
            {
                a=true;
                savecolor=boardarray[i][j];
                for(int k=0;k<4;k++)
                    breakspecial(i+k,j);
                boardarray[i][j]=savecolor+20;
                savecolor=0;

            }

    if(a==true)
        return true;
    else
        return false;

}


bool basic::check5(){
    bool a=false;
    for (int i=0;i<Row;i++)
        for(int j=0;j<Col-4;j++)
            if(boardarray[i][j])
            if(boardarray[i][j]%10==boardarray[i][j+1]%10 && boardarray[i][j+1]%10==boardarray[i][j+2]%10 &&boardarray[i][j+2]%10==boardarray[i][j+3]%10&&boardarray[i][j]%10==boardarray[i][j+4]%10)
            {
                a=true;
                for(int k=0;k<5;k++)
                    breakspecial(i,j+k);
                boardarray[i][j]=50;

            }
    for (int j=0;j<Col;j++)
        for(int i=0;i<Row-4;i++)
            if(boardarray[i][j])
            if(boardarray[i][j]%10==boardarray[i+1][j]%10 && boardarray[i][j]%10==boardarray[i+2][j]%10 &&boardarray[i][j]%10==boardarray[i+3][j]%10&&boardarray[i][j]%10==boardarray[i+4][j]%10)
            {
                a=true;
                for(int k=0;k<5;k++)
                    breakspecial(i,j+k);
                boardarray[i][j]=50;

            }


    if(a==true)
        return true;
    else
        return false;

}


bool basic::checkL(){
    bool a=false;

    int savecolor=0;
    //left up
    for (int i=0;i<Row-2;i++)
        for(int j=0;j<Col-2;j++)
            if(boardarray[i][j])
            if(boardarray[i][j]%10==boardarray[i][j+1]%10 && boardarray[i][j+1]%10==boardarray[i][j+2]%10&&boardarray[i][j]%10==boardarray[i+1][j]%10 && boardarray[i+1][j]%10==boardarray[i+2][j]%10)
            {

                a=true;
                savecolor=boardarray[i][j];

                breakspecial(i,j);
                breakspecial(i,j+1);
                breakspecial(i,j+2);
                breakspecial(i+1,j);
                breakspecial(i+2,j);

                boardarray[i][j]=savecolor+30;
                savecolor=0;
            }

    //right up
    for (int i=0;i<Row-2;i++)
        for(int j=2;j<Col;j++)
            if(boardarray[i][j])
            if(boardarray[i][j]%10==boardarray[i][j-1]%10 && boardarray[i][j-1]%10==boardarray[i][j-2]%10&&boardarray[i][j]%10==boardarray[i+1][j]%10 && boardarray[i+1][j]%10==boardarray[i+2][j]%10)
            {

                a=true;
                savecolor=boardarray[i][j];
                breakspecial(i,j);
                breakspecial(i,j-1);
                breakspecial(i,j-2);
                breakspecial(i+1,j);
                breakspecial(i+2,j);
                boardarray[i][j]=savecolor+30;
                savecolor=0;
            }

    //left down
    for (int i=2;i<Row;i++)
        for(int j=0;j<Col-2;j++)
            if(boardarray[i][j])
            if(boardarray[i][j]%10==boardarray[i][j+1]%10 && boardarray[i][j+1]%10==boardarray[i][j+2]%10&&boardarray[i][j]%10==boardarray[i-1][j]%10 && boardarray[i-1][j]%10==boardarray[i-2][j]%10)
            {

                a=true;
                savecolor=boardarray[i][j];
                breakspecial(i,j);
                breakspecial(i,j+1);
                breakspecial(i,j+2);
                breakspecial(i-1,j);
                breakspecial(i-2,j);
                boardarray[i][j]=savecolor+30;
                savecolor=0;
            }

    //right down
    for (int i=2;i<Row;i++)
        for(int j=2;j<Col;j++)
            if(boardarray[i][j])
            if(boardarray[i][j]%10==boardarray[i][j-1]%10 && boardarray[i][j-1]%10==boardarray[i][j-2]%10&&boardarray[i][j]%10==boardarray[i-1][j]%10 && boardarray[i-1][j]%10==boardarray[i-2][j]%10)
            {

                a=true;
                savecolor=boardarray[i][j];
                breakspecial(i,j);
                breakspecial(i,j-1);
                breakspecial(i,j-2);
                breakspecial(i-1,j);
                breakspecial(i-2,j);
                boardarray[i][j]=savecolor+30;
                savecolor=0;
            }



    //T down
    for(int i=0;i<Row;i++)
        for(int j=1;j<Col-1;j++)
            if(boardarray[i][j])
            if(boardarray[i][j]%10==boardarray[i][j-1]%10&&boardarray[i][j]%10==boardarray[i][j+1]%10&&boardarray[i][j]%10==boardarray[i+1][j]%10&&boardarray[i][j]%10==boardarray[i+2][j]%10){

                a=true;
                savecolor=boardarray[i][j];
                breakspecial(i,j);
                breakspecial(i,j-1);
                breakspecial(i,j+1);
                breakspecial(i+1,j);
                breakspecial(i+2,j);
                boardarray[i][j]=savecolor+30;
                savecolor=0;

            }


    //T up
    for(int i=2;i<Row;i++)
        for(int j=1;j<Col-1;j++)
            if(boardarray[i][j])
            if(boardarray[i][j]%10==boardarray[i][j-1]%10&&boardarray[i][j]%10==boardarray[i][j+1]%10&&boardarray[i][j]%10==boardarray[i-1][j]%10&&boardarray[i][j]%10==boardarray[i-2][j]%10){
                 a=true;
                savecolor=boardarray[i][j];
                breakspecial(i,j);
                breakspecial(i,j-1);
                breakspecial(i,j+1);
                breakspecial(i-1,j);
                breakspecial(i-2,j);
                boardarray[i][j]=savecolor+30;
                savecolor=0;

            }

    //T left
    for(int i=1;i<Row-1;i++)
        for(int j=2;j<Col;j++)
            if(boardarray[i][j])
            if(boardarray[i][j]%10==boardarray[i][j-1]%10&&boardarray[i][j]%10==boardarray[i][j-2]%10&&boardarray[i][j]%10==boardarray[i+1][j]%10&&boardarray[i][j]%10==boardarray[i-1][j]%10){
                a=true;
                savecolor=boardarray[i][j];
                breakspecial(i,j);
                breakspecial(i,j-1);
                breakspecial(i,j-2);
                breakspecial(i+1,j);
                breakspecial(i-1,j);
                boardarray[i][j]=savecolor+30;
                savecolor=0;

            }
    //T right
    for(int i=1;i<Row-1;i++)
        for(int j=0;j<Col-2;j++)
            if(boardarray[i][j])
            if(boardarray[i][j]%10==boardarray[i][j+1]%10&&boardarray[i][j]%10==boardarray[i][j+2]%10&&boardarray[i][j]%10==boardarray[i+1][j]%10&&boardarray[i][j]%10==boardarray[i-1][j]%10){
                a=true;
                savecolor=boardarray[i][j];
                breakspecial(i,j);
                breakspecial(i,j+1);
                breakspecial(i,j+2);
                breakspecial(i+1,j);
                breakspecial(i-1,j);
                boardarray[i][j]=savecolor+30;
                savecolor=0;

            }
    if(a==true)
        return true;
    else
        return false;
}



void basic::breakspecial(int i,int j){

    int special=boardarray[i][j]/10;


     switch (special) {
        case 1:
            break4h(i,j);
            break;
        case 2:
            break4v(i,j);
            break;
        case 3:
            breakL(i,j);
            break;

        case 5:
            break5(i,j);
            break;
        default:
            break;
        }
    boardarray[i][j]=0;

}


void basic::break4h(int i, int j){
    for(int k=0;k<Col;k++)
        boardarray[i][k]=0;
}


void basic::break4v(int i, int j){
    for(int k=0;k<Row;k++)
        boardarray[k][j]=0;
}


void basic::breakL(int i, int j){
    if(i==0&&j==0){

        boardarray[i+1][j]=0;
        boardarray[i][j+1]=0;
        boardarray[i+1][j+1]=0;

    }else if(i==0&&j==8){

        boardarray[i][j-1]=0;
        boardarray[i+1][j]=0;
        boardarray[i+1][j-1]=0;

    }else if(i==0){

        boardarray[i][j-1]=0;
        boardarray[i][j+1]=0;
        boardarray[i+1][j-1]=0;
        boardarray[i+1][j]=0;
        boardarray[i+1][j+1]=0;

    }else if(j==0){

        boardarray[i-1][j]=0;
        boardarray[i+1][j]=0;
        boardarray[i-1][j+1]=0;
        boardarray[i][j+1]=0;
        boardarray[i+1][j+1]=0;

    }else if(i==8&&j==0){

        boardarray[i-1][j]=0;
        boardarray[i][j+1]=0;
        boardarray[i-1][j+1]=0;

    }else if(i==8&&j==8){

        boardarray[i-1][j]=0;
        boardarray[i][j-1]=0;
        boardarray[i-1][j-1]=0;

    }else if(i==8){

        boardarray[i][j-1]=0;
        boardarray[i][j+1]=0;
        boardarray[i+1][j-1]=0;
        boardarray[i+1][j]=0;
        boardarray[i+1][j+1]=0;

    }else if (j==8){

        boardarray[i-1][j]=0;
        boardarray[i+1][j]=0;
        boardarray[i-1][j-1]=0;
        boardarray[i][j-1]=0;
        boardarray[i+1][j-1]=0;

    }else{
        boardarray[i-1][j-1]=0;
        boardarray[i][j-1]=0;
        boardarray[i+1][j-1]=0;

        boardarray[i-1][j]=0;
        boardarray[i+1][j]=0;

        boardarray[i-1][j+1]=0;
        boardarray[i][j+1]=0;
        boardarray[i+1][j+1]=0;

    }


}


void basic::break5(int i, int j){
    int color=boardarray[i][j];
    for(int i=0;i<Row;i++)
        for(int j=0;j<Col;j++)
            if(boardarray[i][j]==color)
                boardarray[i][j]=0;
}
