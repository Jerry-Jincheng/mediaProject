#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include "world.h"


class Environment: public QObject, public Tile
{
public:
    Environment(int xPosition, int yPosition, float value);
};

#endif // ENVIRONMENT_H
