#ifndef PROTAGONISTVIEW_H
#define PROTAGONISTVIEW_H
#include "world.h"


class ProtagonistView
{
public:
    ProtagonistView();

    void textView(int xPos,int yPos,float health,float energy, std::vector<std::unique_ptr<Tile>> my_tiles);
    void twoDView();

private:
    std::vector<std::unique_ptr<Tile>> tiles;

};

#endif // PROTAGONISTVIEW_H
