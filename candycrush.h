#ifndef CANDYCRUSH_H
#define CANDYCRUSH_H

#include "basic.h"
#include <QPainter>
#include <QMainWindow>
#include <QMouseEvent>



namespace Ui {
class candycrush;
}

class candycrush : public QMainWindow
{
    Q_OBJECT

public:
    explicit candycrush(QWidget *parent = 0);
    ~candycrush();
private slots:
    void basicClick();

private:
    basic *objectarray[Row][Col];
    int turn;
    Ui::candycrush *ui;
};

#endif // CANDYCRUSH_H
