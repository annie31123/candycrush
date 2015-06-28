#ifndef OVER_H
#define OVER_H

#include <QWidget>

namespace Ui {
class over;
}

class over : public QWidget
{
    Q_OBJECT

public:
    explicit over(QWidget *parent = 0);
    ~over();
    int game;
    int score;
    void gameover();

private:
   Ui::over *ui;
};

#endif // OVER_H
