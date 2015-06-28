#include "start.h"
#include "ui_start.h"
#include "candycrush.h"

start::start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);
}

start::~start()
{
    delete ui;
}

void start::on_pushButton_clicked()

{
    w.show();
    this->hide();

}
