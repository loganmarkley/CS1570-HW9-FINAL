#include "jewel.h"
#include "city.h"
#include "constants.h"

#include <string>
#include <iostream>
using namespace std;

template <class T>
int Robber<T>::allRobbersLootWorth = 0;

template <class T>
Robber<T>::Robber()
{
  type = '~';
  active = false;
}

template <class T>
Robber<T>::Robber(const int idIn, const char typeIn)
{
  id = idIn;
  type = typeIn;
  active = true;
  lootWorth = 0;
  itemsInBag = 0;
  for(int i=0; i<ROBBER_BAG_SIZE; i++)
  {
    T empty;
    bag[i] = empty;
  }
}

template <class T>
int Robber<T>::getLootWorth() const
{
  return lootWorth;
}

template <class T>
int Robber<T>::getAllRobbersLootWorth() const
{
  return allRobbersLootWorth;
}

template <class T>
bool Robber<T>::isActive() const
{
  return active;
}

template <class T>
char Robber<T>::getType() const
{
  return type;
}

template <class T>
Coordinate Robber<T>::getCords() const
{
  return cords;
}

template <class T>
void Robber<T>::setCords(const Coordinate & cordIn)
{
  cords = cordIn;
  return;
}

template <class T>
void Robber<T>::makeActive()
{
  active = true;
  return;
}

template <class T>
void Robber<T>::makeInactive()
{
  active = false;
  return;
}

template <class T>
void Robber<T>::pickUpLoot(const T & itemIn)
{
  bool itemPlaced = false;
  int indexPlaced = 0;
  for(int i=0; i<ROBBER_BAG_SIZE; i++)
  {
    if(bag[i].getValue() == -1 && itemPlaced == false)
    {
      bag[i] = itemIn;
      itemPlaced = true;
      indexPlaced = i;
    }
  }
  itemsInBag++;
  int itemWorth = bag[indexPlaced].getValue();
  lootWorth += itemWorth;
  allRobbersLootWorth += itemWorth;
  return;
}

template <class T>
Coordinate Robber<T>::move(const City & cityIn)
{
  bool keepSearching = true;
  bool canGreedyRobberFindJewel = false;
  for(int i=0; i<8; i++)
  {
    if(cityIn.jewelInThisDirection(cords, i))
    {
      canGreedyRobberFindJewel = true;
    }
  }
  while(keepSearching)
  {
    int randDirection = rand() % 8;
    switch (randDirection){
      case 0:
        if(cords.row - 1 >= 0 && cords.col - 1 >= 0 && (type == 'O' || (type == 'G' && cityIn.jewelInThisDirection(cords, 0)) || (type == 'G' && canGreedyRobberFindJewel == false)))
        {
          cords.row -= 1;
          cords.col -= 1;
          keepSearching = false;
        }
        break;
      case 1:
        if(cords.row - 1 >= 0 && (type == 'O' || (type == 'G' && cityIn.jewelInThisDirection(cords, 1)) || (type == 'G' && canGreedyRobberFindJewel == false)))
        {
          cords.row -= 1;
          keepSearching = false;
        }
        break;
      case 2:
        if(cords.row - 1 >= 0 && cords.col + 1 < CITY_COL_SIZE && (type == 'O' || (type == 'G' && cityIn.jewelInThisDirection(cords, 2)) || (type == 'G' && canGreedyRobberFindJewel == false)))
        {
          cords.row -= 1;
          cords.col += 1;
          keepSearching = false;
        }
        break;
      case 3:
        if(cords.col - 1 >= 0 && (type == 'O' || (type == 'G' && cityIn.jewelInThisDirection(cords, 3)) || (type == 'G' && canGreedyRobberFindJewel == false)))
        {
          cords.col -= 1;
          keepSearching = false;
        }
        break;
      case 4:
        if(cords.col + 1 < CITY_COL_SIZE && (type == 'O' || (type == 'G' && cityIn.jewelInThisDirection(cords, 4)) || (type == 'G' && canGreedyRobberFindJewel == false)))
        {
          cords.col += 1;
          keepSearching = false;
        }
        break;
      case 5:
        if(cords.row + 1 < CITY_ROW_SIZE && cords.col - 1 >= 0 && (type == 'O' || (type == 'G' && cityIn.jewelInThisDirection(cords, 5)) || (type == 'G' && canGreedyRobberFindJewel == false)))
        {
          cords.row += 1;
          cords.col -= 1;
          keepSearching = false;
        }
        break;
      case 6:
        if(cords.row + 1 < CITY_ROW_SIZE && (type == 'O' || (type == 'G' && cityIn.jewelInThisDirection(cords, 6)) || (type == 'G' && canGreedyRobberFindJewel == false)))
        {
          cords.row += 1;
          keepSearching = false;
        }
        break;
      case 7:
        if(cords.row + 1 < CITY_ROW_SIZE && cords.col + 1 < CITY_COL_SIZE && (type == 'O' || (type == 'G' && cityIn.jewelInThisDirection(cords, 7)) || (type == 'G' && canGreedyRobberFindJewel == false)))
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

template <class T>
void Robber<T>::endSummary() const
{
  if(type == 'O')
  {
    cout<<"\tOrdinary Robber id: "<<id<<endl;
  }
  else if(type == 'G')
  {
    cout<<"\tGreedy Robber id: "<<id<<endl;
  }
  if(active)
  {
    cout<<"\t   Active? Yes!"<<endl;
  }
  else
  {
    cout<<"\t   Active? No!"<<endl;
  }
  cout<<"\t   Final number of jewels picked up: "<<itemsInBag<<endl;
  cout<<"\t   Total jewel worth: $"<<lootWorth<<endl;
  return;
}

