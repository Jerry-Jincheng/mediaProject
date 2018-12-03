#include "protagonistview.h"
#include <iostream>

ProtagonistView::ProtagonistView()
{

}

void ProtagonistView::textView(int xPos, int yPos, float health, float energy, std::vector<std::unique_ptr<Tile> > my_tiles)
{
    std::cout<<"protagonist at position ("<<xPos<<", "<<yPos
                <<"), health value = "<<health
                <<",energy = "<<energy<<std::endl;
}
