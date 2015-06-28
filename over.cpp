#include "over.h"
#include "ui_over.h"

#include <qstring.h>
over::over(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::over)
{
    ui->setupUi(this);

}

over::~over()
{
    delete ui;
}

void over::gameover()
{
    if(game==1)
        ui->label->setText("you win");
    else
        ui ->label->setText("you lose");
    QString A;
    A = QString :: number(score,10);
    ui->score->setText(A);
    if(score<1500)
        ui->pic->setPixmap(QPixmap(":/zerostar.PNG"));
    if(score>=1500&&score<2000)
        ui->pic->setPixmap(QPixmap(":/onestar.PNG"));
    if(score>2000&&score<2500)
        ui->pic->setPixmap(QPixmap(":/twostar.PNG"));
    if(score>2500)
        ui->pic->setPixmap(QPixmap(":/threestar.PNG"));
}
