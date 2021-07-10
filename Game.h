#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Life.h"
#include "GameOver.h"

class Game:public QGraphicsView{
public:

    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Life * life;
    GameOver * gameover;
};

#endif // GAME_H
