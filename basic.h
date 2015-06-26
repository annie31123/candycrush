#ifndef BASIC_H
#define BASIC_H

#include <QObject>
#include <QPushButton>
#include<Qstring.h>
#define Row 9
#define Col 9

class basic:public QObject
{
    Q_OBJECT
public:
    explicit basic(QWidget *parent ,int i,int j);
    ~basic();
    bool checkall();
    bool check4();
    bool check5();
    bool checkL();
    bool check3();

    void breakspecial(int i,int j);

    void break4v(int i,int j);
    void break4h(int i,int j);
    void break5(int i,int j);
    void breakL(int i,int j);
    int giveboardarray(int i,int j);
    QPushButton *button;
signals:
    void Click();

public slots:
    void click();
private:
    //bool putzero[i][j];

    const int row;
    const int col;
    //int *Turn;


};

#endif // BASIC_H
