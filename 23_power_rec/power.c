#include <stdio.h>
#include <stdlib.h>

unsigned power (unsigned x, unsigned y)
{
  if ( y == 0 || x == 1 || (x == 0 && y == 0))
    {
      return 1;
    }
  else if ( x == 0)
    {
      return 0;
    }
  else if ( y == 1)
    {
      return x;
    }

  return x * power ( x, y-1);
}
