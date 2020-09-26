#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

char *  stripNewline(char * str)  {
  char * p = strchr(str, '=');
  char * s = strchr(str, '\n');
  if ( s != NULL)
    {
      *s = '\0';
    }
  size_t len = strlen(str);
  *p = '\0';
  p++;
  p[len ] = '\0';
  return p;
  
}

kvarray_t * readKVs(const char * fname) {
  FILE * f = fopen(fname,"r");
  if ( f == NULL)
    {
      fprintf(stderr,"could not open file!");
      exit (EXIT_FAILURE);
    }
  size_t sz = 0;
  char * str = NULL;
  kvarray_t * ans = malloc (sizeof(*ans));
  ans -> kvarr = malloc (sizeof(*ans -> kvarr));
  ans -> kvarrsize = 0;
  while (getline(&str, &sz, f) >= 0)
    {
      if ( str[0] =='\n')
	{
	  continue;
	}
      ans -> kvarr = realloc (ans -> kvarr, ((ans -> kvarrsize + 1) * sizeof(*ans -> kvarr)));
      ans -> kvarr[ans ->kvarrsize] = malloc (sizeof(*ans -> kvarr[ans -> kvarrsize]));
      ans -> kvarr[ans -> kvarrsize] -> value =  stripNewline(str);
      ans -> kvarr[ans -> kvarrsize] -> key =str;
      str = NULL;
      ans -> kvarrsize++;
    }
  free(str);
  if (fclose(f) != 0)
    {
      fprintf(stderr,"could not close file!");
    }
  return ans;
  
  //WRITE ME
}


void freeKVs(kvarray_t * pairs) {
  for ( int i = 0; i < pairs -> kvarrsize; i++)
    {
      free(pairs -> kvarr[i]-> key);
      free(pairs -> kvarr[i]);
    }
  free(pairs -> kvarr);
  free(pairs);
  
  //WRITE ME
}

void printKVs(kvarray_t * pairs) {
  for ( int i = 0; i < pairs -> kvarrsize; i++){
    printf("key = '%s' value = '%s'\n", pairs ->kvarr[i]->key, pairs -> kvarr[i] -> value);
  }
  //WRITE ME
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  for ( int i = 0; i < pairs -> kvarrsize; i++)
    {
      if ( strcmp(pairs -> kvarr[i] -> key, key) == 0)
	{
	  return pairs -> kvarr[i] -> value;
	}
    }
  return NULL;
  //WRITE ME
}
