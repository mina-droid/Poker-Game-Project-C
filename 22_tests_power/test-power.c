#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned power (unsigned x, unsigned y);

int main (void)
{
  unsigned x;
  x =  power ( 2, 3);
  if ( x != 8) { exit (EXIT_FAILURE);}

  x =  power ( 0, 0);
  if ( x != 1) { exit (EXIT_FAILURE);}

  x =  power (0, 3);
  if ( x != 0) { exit (EXIT_FAILURE);}

  x =  power ( 0, 1);
  if ( x != 0) { exit (EXIT_FAILURE);}

  x =  power ( 1, 1);
  if ( x != 1) { exit (EXIT_FAILURE);}

  x =  power ( 1, 9);
  if ( x != 1) { exit (EXIT_FAILURE);}

  x =  power ( 1, 0);
  if ( x != 1) { exit (EXIT_FAILURE);}

  x =  power ( 1000000000,1);
  if ( x != 1000000000) { exit (EXIT_FAILURE);}

 
 }
  
