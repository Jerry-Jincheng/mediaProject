#include "mainwindow.h"
#include <QApplication>
#include <qgraphicsview.h>
#include <qgraphicsscene.h>
#include <QGraphicsRectItem>
#include <QPixmap>
#include <iostream>
#include "consumable.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    World *world = new World();
    QString filename = ":/maze1.png";


    std::vector<std::unique_ptr<Tile>> tiles = world->createWorld(filename);
    std::unique_ptr<Protagonist> protagonist = world->getProtagonist();
    std::vector<std::unique_ptr<Enemy>> enermies = world->getEnemies(2);

    //protagonist
    protagonist->setXPos(10);
    protagonist->setYPos(0);
    //protagonist->setPos(0,0);
    protagonist->setHealth(100.0);
    float health = protagonist->getHealth();
    //printf("health is: %g\n",health);
    std::cout<<health<<std::endl;

    //enermies
    int i=0;
    for(auto &e:enermies)
    {
        e->setXPos(5+i);
        e->setYPos(5+i);
        i+=10;
        //std::cout<<"enermy"<<e->getXPos()<<std::endl;
    }

    std::cout<<"protagonist at position ("<<protagonist->getXPos()<<", "<<protagonist->getYPos()
            <<"), health value = "<<protagonist->getHealth()
               <<",energy = "<<protagonist->getEnergy()<<std::endl;

//    int rows = world->getRows();
//    int cols = world->getCols();

//    for(int row=0;row<rows;row++)
//    {
////        for(int col=0;col<cols;col++)
////        {
////            float value = tiles[row+col]->getValue();
//////            *rect = new QGraphicsRectItem();
//////            rect->setRect(row,col,1,1);
//////            rect-set
//////            QGraphicsScene *scene = new QGraphicsScene();
//////            scene->addItem(rect);
//////            QGraphicsView *view = new QGraphicsView(scene);
//////            w.setCentralWidget(view);
////            w.show();


////        }
//    }


//    QGraphicsScene *scene = new QGraphicsScene();
//    scene->addPixmap(img);

//    QGraphicsView *view = new QGraphicsView(scene);

//    w.setCentralWidget(view);
    w.show();

    return a.exec();
}

//    //create an item
//    QGraphicsRectItem *rect = new QGraphicsRectItem();
//    rect->setRect(0,0,100,100);

//    //create a scene
//    QGraphicsScene *scene = new QGraphicsScene();

//    //add item to scene
//    scene->addItem(rect);

//    //create a view to visualize
//    QGraphicsView *view = new QGraphicsView(scene);

//    //show the view
//    view->show();
