#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "world.h"
#include "protagonistview.h"


class Controller: public QObject
{
    Q_OBJECT
public:
    Controller();
    virtual ~Controller();

    void protagonistController();
public slots:
    void moveProtagonistRight();

private:
    std::unique_ptr<World> world;
    std::unique_ptr<Protagonist> protagonist;
    ProtagonistView *protagonistView;
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<std::unique_ptr<Tile>> tiles;


};

#endif // CONTROLLER_H
