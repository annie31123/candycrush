#ifndef CANDYCRUSH_H
#define CANDYCRUSH_H
#include"candys.h"
#include "basic.h"
#include "over.h"
#include <QPainter>
#include <QMainWindow>
#include <QMouseEvent>
#include <QTimer>
#include <QString.h>

#define SOEASY 30
#define MEDIUM 25
#define Hard 20
namespace Ui {
class candycrush;
}

class candycrush : public QMainWindow
{
    Q_OBJECT

public:
    explicit candycrush(QWidget *parent = 0);
    ~candycrush();
    bool checkall(int first[2],int second[2]);
    bool check4h(int a[2]);
    bool check4v(int a[2]);
    bool check5(int a[2]);
    bool checkL(int a[2]);
    bool check3(int a[2]);
    void putzero();
    bool canmove();

    void reset();
    void setclickpicture();


    int first[2],second[2];
    int count;
private slots:
    void basicClick(int,int );
    //void Time();

    void on_pushButton_clicked();
signals:
    void quit(int ,int);
private:
    int score;
    int cont;

    Destroy *destroy;
    basic *objectarray[Row][Col];
    //QTimer *t;
    //int turn;
    Ui::candycrush *ui;
    over o;

};

#endif // CANDYCRUSH_H
