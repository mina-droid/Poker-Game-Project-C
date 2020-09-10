#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}



int main(int argc, char ** argv) {
  char ** data = NULL;
  char * line = NULL;
  size_t i = 0;
  size_t sz;
   if (argc == 1)
    {
      while( (getline(&line, &sz, stdin)) >= 0)
	{
	  data = realloc(data, (i + 1) * sizeof(*data));
	  data[i] = line;
	  line = NULL;
          i++;
	}
      free(line);
   sortData(data, i);
   for (int j = 0; j < i; j++)
    {
        printf ("%s", data[j]);
        free(data[j]);
     }
  free(data);
   
       }

  if ( argc > 1)
    {
      for ( int c = 1; c < argc; ++c)
	{
	  sz = 0;
	  i = 0;
	  FILE * f = fopen(argv[c], "r");

	  if ( f == NULL)
	    {
	      fprintf(stderr, "could not open file!");
	      exit ( EXIT_FAILURE);
	    }

          while( (getline(&line, &sz, f)) >= 0)
	   {
	     data = realloc(data, (i + 1) * sizeof(*data));
	     data[i] = line;
	     line = NULL;
             i++;
	    
	    }
	   free(line);
   sortData(data, i);
   for (int j = 0; j < i; j++)
    {
        printf ("%s", data[j]);
        free(data[j]);
     }
  free(data);
  data = NULL;
   
	   if (fclose(f) != 0)
	     {
	       fprintf(stderr, "could not close file!");
	       exit (EXIT_FAILURE);
	     }
	   f = NULL;
	   
	}

      
    }
   
  return EXIT_SUCCESS;
}
