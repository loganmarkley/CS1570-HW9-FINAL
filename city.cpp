#include "city.h"
#include "jewel.h"
#include "constants.h"
#include "coordinate.h"

#include <string>
#include <iostream>
using namespace std;

City::City()
{
  for(int i=0; i<CITY_ROW_SIZE; i++)
  {
    for(int j=0; j<CITY_COL_SIZE; j++)
    {
      grid[i][j]='-';
    }
  }
  jewelCount=0;
}



void City::scatterJewels(const int numJewels)
{
  while(jewelCount<numJewels)
  {
    Coordinate empty = findEmptySpot();
    updateGrid(empty, 'J');
    jewelCount++;
  }
  return;
}

char City::getGridCharAtCord(const Coordinate & cordIn) const
{
  return grid[cordIn.row][cordIn.col];
}

void City::updateGrid(const Coordinate & cordIn, const char updateChar)
{
  grid[cordIn.row][cordIn.col] = updateChar;
  return;
}

bool City::jewelAtThisCord(const Coordinate & cordIn) const
{
  if(grid[cordIn.row][cordIn.col] == 'J')
  {
    return true;
  }
  return false;
}

bool City::jewelInThisDirection(const Coordinate & cordRobber, const int direction) const
{
  Coordinate gridCord = cordRobber;
  bool jewelInThisDirection = false;
  switch (direction){
    case 0:
      do
      {
        gridCord.row -= 1;
        gridCord.col -= 1;
        if(jewelAtThisCord(gridCord))
        {
          jewelInThisDirection = true;
        }
      } while(gridCord.row - 1 >= 0 && gridCord.col - 1 >= 0);
      break;
    case 1:
      do
      {
        gridCord.row -= 1;
        if(jewelAtThisCord(gridCord))
        {
          jewelInThisDirection = true;
        }
      } while(gridCord.row - 1 >= 0);
      break;
    case 2:
      do
      {
        gridCord.row -= 1;
        gridCord.col += 1;
        if(jewelAtThisCord(gridCord))
        {
          jewelInThisDirection = true;
        }
      } while(gridCord.row - 1 >= 0 && gridCord.col + 1 < CITY_COL_SIZE);
      break;
    case 3:
      do
      {
        gridCord.col -= 1;
        if(jewelAtThisCord(gridCord))
        {
          jewelInThisDirection = true;
        }
      } while(gridCord.col - 1 >= 0);
      break;
    case 4:
      do
      {
        gridCord.col += 1;
        if(jewelAtThisCord(gridCord))
        {
          jewelInThisDirection = true;
        }
      } while(gridCord.col + 1 < CITY_COL_SIZE);
      break;
    case 5:
      do
      {
        gridCord.row += 1;
        gridCord.col -= 1;
        if(jewelAtThisCord(gridCord))
        {
          jewelInThisDirection = true;
        }
      } while(gridCord.row + 1 < CITY_ROW_SIZE && gridCord.col - 1 >= 0);
      break;
    case 6:
      do
      {
        gridCord.row += 1;
        if(jewelAtThisCord(gridCord))
        {
          jewelInThisDirection = true;
        }
      } while(gridCord.row + 1 < CITY_ROW_SIZE);
      break;
    case 7:
      do
      {
        gridCord.row += 1;
        gridCord.col += 1;
        if(jewelAtThisCord(gridCord))
        {
          jewelInThisDirection = true;
        }
      } while(gridCord.row + 1 < CITY_ROW_SIZE && gridCord.col + 1 < CITY_COL_SIZE);
      break;
  }
  return jewelInThisDirection;
}

Coordinate City::findEmptySpot()
{
  Coordinate temp;
  int randRow, randCol;
  bool search = true;
  while(search)
  {
    randRow = rand() % CITY_ROW_SIZE;
    randCol = rand() % CITY_COL_SIZE;
    if(grid[randRow][randCol]=='-')
    {
      temp.row = randRow;
      temp.col = randCol;
      search = false;
    }
  }
  return temp;
}

ostream & operator << (ostream & os, const City & cityIn)
{
  for(int i=0; i<CITY_ROW_SIZE; i++)
  {
    for(int j=0; j<CITY_COL_SIZE; j++)
    {
      cout<<"  "<<cityIn.grid[i][j];
    }
    cout<<endl;
  }
  return os;
}
