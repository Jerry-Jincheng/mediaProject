#include "controller.h"
#include "protagonistview.h"
#include <QTimer>
#include <iostream>

Controller::Controller()
{
    World *world = new World();
    QString filename = ":/maze1.png";
    tiles = world->createWorld(filename);
}

Controller::~Controller()
{

}

void Controller::protagonistController()
{
    //create protagonist
    protagonist = world->getProtagonist();//Tile(0, 0, 0.0f), health{100.0f}, energy{100.0f}
    protagonistView = new ProtagonistView();

    //connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveProtagonistRight()));

    timer->start(1000);

}

void Controller::moveProtagonistRight()
{
    //move left
    protagonist->setXPos(protagonist->getXPos()+10);
    int x = protagonist->getXPos();
    int y = protagonist->getYPos();
    float health = protagonist->getHealth();
    float energy = protagonist->getEnergy();


    protagonistView->textView(x,y,health,energy);

}


//    enemies = world->getEnemies(2);

    //enermiess
//    int i=0;
//    for(auto &e:enemies)
//    {
//        e->setXPos(5+i);
//        e->setYPos(5+i);
//        i+=10;
//        //std::cout<<"enermy"<<e->getXPos()<<std::endl;
//    }
