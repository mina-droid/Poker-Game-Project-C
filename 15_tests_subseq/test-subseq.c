#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

int main(void)
{
  size_t  a1;
  int d [] = {9, 8, 7, 6};
  a1 = maxSeq(d, 4);
  if ( a1 != 1)
    {
      exit(EXIT_FAILURE);
    }

  
 int arr1 []= { -25, -4, 5, 9};
 size_t a2 = maxSeq(arr1, 4);
  if ( a2 != 4) {
     exit( EXIT_FAILURE);}

  int arr2 []= {0};
  size_t a3 = maxSeq(arr2, 1);
  if ( a3 != 1) {
    exit(EXIT_FAILURE);}

  int arr3 []= {2 , 3 , 4 , 3, 5, 7, 9, 5};
  size_t a4 = maxSeq(arr3, 9);
  if(a4 != 4) { exit(EXIT_FAILURE);}

  int arr4 [] = {-1, -2, 0, 1, 2};
  if (maxSeq(arr4, 5) != 4) {exit(EXIT_FAILURE);}

  int arr5 [] = {-9, -8, -7, -1};
  if (maxSeq(arr5, 4) != 4) {exit(EXIT_FAILURE);}

  int arr6 [] = {};
  if (maxSeq(arr6, 0) != 0) {exit(EXIT_FAILURE);}

  int arr7 [] = {1,2,2,3,3,6,7,8};
  if (maxSeq(arr7, 8) != 4) {exit(EXIT_FAILURE);}
  int arr8 [] = {1, 1, 1};
  if (maxSeq(arr8, 3) != 1) {exit(EXIT_FAILURE);}
  

  return EXIT_SUCCESS;


}

