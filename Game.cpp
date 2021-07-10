#include "Game.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "Player.h"
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include "GameOver.h"



Game::Game(QWidget * parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/background.jpg")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    player = new Player();

    //set item parameters
    //draw the rect
    player->setPixmap(QPixmap(":/images/player.png"));
    player->setPos(400,475);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //add the item to the scene
    scene->addItem(player);

    //create the score
    score = new Score();
    scene->addItem(score);

    //create the life
    life = new Life();
    life->setPos(life->x(),life->y()+25);
    scene->addItem(life);

    gameover = new GameOver();
    gameover->gameOverFlag = false;
    gameover->setPos(200,250);
    scene->addItem(gameover);



    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    //play background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/BackgroundMusic.mp3"));
    music->play();


    show();
}
