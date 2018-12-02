#include "penemyview.h"
#include <iostream>

PEnemyView::PEnemyView()
{

}

void PEnemyView::textView(int xPos, int yPos, float strength)
{
    std::cout<<"penemy at position ("<<xPos<<", "<<yPos
                <<"), strength value = "<<strength<<std::endl;
}
