/*
 Sample code from https://www.redblobgames.com/pathfinding/a-star/
 Copyright 2014 Red Blob Games <redblobgames@gmail.com>

 Feel free to use this code in your own projects, including commercial projects
 License: Apache v2.0 <http://www.apache.org/licenses/LICENSE-2.0.html>
*/
#include "pathfinder.h"
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstdlib>


bool operator == (GridLocation a, GridLocation b) {
  return a.x == b.x && a.y == b.y;
}

bool operator != (GridLocation a, GridLocation b) {
  return !(a == b);
}

bool operator < (GridLocation a, GridLocation b) {
  return std::tie(a.x, a.y) < std::tie(b.x, b.y);
}


Pathfinder::Pathfinder(std::vector<std::unique_ptr<Tile>>& mmap,int mwidth, int mlength):cols{mwidth},rows{mlength}
{
    for(int i=0;i<mlength;i++)
    {
        for(int j=0;j<mwidth;j++)
        {
           int xPos=mmap.at(i*mwidth+j)->getXPos();

           int yPos=mmap.at(i*mwidth+j)->getYPos();
           float value=mmap.at(i*mwidth+j)->getValue();
           GridLocation grid{xPos,yPos,value};
           map.push_back(grid);
        }
    }

    for(int i=0;i<10;i++)
    {
        std::cout<<"X: "<<map.at(i).x<< "Y: "<<map.at(i).y<<std::endl;
    }
}


void Pathfinder::find(std::unique_ptr<Tile>& start, std::unique_ptr<Tile>& end)
{

    PriorityQueue<GridLocation,float> frontier;

    mystart=GridLocation{start->getXPos(),start->getYPos(),start->getValue()};
    goal=GridLocation{end->getXPos(),end->getYPos(),end->getValue()};
    came_from[mystart]=mystart;
    cost_so_far[mystart]=0;

    frontier.put(mystart,0);

    while (!frontier.empty()) {
        GridLocation current=frontier.get();
        if(current==goal)
        {
            break;
        }

        //first find all neighbors of "current"
          std::vector<GridLocation> neighbors;
          int xPos=current.x;
          int yPos=current.y;
          if(xPos>1)
          {
              neighbors.push_back(map.at(yPos*cols+xPos-1));
          }

          if(xPos<cols-1)
          {
              neighbors.push_back(map.at(yPos*cols+xPos+1));
          }

          if(yPos>1)
          {
              neighbors.push_back(map.at((yPos-1)*cols+xPos));
          }

          if(yPos<rows-1)
          {
              neighbors.push_back(map.at((yPos+1)*cols+xPos));
          }


          //iterate the all the elements in the neighbors
          for(auto next:neighbors)
          {
              float new_cost=cost_so_far[current]+current.value-next.value;
              if(cost_so_far.find(next)==cost_so_far.end()||new_cost<cost_so_far[next])
              {
                  cost_so_far[next]=new_cost;
                  float heuristic=abs(goal.x-next.x)+abs(goal.y-next.y);
                  float priority =new_cost+heuristic;
                  frontier.put(next,priority);
                  came_from[next]=current;
              }
          }
    }
}


void Pathfinder::print_path()
{
        std::vector<GridLocation> path;
        GridLocation current=goal;
        while(current!=mystart)
        {
            path.push_back(current);
            current=came_from[current];
        }
        path.push_back(current);
        std::reverse(path.begin(), path.end());
        for(GridLocation grid:path)
        {
            std::cout<<"x= "<<grid.x<< "  y= "<< grid.y<<std::endl;
        }
}
