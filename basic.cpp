#include "basic.h"
#include <ctime>
#include <cstdlib>

/*
int boardarray[Row][Col]={{2,1,3,4,3,1,5,3,5},
                       {1,2,2,4,3,5,3,4,3},
                       {5,2,4,2,5,3,3,5,1},
                       {2,4,5,3,3,1,1,2,2},
                       {1,2,4,5,5,2,2,1,2},
                       {3,3,2,5,3,4,1,2,5},
                       {3,4,3,2,4,5,5,3,1},
                       {2,3,1,5,5,3,1,1,5},
                       {5,3,1,5,3,1,4,4,3}};
*/

basic::basic(QWidget *parent ,int i,int j): QObject(parent),row(i),
col(j)
{
    srand(time(NULL));
    button=new QPushButton(parent);
    button->setGeometry(50*col+50,50*row+50,50,50);
    button->setFlat(true);
    button->setStyleSheet("border:1px solid;");
    button->setIconSize(button->size());
    connect(button,SIGNAL(clicked()),this ,SLOT(click()));
    //Turn=turn;

    //QString s;
    //s = QString :: number(boardarray[i][j],10);
    //button->setIcon(QIcon(QPixmap("/Porotorayado")));;
    /*

*/

    //button->setText(s);



}

basic::~basic()
{

}


void basic::click()
{
    emit Click( row, col);
}

void basic::setrandcolor(){

    color=rand()%5+1;

}

void basic::setpicture(){
    switch (color) {
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

    case 11:
        button->setIcon(QIcon(QPixmap(":/red1.png")));
        break;
    case 12:
        button->setIcon(QIcon(QPixmap(":/orange1.png")));
        break;
    case 13:
        button->setIcon(QIcon(QPixmap(":/yellow1.png")));
        break;
    case 14:
        button->setIcon(QIcon(QPixmap(":/green1.png")));
        break;
    case 15:
        button->setIcon(QIcon(QPixmap(":/blue1.png")));
        break;

    case 21:
        button->setIcon(QIcon(QPixmap(":/red2.png")));
        break;
    case 22:
        button->setIcon(QIcon(QPixmap(":/orange2.png")));
        break;
    case 23:
        button->setIcon(QIcon(QPixmap(":/yellow2.png")));
        break;
    case 24:
        button->setIcon(QIcon(QPixmap(":/green2.png")));
        break;
    case 25:
        button->setIcon(QIcon(QPixmap(":/blue2.png")));
        break;

    case 31:
        button->setIcon(QIcon(QPixmap(":/red3.png")));
        break;
    case 32:
        button->setIcon(QIcon(QPixmap(":/orange3.png")));
        break;
    case 33:
        button->setIcon(QIcon(QPixmap(":/yellow3.png")));
        break;
    case 34:
        button->setIcon(QIcon(QPixmap(":/green3.png")));
        break;
    case 35:
        button->setIcon(QIcon(QPixmap(":/blue3.png")));
        break;
    case 50:
        button->setIcon(QIcon(QPixmap(":/chocolate.png")));
        break;
    default:
        button->setIcon(QIcon(QPixmap("NO pic")));
        break;
    }

}

//上下(下在前)
void basic::operator +(basic *a){
    int temp=a->color;
    a->color=color;
    color=temp;
    setpicture();
    a->setpicture();

}
//左右(佐在後)
void basic::operator -(basic *a){
    int temp=a->color;
    a->color=color;
    color=temp;
    setpicture();
    a->setpicture();

}
