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
  int ic = 0;
  int c = 0;
  char  s[12];
  while ( fgets(s, 12, f) != NULL)
    {
      if (strchr(s,'\n') == NULL)
	{
	  fprintf(stderr, "Line too long!");
	  exit(EXIT_FAILURE);
	}
      if (strchr(s,'\0') != &s[11]){

	fprintf(stderr,"Few arguments\n");
	exit(EXIT_FAILURE);

      }
      for (int  k = 0; s[k] != '\0'; k++){c++; }

	if ( c < 11)
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
	ic++;
    }
  if ( ic > 10)
    {
      fprintf(stderr,"File too long!");
      exit(EXIT_FAILURE);
    }
  else if ( ic < 10)
    {
      fprintf(stderr, "File too short!");
      exit(EXIT_FAILURE);
    }
  printf("%d", ic);

  rotate(arr);

  for ( int i = 0; i < 10; i++)
    {
      for ( int j = 0; j < 12; j++)
	{
	  printf("%c", arr[i][j]);
	}
      }
  
   
}

