#include "mainwindow.h"
#include <QApplication>
#include "controller.h"
#include <memory>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Controller *contr = new Controller();
    contr->protagonistController();


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
