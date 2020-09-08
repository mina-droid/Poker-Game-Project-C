#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include <string.h>

void rotate(char arr[][12] )
{
  char arr2 [10][12];
  int k;
  for (int i = 0; i < 10; i++)
    {
      k = 9;
      for (int j = 0; j < 12; j++)
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

int main(int argc, char ** argv)
{
  if ( argc != 2)
    {
      fprintf(stderr, "wrong number of arguments!");
      exit(EXIT_FAILURE);
    }

  FILE * f = fopen(argv[1], "r");
  if ( f == NULL)
    {
      fprintf( stderr, "could not open the file!");
      exit(EXIT_FAILURE);
    }
  char arr [10][12];
  int i = 0;
  char  s[12];
  while ( fgets(s, 12, f) != NULL)
    {
      if (strchr(s,'\n') == NULL)
	{
	  fprintf(stderr, "Line too long!");
	  exit(EXIT_FAILURE);
	}
      else if ( strchr(s,'\n') != &s[10])
	{
	  fprintf(stderr, "Line too short");
	  exit (EXIT_FAILURE);
	}
      else
	{
	  for ( int j = 0; j < 12; j++)
	    {
	      arr[i][j] = s[j];
	    }
	  i++;
	}
      
    }

  rotate(arr);

  for ( int i = 0; i < 10; i++)
    {
      for ( int j = 0; j < 12; j++)
	{
	  printf("%c", arr[i][j]);
	}
      }
  
   
}

