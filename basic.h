#ifndef BASIC_H
#define BASIC_H

#include <QObject>
#include <QPushButton>
#include<Qstring.h>
#include <QTime>

#define Row 10
#define Col 10

class basic:public QObject
{
    Q_OBJECT
public:
    explicit basic(QWidget *parent ,int i,int j);
    ~basic();
    QPushButton *button;

    void setrandcolor();
    void setpicture();

    const int row;
    const int col;
    int color;
    void operator -(basic *a);
    void operator +(basic *a);
signals:
    void Click(int,int);

public slots:
    void click();
private:
    //bool putzero[i][j];

    //int *Turn;

};

#endif // BASIC_H
