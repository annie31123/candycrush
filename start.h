#ifndef START_H
#define START_H
#include "candycrush.h"
#include <QWidget>

namespace Ui {
class start;
}

class start : public QWidget
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = 0);
    ~start();

private slots:
    void on_pushButton_clicked();

private:
    Ui::start *ui;
    candycrush w;
};

#endif // START_H
