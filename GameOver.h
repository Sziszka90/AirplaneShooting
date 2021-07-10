#ifndef GAMEOVER_H
#define GAMEOVER_H

#include<QGraphicsTextItem>

class GameOver: public QGraphicsTextItem{
public:
    void GameOverAction();
    bool gameOverFlag;
};

#endif // GAMEOVER_H
