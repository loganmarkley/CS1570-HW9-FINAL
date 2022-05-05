#ifndef POLICE_H
#define POLICE_H

#include "coordinate.h"
#include "robber.h"
#include "jewel.h"

class Police{
  public:
    //desc: default constructor that is not used, only for compilation success
    //pre: none
    //post: an invalid Police object (id = -1) is created.
    Police();
    //desc: constructor that sets id to idIn and initializes other variables
    //pre: id >= 0
    //post: this Police is initialized with real values
    Police(const int idIn);
    
    //desc: gets the totalRobbersCaught member variable of a Police object
    //pre: none
    //post: returns totalRobbersCaught.
    int getTotalRobbersCaught() const;
    //desc: gets the cords member variable of a Police object
    //pre: none
    //post: returns cords.
    Coordinate getCords() const;
    //desc: sets the cords member variable of a Police object to cordIn
    //pre: none
    //post: cords = cordIn.
    void setCords(const Coordinate & cordIn);
    //desc: given a Robber object, robberIn will be made inactive 
    //      and totalRobbersCaught and totalConfiscatedLootWorth will be adjusted
    //pre: none
    //post: robberIn is made inactive, totalRobbersCaught++, and the robbers loot will
    //      be added to the Police's totalConfiscatedLootWorth.
    template <typename T>
    void arrest(Robber<T> & robberIn)
    {
      robberIn.makeInactive();
      totalRobbersCaught++;
      totalConfiscatedLootWorth+=robberIn.getLootWorth();
      return;
    }
    //desc: randomly chooses a direction to move the Police in bounds of cityIn's grid.
    //pre: the Police's Coordinate before moving must be marked in cityIn's grid with the character 'p'.
    //post: cords are adjusted based on which direction the Police moved. 
    //      this adjusted Coordinate is then returned.
    Coordinate move();
    //desc: neatly prints out a summary of some of the Police's variables
    //pre: none
    //post: the Police's id, totalConfiscatedLootWorth, and totalRobbersCaught member variables are displayed
    void endSummary() const;
  private:
    int id;
    Coordinate cords;
    int totalConfiscatedLootWorth;
    int totalRobbersCaught;
};



#endif
