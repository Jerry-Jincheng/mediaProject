#ifndef COMSUMABLE_H
#define COMSUMABLE_H
#include "world.h"


class Consumable: public QObject, public Tile
{
public:
    Consumable(int xPosition, int yPosition, float value);
};

#endif // COMSUMABLE_H
