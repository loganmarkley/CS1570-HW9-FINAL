#include "police.h"
#include "robber.h"
#include "jewel.h"
#include "coordinate.h"

#include <iostream>
using namespace std;

Police::Police()
{
  id=-1;
}

Police::Police(const int idIn)
{
  id=idIn;
  totalConfiscatedLootWorth=0;
  totalRobbersCaught=0;
}

int Police::getTotalRobbersCaught() const
{
  return totalRobbersCaught;
}

Coordinate Police::getCords() const
{
  return cords;
}

void Police::setCords(const Coordinate & cordIn)
{
  cords = cordIn;
  return;
}

Coordinate Police::move()
{
  bool keepSearching = true;
  while(keepSearching)
  {
    int randDirection;
    randDirection = rand() % 8;
    switch (randDirection){
      case 0:
        if(cords.row - 1 >= 0 && cords.col - 1 >= 0)
        {
          cords.row -= 1;
          cords.col -= 1;
          keepSearching = false;
        }
        break;
      case 1:
        if(cords.row - 1 >= 0)
        {
          cords.row -= 1;
          keepSearching = false;
        }
        break;
      case 2:
        if(cords.row - 1 >= 0 && cords.col + 1 < CITY_COL_SIZE)
        {
          cords.row -= 1;
          cords.col += 1;
          keepSearching = false;
        }
        break;
      case 3:
        if(cords.col - 1 >= 0)
        {
          cords.col -= 1;
          keepSearching = false;
        }
        break;
      case 4:
        if(cords.col + 1 < CITY_COL_SIZE)
        {
          cords.col += 1;
          keepSearching = false;
        }
        break;
      case 5:
        if(cords.row + 1 < CITY_ROW_SIZE && cords.col - 1 >= 0)
        {
          cords.row += 1;
          cords.col -= 1;
          keepSearching = false;
        }
        break;
      case 6:
        if(cords.row + 1 < CITY_ROW_SIZE)
        {
          cords.row += 1;
          keepSearching = false;
        }
        break;
      case 7:
        if(cords.row + 1 < CITY_ROW_SIZE && cords.col + 1 < CITY_COL_SIZE)
        {
          cords.row += 1;
          cords.col += 1;
          keepSearching = false;
        }
        break;
    }
  }
  return cords;
}

void Police::endSummary() const
{
  cout<<"\tPolice id: "<<id<<endl;
  cout<<"\t   Confiscated jewels amount: $"<<totalConfiscatedLootWorth<<endl;
  cout<<"\t   Final number of robbers caught: "<<totalRobbersCaught<<endl;
  return;
}

