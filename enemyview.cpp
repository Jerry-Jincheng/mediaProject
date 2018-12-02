#include "enemyview.h"
#include <iostream>

EnemyView::EnemyView()
{

}

void EnemyView::textView(int xPos, int yPos, float strength)
{
    std::cout<<"normal enemy at position ("<<xPos<<", "<<yPos
                <<"), strength value = "<<strength<<std::endl;
}
