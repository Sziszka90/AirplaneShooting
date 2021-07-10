#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include "Bullet.h"
#include "Enemy.h"


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/shooting.mp3"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x()>0){
            setPos(x()-10,y());
        }
    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x() + 100 < 800){
            setPos(x()+10,y());
        }
    }
    if(event->key() == Qt::Key_Space){
        //create bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

        // play bulletsound
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
    }
}

void Player::spawn()
{
    //create enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);

}
