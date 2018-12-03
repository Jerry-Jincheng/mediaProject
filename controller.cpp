#include "controller.h"
#include "protagonistview.h"
#include <QTimer>
#include <iostream>

Controller::Controller()
{
    //create world, protagonist, enemies
    world = std::make_shared<World>();
    QString filename = ":/maze1.png";
    tiles = world->createWorld(filename);
    protagonist = world->getProtagonist();//Tile(0, 0, 0.0f), health{100.0f}, energy{100.0f}
    createEnemies();

    //create protagonist view, enemy view for normal enemies, penemy view for penemies
    protagonistView = std::make_unique<ProtagonistView>();
    enemyView = std::make_unique<EnemyView>();
    penemyView = std::unique_ptr<PEnemyView>();

    //create pathfinder
    finder = new Pathfinder(tiles,world->getCols(),world->getRows());
}

Controller::~Controller()
{

}

void Controller::protagonistController()
{
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
    float newHealth,newEnegy;
    //move right
    protagonist->setXPos(protagonist->getXPos()+10);
    int x = protagonist->getXPos();
    int y = protagonist->getYPos();

    //check the position if there is normal enemy
    for(auto &e:enemies)
    {
        if(x==e->getXPos()&&y==e->getYPos())//clision with normal enermy
        {
            //decrease health
            newHealth = protagonist->getHealth()-e->getValue();
            if(newHealth>0)//protagonist wins
            {
                protagonist->setHealth(newHealth);
                //TODO distroy enemy
            }
            else
            {
                //TODO game over
            }
        }
    }

    //check check the value of difficulty
    newEnegy = protagonist->getEnergy()-tiles[x+y]->getValue();
    protagonist->setEnergy(newEnegy);

    //update view
    protagonistView->textView(x,y,protagonist->getHealth(),protagonist->getEnergy(), tiles);
}

void Controller::enemyController()
{
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
    for(auto &pe:penemies)
    {
        penemyView->textView(pe->getXPos(),pe->getYPos(),pe->getValue());
    }
}

void Controller::testFinder()
{
//    int x=3, y=4, x1=15, y1=20;
//    finder->find(tiles.at(y*))
}
