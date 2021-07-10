#include "Life.h"
#include <QGraphicsTextItem>
#include <QFont>

Life::Life(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // initialize life to 3
    life = 3;

    // draw the text
    setPlainText(QString("Life: ") + QString::number(life)); //Life: 0
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));

}

void Life::decrease()
{
    if(life>0) {
        life--;
    };

    setPlainText(QString("Life: ") + QString::number(life)); //Life: 1
}

int Life::getLife()
{
    return life;
}
