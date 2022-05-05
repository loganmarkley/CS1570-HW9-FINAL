#ifndef CITY_H
#define CITY_H

#include "constants.h"
#include "coordinate.h"
#include "jewel.h"

#include <string>
#include <iostream>
using namespace std;

class City{
  public:
    //desc: default constructor of city sets every value in grid[][] to '-' and jewelCount = 0
    //pre: none
    //post: every value in grid[][] is '-' and jewelCount = 0
    City();
    
    //desc: randomly places numJewels amount of 'J' chars in grid[][]
    //pre: numJewels must be less than the max size of the 2d array grid[][] which depends on constants.h
    //     0 <= numJewels <= max size of grid
    //post: numJewels amount of 'J's are randomly put in grid
    void scatterJewels(const int numJewels);
    //desc: returns the char value at a Coordinate in grid
    //pre: the Coordinate must be possible in grid. (aka not out of bounds)
    //post: the char value in grid at cordIn is returned.
    char getGridCharAtCord(const Coordinate & cordIn) const;
    //desc: changes the char value in grid at the Coordinate cordIn using the char updateChar.
    //pre: the Coordinate must be possible in grid. (aka not out of bounds).
    //     updateChar should be '-', 'J', 'r', 'R', or 'P' to be consistent with the current chase situation.
    //post: the char at cordIn in grid is changed to updateChar.
    void updateGrid(const Coordinate & cordIn, const char updateChar);
    //desc: sees if there is a Jewel 'J' at a Coordinate in grid
    //pre: the Coordinate must be possible in grid. (aka not out of bounds)
    //post: true is returned if the char at cordIn is 'J' in grid
    bool jewelAtThisCord(const Coordinate & cordIn) const;
    //desc: sees if there is a jewel in certain direction away from cordRobber, anywhere in grid.
    //      direction relates to North, northwest, east, etc.
    //pre: the Coordinate must be possible in grid. (aka not out of bounds).
    //     0 <= direction <= 7
    //post: true is returned if there is a jewel inbetween cordRobber and the end of the grid, based on direction.
    bool jewelInThisDirection(const Coordinate & cordRobber, const int direction) const;
    //desc: randomly searches Coordinates in grid until one is found with the value of '-'
    //pre: none
    //post: the Coordinate of a random empty spot '-' in grid is returned
    Coordinate findEmptySpot();
    //desc: displays every character in each index of grid in an organized fashion.
    //pre: none
    //post: the 2D array, grid, is displayed to the user.
    friend ostream & operator << (ostream & os, const City & cityIn);
  private:
    char grid[CITY_ROW_SIZE][CITY_COL_SIZE]={};
    int jewelCount;
};

#endif
