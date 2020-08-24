#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n)
{
  size_t max = 0;
  size_t maxseq = 1;
  if (n == 0)
    {
      return max;
    }
  else if ( n == 1)
    {
      return maxseq;
    }
  for ( int i = 0, j = i + 1; i < n && j < n; i++)
    {
      if (array[j] > array[i])
	{
	  maxseq++;
	}
      else
	{
	  if (maxseq >= max)
	    {
	      max = maxseq;
	    }
	   maxseq = 1;
        }
    }
  if (maxseq > max)
    {
      max = maxseq;
    }
  return max;
 
}
