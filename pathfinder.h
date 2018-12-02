#ifndef PATHFINDER_H
#define PATHFINDER_H
#include "world.h"
#include "priorityqueue.h"
#include <map>

struct GridLocation {
  int x, y;
  float value;
};

class Pathfinder
{

public:
    Pathfinder(std::vector<std::unique_ptr<Tile>>& mmap,int mwidth,int mlength);
    void find(std::unique_ptr<Tile>& start, std::unique_ptr<Tile>& goal);
    void print_path();
    std::vector<GridLocation> getNeighbors(GridLocation current);
 private:
    std::vector<GridLocation> map;
    std::map<GridLocation, GridLocation> came_from;
    std::map<GridLocation, double> cost_so_far;
    GridLocation mystart;
    GridLocation goal;
    int cols, rows;


};

#endif // PATHFINDER_H
