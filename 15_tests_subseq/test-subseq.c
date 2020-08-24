#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

int main(void)
{
  size_t  a1;
  int d [] = {9, 8, 7, 6};
  a1 = maxSeq(d, 4);
  if ( a1 != 0)
    {
      exit(EXIT_FAILURE);
    }

  
 int a []= { -25, -20, 5, 9};
 size_t a2 = maxSeq(a, 4);
  if ( a2 != 4) {
    printf("Mi\n");
    exit( EXIT_FAILURE);}

  int b []= {0};
  size_t a3 = maxSeq(b, 1);
  if ( a3 != 1) {
    printf("ho\n");
    exit(EXIT_FAILURE);}

  int c []= {2 , 3 , 4 , 3, 5, 7, 9};
  size_t a4 = maxSeq(c, 8);
  if(a4 != 4) { printf("lool\n"); exit(EXIT_FAILURE);}
  

  return EXIT_SUCCESS;


}

