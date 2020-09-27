#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  counts_t * ans= malloc(sizeof(*ans));
  ans->arr = NULL;
  ans->arrs=0;
  ans->ucounts=0;
  return ans;
    //WRITE ME
}
void addCount(counts_t * c, const char * name) {
  if (name == NULL) c->ucounts ++;
  else {
    one_count_t* x = NULL;
    int h = 0;
    for(size_t i=0 ; i< c->arrs ; i++){
      x = c->arr[i];
      if (! strcmp(x->name,name)) {
	x->count ++;
	h=1;}
    }
    if (h==0) {
      one_count_t *x1=NULL;
      x1=malloc(sizeof(*x1));
      x1->name=malloc(strlen(name)+8);
      strcpy(x1->name ,name);
      x1->count=1;
      c->arr=realloc(c->arr,(c->arrs+1)*sizeof(*c->arr));
      c->arr[c->arrs]=x1;
      c->arrs ++;
    }
  }
  //WRITE ME
}
void printCounts(counts_t * c, FILE * outFile) {
   
  one_count_t* x=NULL;
  for (size_t i=0 ;i<c->arrs;i++){
    x=c->arr[i];
    fprintf(outFile,"%s: %i\n",x->name,x->count);
  }
  if (c->ucounts != 0) fprintf(outFile,"<unknown> : %i\n",c->ucounts);
  //WRITE ME
}

void freeCounts(counts_t * c) {
  for ( int i = 0; i < c -> arrs; i++)
    {
      free (c -> arr[i] -> name);
      free(c -> arr[i]);
    }
  free(c -> arr);
  free(c);
  //WRITE ME
  
}
