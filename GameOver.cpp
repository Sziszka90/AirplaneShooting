#include "GameOver.h"
#include <QGraphicsTextItem>
#include <QFont>

void GameOver::GameOverAction()
{
    // draw the text
    setPlainText(QString("GAME OVER"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",50));

}
