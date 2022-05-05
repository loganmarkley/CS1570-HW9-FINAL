#include "coordinate.h"

bool Coordinate::operator == (const Coordinate & cordIn)
{
  if(row == cordIn.row && col == cordIn.col)
  {
    return true;
  }
  else
  {
    return false;
  }
}
