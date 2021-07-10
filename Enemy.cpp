#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> // rand() return a large int
#include "Player.h"
#include "Game.h"

extern Game * game; // there is an external global object called game

Enemy::Enemy(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    //set random position
    srand (time(NULL));
    int random_number = rand() % 700;
    setPos(random_number,0);

    //draw the rect
    setPixmap(QPixmap(":/images/enemy.png"));

    //connect
    QTimer * timer = new QTimer();
    //every timeout signal the move() will be called
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);

}

void Enemy::move()
{
    //if bullet collides with enemy, destroy both
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for(int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Player)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            game->gameover->gameOverFlag = true;
            return;
        }
    }

    //move Enemy down
    setPos(x(),y()+3);
    if(pos().y() < -60){
        scene()->removeItem(this);
        delete this;
    }


    if(pos().y() > 600){
        game->life->decrease();
        if(game->life->getLife() == 0 && !game->gameover->gameOverFlag ) {
           game->gameover->gameOverFlag = true;
           scene()->removeItem(game->player);
           delete game->player;

        }
        scene()->removeItem(this);
        delete this;
    }

    if(game->gameover->gameOverFlag == true) {
        game->gameover->GameOverAction();
    }
}
