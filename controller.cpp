#include "controller.h"
#include "protagonistview.h"
#include <QTimer>
#include <iostream>

Controller::Controller()
{
    world = std::make_shared<World>();
    QString filename = ":/maze1.png";
    tiles = world->createWorld(filename);
}

Controller::~Controller()
{

}

void Controller::protagonistController()
{
    //create protagonist view
    protagonistView = std::make_unique<ProtagonistView>();

    //create protagonist
    protagonist = world->getProtagonist();//Tile(0, 0, 0.0f), health{100.0f}, energy{100.0f}

    //move protagonist
    protagonistMove();
}

void Controller::protagonistMove()
{//TODO move by timer now
    //connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveProtagonistRight()));
    timer->start(1000);
}

void Controller::moveProtagonistRight()
{
    //move right
    protagonist->setXPos(protagonist->getXPos()+10);
    int x = protagonist->getXPos();
    int y = protagonist->getYPos();

    //TODO check the position if there is enemy
    for(auto &e:enemies)
    {
        if(x==e->getXPos()&&y==e->getYPos())//clision with normal enermy
        {
            //decrease health
            //protagonist->getHealth() =
        }

    }


    float health = protagonist->getHealth();

    //TODO check the value of difficulty
    //..

    float energy = protagonist->getEnergy();

    //update view
    protagonistView->textView(x,y,health,energy);
}

void Controller::enemyController()
{
    //create enemy view for normal enemies
    enemyView = std::make_unique<EnemyView>();

    createEnemies();

    //show normal enemy info
    for(auto &e:enemies)
    {
        enemyView->textView(e->getXPos(),e->getYPos(),e->getValue());
    }

}

void Controller::createEnemies()
{
    //create enermiesAll, include normal enemies,pEnemies (and xEnemies)
    auto enemiesAll = world->getEnemies(6);
    //seperate different typies of enemies
    for(auto &e:enemiesAll)
    {
        std::unique_ptr<PEnemy> p(dynamic_cast<PEnemy *>(e.get()));
        if(p)//check non-null ptr
        {
            //std::cout<<"this is pEnemy"<<std::endl;
            penemies.push_back(std::move(p));
            e.release();//release the ownership
        }
        else
        {
            //std::cout<<"this is normal enemy"<<std::endl;
            enemies.push_back(std::move(e));
        }
    }
}

void Controller::penemyController()
{
    //create penemy view for penemies
    penemyView = std::unique_ptr<PEnemyView>();

    for(auto &pe:penemies)
    {
        penemyView->textView(pe->getXPos(),pe->getYPos(),pe->getValue());
    }

}
