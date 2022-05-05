#include "jewel.h"

Jewel::Jewel()
{
  value = -1;
}

Jewel::Jewel(const Coordinate & cordIn)
{
  originalCords = cordIn;
  cords = originalCords;
  value = originalCords.row + originalCords.col;
}

int Jewel::getValue() const
{
  return value;
}
