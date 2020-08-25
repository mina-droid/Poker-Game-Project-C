#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * str){
  int i = 0;

  while (str[i] != '\0'){

    i++;
  }

  if ( i == 0)
    {
      printf(" ");
    }
  else
    {
      
     char str4 [i];
     int k = i - 1;
     int j = 0;
     while ( j != i)
       {
	 str4[j] = str[k];
	 j++;
	 k--;
       }
     str4[j] = '\0';
    
     printf ("%s\n", str4);
    }

  
}

int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
