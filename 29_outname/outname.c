#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  char * outfilename = malloc((strlen(inputName) + 8) * sizeof(*outfilename));
  strcpy(outfilename, inputName);
  strcat(outfilename, ".counts");
  return outfilename;
  

   
  //WRITE ME
}
