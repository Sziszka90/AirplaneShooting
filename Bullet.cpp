#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include "Enemy.h"
#include "Bullet.h"
#include <QTimer>
#include "Game.h"

extern Game * game; // there is an external global object called game

Bullet::Bullet(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    //draw the rect
    setPixmap(QPixmap(":/images/bullet.png"));


    //connect
    QTimer * timer = new QTimer();
    //every timeout signal the move() will be called
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);

}

void Bullet::move()
{
    //if bullet collides with enemy, destroy both
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for(int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            //increase the score
            game->score->increase();
            //remove both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //move bullet up
    setPos(x(),y()-10);
    if(pos().y() < -60){
        scene()->removeItem(this);
        delete this;
    }

}
