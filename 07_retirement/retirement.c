#include <stdio.h>
#include <stdlib.h>

struct _retire_info
{
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

void retirement(int startAge, double initial, retire_info working, retire_info retired);
void retired (int startAge, double initial, retire_info retired);

int main(void)
{
  retire_info working;
  retire_info retired;
  int startAge;
  double initial;
  
  
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;

  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;

  startAge = 327;
  initial = 21.345 * 1000;
    
  printf ("Age %3d month %2d you have $%.2f\n", startAge/12, startAge%12,  initial);
  

  
  retirement(startAge, initial, working, retired);  

  return 0;
  
  
}
void retired_c (int startAge, double initial, retire_info retired)
{
  double  s;
  for (int i = startAge; i < 1199 ; i++)
    {
      s = initial * retired.rate_of_return;
      s += retired.contribution;
      initial += s;
      startAge++;
      
      printf ("Age %3d month %2d you have $%.2f\n", startAge/12, startAge%12,  initial);
	
    }
}

void retirement(int startAge, double initial, retire_info working, retire_info retired)
{
  double  s;
  for (int i = startAge; i < 816; i++)
    {
      s = initial * working.rate_of_return;
      s += working.contribution;
      initial += s;
      startAge++;
      
      printf ("Age %3d month %2d you have $%.2f\n", startAge/12, startAge%12,  initial);
	
    }
  retired_c(startAge, initial, retired); 
  
}
