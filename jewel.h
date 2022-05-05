#ifndef JEWEL_H
#define JEWEL_H

#include "coordinate.h"

class Jewel{
  public:
    //desc: default constructor that is not used, only for compilation success
    //pre: none
    //post: an invalid Jewel object (value = -1) is created.
    Jewel();
    //desc: constructor that sets originalCords to cordIn and sets the value.
    //pre: none
    //post: originalCords = cordIn and value = row + col of that Coordinate
    Jewel(const Coordinate & cordIn);
    
    //desc: gets value of a Jewel object
    //pre: none
    //post: value is returned.
    int getValue() const;
  private:
    int value;
    Coordinate originalCords;
    Coordinate cords;
};


#endif
