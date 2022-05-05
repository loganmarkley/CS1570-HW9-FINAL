#ifndef COORDINATE_H
#define COORDINATE_H

struct Coordinate{
  int row;
  int col;
  
  //desc: this overloaded == opertor returns true if two Coordinates are exactly the same
  //pre: none
  //post: true is returned if the Coordinates rows are equal and if their cols are equal aswell. false otherwise
  bool operator == (const Coordinate & cordIn);
};

#endif
