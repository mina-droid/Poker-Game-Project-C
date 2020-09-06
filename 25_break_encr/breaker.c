#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void letterfreq(FILE * f, int * arr, size_t size);

int fkey(int *arr, size_t size);

int main(int argc, char ** argv)
{
  if (argc != 2)
    {
      fprintf(stderr,"invlaid arguments number\n");
      return EXIT_FAILURE;
    }
  FILE * f = fopen(argv[1],"r");
  if ( f == NULL)
    {
      perror("Could not open file\n");
      return EXIT_FAILURE;
    }
  int letters[26] = {0};
  letterfreq(f, letters, 26);
  int key = fkey(letters, 26);

  printf("%d\n", key);
  return EXIT_SUCCESS;
}

void letterfreq(FILE * f, int * arr, size_t size)
{
  int c;
  while ( (c = fgetc(f)) != EOF)
    {
      if ( isalpha(c))
	{
	  arr[c-97]++;
	}
    }
 
}

int fkey(int *arr, size_t size)
{
  int max = 0;
  int maxindex = 0;
  for ( int i = 0; i < size; i++)
    {
      if ( arr[i] > max)
	{
	  max = arr[i];
	  maxindex = i;
	}
    }
  int key = (maxindex + 22) % 26;
  return key;
}
