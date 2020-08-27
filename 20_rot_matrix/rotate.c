#include <stdio.h>
#include <stdlib.h> 


void rotate(char arr[][10] )
{
  char arr2 [10][10];
  int k;
  for (int i = 0; i < 10; i++)
    {
      k = 9;
      for (int j = 0; j < 10; j++)
	{
	  arr2[i][j] = arr[k][i];
	  k--;
	}
              
    }
  for (int i = 0; i < 10; i++)
    {
     for (int j = 0; j < 10; j++)
	{
	  arr[i][j] = arr2[i][j];
	 }
              
    }
  
  
}


