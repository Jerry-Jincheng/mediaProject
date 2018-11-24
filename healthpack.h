#ifndef HEALTHPACK_H
#define HEALTHPACK_H
#include "consumable.h"


class HealthPack: public Consumable
{
public:
    HealthPack(int xPosition, int yPosition, float health);
};

#endif // HEALTHPACK_H
