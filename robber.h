#ifndef ROBBER_H
#define ROBBER_H

#include "constants.h"
#include "coordinate.h"
#include "city.h"
#include "jewel.h"

#include <string>

template <class T>
class Robber{
  public:
    //desc: default constructor that is not used, only for compilation success
    //pre: none
    //post: an invalid Robber object (type = '~', active = false) is created.
    Robber<T>();
    //desc: constructor that sets id to idIn and sets type to typeIn and initializes other variables
    //      they are also made active and their bag is initialized with empty objects
    //pre: id >= 0, typeIn should be 'O' or 'G' currently (as these are the two types of Robbers)
    //post: this robber is initialized with real values
    Robber<T>(const int idIn, const char typeIn);
    
    //desc: gets the lootWorth member variable of a Robber object
    //pre: none
    //post: returns lootWorth.
    int getLootWorth() const;
    //desc: gets the allRobberslootWorth static member variable of all Robbers
    //pre: none
    //post: returns allRobberslootWorth.
    int getAllRobbersLootWorth() const;
    //desc: gets the active member variable of a Robber object
    //pre: none
    //post: returns active.
    bool isActive() const;
    //desc: gets the type member variable of a Robber object
    //pre: none
    //post: returns type.
    char getType() const;
    //desc: gets the cords member variable of a Robber object
    //pre: none
    //post: returns cords.
    Coordinate getCords() const;
    //desc: sets the cords member variable of a Robber object using cordIn
    //pre: none
    //post: cords = cordIn
    void setCords(const Coordinate & cordIn);
    //desc: sets the active member variable of a Robber object to true
    //pre: none
    //post: active = true
    void makeActive();
    //desc: sets the active member variable of a Robber object to false
    //pre: none
    //post: active = false
    void makeInactive();
    //desc: given itemIn, it will be added into bag[] at an available spot.
    //      if the bag is full, nothing will happen.
    //pre: none
    //post: itemIn is added into the bag at the first available spot, or if full, not added.
    void pickUpLoot(const T & itemIn);
    //desc: randomly chooses a direction to move the Robber in bounds of cityIn's grid.
    //pre: the Robber's Coordinate before moving must be marked in cityIn's grid with the character 'r'.
    //     or 'R' if two Robbers are on the same spot.
    //post: cords are adjusted based on which direction the Robber moved. 
    //      this adjusted Coordinate is then returned.
    Coordinate move(const City & cityIn);
    //desc: neatly prints out a summary of some of the Robber's variables
    //pre: none
    //post: the Robber's type, id, active, itemsInBag, and lootWorth member variables are displayed
    void endSummary() const;
  private:
    static int allRobbersLootWorth;
    
    int id;
    Coordinate cords;
    T bag[ROBBER_BAG_SIZE] = {};
    int itemsInBag;
    int lootWorth;
    bool active;
    char type;
};

#include "robber.hpp"
#endif
