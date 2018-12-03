#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "world.h"
#include "protagonistview.h"
#include "enemyview.h"
#include "penemyview.h"
#include "pathfinder.h"


class Controller: public QObject
{
    Q_OBJECT
public:
    Controller();
    virtual ~Controller();

    void protagonistController();
    void enemyController();
    void penemyController();

    void getPEnemies();

    void protagonistMove();

    void createEnemies();

    void testFinder();

public slots:
    void moveProtagonistRight();

private:
    std::shared_ptr<World> world;
//    std::vector<std::unique_ptr<Tile>> tiles;
    std::vector<std::unique_ptr<Tile>> tiles;
    std::unique_ptr<Protagonist> protagonist;
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<std::unique_ptr<PEnemy>> penemies;

    std::unique_ptr<ProtagonistView> protagonistView;
    std::unique_ptr<EnemyView> enemyView;
    std::unique_ptr<PEnemyView> penemyView;
//    std::vector<std::unique_ptr<XEnemy>> xEnemies;
    Pathfinder *finder;
};

#endif // CONTROLLER_H
