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
              connect(objectarray[i][j],SIGNAL(Click()),this,SLOT(basicClick()));
    }}


}

candycrush::~candycrush()
{
    delete ui;
}

void candycrush::basicClick(){
    for(int i=0;i<Row;i++)
        for(int j=0;j<Col;j++){
            QString s;
            s = QString :: number(objectarray[i][j]->giveboardarray(i,j),10);
           objectarray[i][j]->button->setText(s);

        }

}
