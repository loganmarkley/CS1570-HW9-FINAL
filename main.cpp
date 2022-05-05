//Programmer: Logan Markley
//Student ID: 12579435
//MST Username: lcmkbc
//Instructor Name: San Yeung
//Section: 109
//Date: 5/3/22
//File: main.cpp
//Purpose: final project in C++ (HW 9)

//---------------- I AM DOING THE BONUS FOR THE GREEDY ROBBER TYPE!!!!! ---------- 
// Also, I did not implement two features for greedy robbers: DID NOT DO THE DROPPING HALF OF THE BAG | DID NOT DO THE MOVING AGAIN IF VALUE IS EVEN

#include "city.h"
#include "jewel.h"
#include "robber.h"
#include "police.h"
#include "constants.h"
#include "coordinate.h"

#include <string>
#include <iostream>
using namespace std;

int main()
{
  srand(RAND_SEED);

  cout<<"A man has fallen into the river in lego city!"<<endl<<endl;
  City legoCity;
  legoCity.scatterJewels(CITY_JEWELS_SCATTERED);
  
  Police logan(1);
  Robber<Jewel> zach(1, 'O'), owen(2, 'O'), emre(3, 'G'), cris(4, 'G');
  for(int i=0; i<CITY_PEOPLE; i++)
  {
    Coordinate emptySlot = legoCity.findEmptySpot();
    switch(i){
      case 0:
        logan.setCords(emptySlot);
        legoCity.updateGrid(emptySlot, 'p');
        break;
      case 1:
        zach.setCords(emptySlot);
        legoCity.updateGrid(emptySlot, 'r');
        break;
      case 2:
        owen.setCords(emptySlot);
        legoCity.updateGrid(emptySlot, 'r');
        break;
      case 3:
        emre.setCords(emptySlot);
        legoCity.updateGrid(emptySlot, 'r');
        break;
      case 4:
        cris.setCords(emptySlot);
        legoCity.updateGrid(emptySlot, 'r');
        break;
    }
  }
  
  cout<<"   This is the lego city grid"<<endl<<legoCity<<endl;
  
  int turn = 1;
  bool chase = true;
  int finalOutcome;
  while(chase)
  {
    if(zach.isActive())
    {
      if(legoCity.getGridCharAtCord(zach.getCords()) == 'R')
      {
        legoCity.updateGrid(zach.getCords(), 'r');
      }
      else
      {
        legoCity.updateGrid(zach.getCords(), '-');
      }
      Coordinate robberNewCord = zach.move(legoCity);
      char newGridChar = legoCity.getGridCharAtCord(robberNewCord);
      if(newGridChar == 'r')
      {
        legoCity.updateGrid(robberNewCord, 'R');
      }
      else if(newGridChar == 'J')
      {
        Jewel jewelTemp(robberNewCord);
        zach.pickUpLoot(jewelTemp);
        legoCity.updateGrid(robberNewCord, 'r');
      }
      else if(newGridChar == 'p')
      {
        logan.arrest(zach);
      }
      else if(newGridChar == '-')
      {
        legoCity.updateGrid(robberNewCord, 'r');
      }
    }
    if(owen.isActive())
    {
      if(legoCity.getGridCharAtCord(owen.getCords()) == 'R')
      {
        legoCity.updateGrid(owen.getCords(), 'r');
      }
      else
      {
        legoCity.updateGrid(owen.getCords(), '-');
      }
      Coordinate robberNewCord = owen.move(legoCity);
      char newGridChar = legoCity.getGridCharAtCord(robberNewCord);
      if(newGridChar == 'r')
      {
        legoCity.updateGrid(robberNewCord, 'R');
      }
      else if(newGridChar == 'J')
      {
        Jewel jewelTemp(robberNewCord);
        owen.pickUpLoot(jewelTemp);
        legoCity.updateGrid(robberNewCord, 'r');
      }
      else if(newGridChar == 'p')
      {
        logan.arrest(owen);
      }
      else if(newGridChar == '-')
      {
        legoCity.updateGrid(robberNewCord, 'r');
      }
    }
    
    if(emre.isActive())
    {
      if(legoCity.getGridCharAtCord(emre.getCords()) == 'R')
      {
        legoCity.updateGrid(emre.getCords(), 'r');
      }
      else
      {
        legoCity.updateGrid(emre.getCords(), '-');
      }
      Coordinate robberNewCord = emre.move(legoCity);
      char newGridChar = legoCity.getGridCharAtCord(robberNewCord);
      if(newGridChar == 'r') //DID NOT DO THE DROPPING HALF OF THE BAG 
      {
        legoCity.updateGrid(robberNewCord, 'R');
      }
      else if(newGridChar == 'J')  //DID NOT DO THE MOVING AGAIN IF VALUE IS EVEN
      {
        Jewel jewelTemp(robberNewCord);
        emre.pickUpLoot(jewelTemp);
        legoCity.updateGrid(robberNewCord, 'r');
      }
      else if(newGridChar == 'p')
      {
        logan.arrest(emre);
      }
      else if(newGridChar == '-')
      {
        legoCity.updateGrid(robberNewCord, 'r');
      }
    }
    if(cris.isActive())
    {
      if(legoCity.getGridCharAtCord(cris.getCords()) == 'R')
      {
        legoCity.updateGrid(cris.getCords(), 'r');
      }
      else
      {
        legoCity.updateGrid(cris.getCords(), '-');
      }
      Coordinate robberNewCord = cris.move(legoCity);
      char newGridChar = legoCity.getGridCharAtCord(robberNewCord);
      if(newGridChar == 'r') //DID NOT DO THE DROPPING HALF OF THE BAG
      {
        legoCity.updateGrid(robberNewCord, 'R');
      }
      else if(newGridChar == 'J')  //DID NOT DO THE MOVING AGAIN IF VALUE IS EVEN
      {
        Jewel jewelTemp(robberNewCord);
        cris.pickUpLoot(jewelTemp);
        legoCity.updateGrid(robberNewCord, 'r');
      }
      else if(newGridChar == 'p')
      {
        logan.arrest(cris);
      }
      else if(newGridChar == '-')
      {
        legoCity.updateGrid(robberNewCord, 'r');
      }
    }
    
    legoCity.updateGrid(logan.getCords(), '-');
    Coordinate policeNewCord = logan.move();
    char newGridChar = legoCity.getGridCharAtCord(policeNewCord);
    if(newGridChar == 'r')
    {
      if(policeNewCord == zach.getCords())
      {
        logan.arrest(zach);
        cout<<"Zach got arrested!"<<endl<<endl;
      }
      else if(policeNewCord == owen.getCords())
      {
        logan.arrest(owen);
        cout<<"Owen got arrested!"<<endl<<endl;
      }
      else if(policeNewCord == emre.getCords())
      {
        logan.arrest(emre);
        cout<<"Emre got arrested!"<<endl<<endl;
      }
      else if(policeNewCord == cris.getCords())
      {
        logan.arrest(cris);
        cout<<"Cris got arrested!"<<endl<<endl;
      }
      legoCity.updateGrid(policeNewCord, 'p');
    }
    else if(newGridChar == 'R')
    {
      if(policeNewCord == zach.getCords() && zach.getCords() == owen.getCords())
      {
        logan.arrest(zach);
        logan.arrest(owen);
        cout<<"Zach and Owen got arrested!"<<endl<<endl;
      }
      else if(policeNewCord == zach.getCords() && zach.getCords() == emre.getCords())
      {
        logan.arrest(zach);
        logan.arrest(emre);
        cout<<"Zach and Emre got arrested!"<<endl<<endl;
      }
      else if(policeNewCord == zach.getCords() && zach.getCords() == cris.getCords())
      {
        logan.arrest(zach);
        logan.arrest(cris);
        cout<<"Zach and Cris got arrested!"<<endl<<endl;
      }
      else if(policeNewCord == owen.getCords() && owen.getCords() == cris.getCords())
      {
        logan.arrest(owen);
        logan.arrest(cris);
        cout<<"Owen and Cris got arrested!"<<endl<<endl;
      }
      else if(policeNewCord == owen.getCords() && owen.getCords() == emre.getCords())
      {
        logan.arrest(owen);
        logan.arrest(emre);
        cout<<"Owen and Emre got arrested!"<<endl<<endl;
      }
      else if(policeNewCord == emre.getCords() && emre.getCords() == cris.getCords())
      {
        logan.arrest(emre);
        logan.arrest(cris);
        cout<<"Emre and Cris got arrested!"<<endl<<endl;
      }
      legoCity.updateGrid(policeNewCord, 'p');
    }
    else if(newGridChar == 'J')
    {
      legoCity.updateGrid(policeNewCord, 'p');
    }
    else if(newGridChar == '-')
    {
      legoCity.updateGrid(policeNewCord, 'p');
    }
    
    cout<<"After Round "<<turn<<":"<<endl<<legoCity<<endl;
    
    turn++;
    if(turn > MAX_CHASE_TURNS)
    {
      chase = false;
      finalOutcome = 1;
    }
    else if(zach.getAllRobbersLootWorth() >= NET_WORTH_WIN_CON)
    {
      chase = false;
      finalOutcome = 2;
      zach.makeActive();
      owen.makeActive();
      emre.makeActive();
      cris.makeActive();
    }
    else if(logan.getTotalRobbersCaught() == ROBBERS_IN_CITY)
    {
      chase = false;
      finalOutcome = 3;
    }
  }
  cout<<"Summary of the chase:"<<endl;
  if(finalOutcome == 1)
  {
    cout<<"\tThe robbers win the chase because maximum turns ("<<MAX_CHASE_TURNS<<") have been reached."<<endl;
  }
  else if(finalOutcome == 2)
  {
    cout<<"\tThe robbers won the chase because they collectively picked up $"<<NET_WORTH_WIN_CON<<"!"<<endl;
  }
  else if(finalOutcome == 3)
  {
    cout<<"\tThe police won the chase because all the robbers were caught!"<<endl;
  }
  logan.endSummary();
  zach.endSummary();
  owen.endSummary();
  emre.endSummary();
  cris.endSummary();
  return 0;
}
