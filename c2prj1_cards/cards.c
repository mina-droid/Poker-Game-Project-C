#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"



void assert_card_valid(card_t c)
{
  assert(c.value >= 2 && c.value <= VALUE_ACE && c.suit >= SPADES  && c.suit <= CLUBS); 
}

const char * ranking_to_string(hand_ranking_t r)
{
   switch (r){
  case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH"; break; 
  case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND"; break;
  case FULL_HOUSE: return "FULL_HOUSE"; break;
  case FLUSH: return "FLUSH"; break; 
  case STRAIGHT: return "STRAIGHT"; break; 
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND"; break; 
  case TWO_PAIR: return "TWO_PAIR";break; 
  case PAIR: return "PAIR"; break;   
  case NOTHING: return "NOTHING"; break;
   default: exit(EXIT_FAILURE);
  }        
}

char value_letter(card_t c) {
  
  switch (c.value){
  case 2: return '2'; break;
  case 3: return '3'; break;
  case 4: return '4'; break;
  case 5: return '5'; break;
  case 6: return '6'; break;
  case 7: return '7'; break; 
  case 8: return '8'; break; 
  case 9: return '9'; break;
  case 10: return '0'; break;
  case VALUE_JACK: return 'J'; break;
  case VALUE_QUEEN: return 'Q'; break;
  case VALUE_KING: return 'K'; break;
  case VALUE_ACE: return 'A'; break;
  default: exit(EXIT_FAILURE);
  }
  
   
}


char suit_letter(card_t c) {
  switch (c.suit){
  case SPADES: return 's'; break;
  case HEARTS: return 'h'; break;
  case DIAMONDS: return 'd'; break;
  case CLUBS: return 'c'; break;
  default:exit (EXIT_FAILURE); 
  }    
  
}

void print_card(card_t c) {
  c.value = value_letter(c);
  c.suit = suit_letter(c);
  printf("%c%c", c.value, c.suit);

}

card_t card_from_letters(char value_let, char suit_let){
  card_t c;
  assert(value_let == 'A' || value_let == '2' || value_let == '3' || value_let == '4'|| value_let == '5'|| value_let == '6'|| value_let == '7'|| value_let == '8' ||value_let == '9'|| value_let == '0' ||value_let == 'J'|| value_let == 'Q'|| value_let == 'K');
  assert(suit_let == 's' || suit_let == 'h'|| suit_let == 'd'|| suit_let == 'c');
    

 switch (value_let)
    {
    case'2': c.value = 2; break;
    case'3': c.value = 3; break;
    case'4': c.value = 4; break;
    case'5': c.value = 5; break;
    case'6': c.value = 6; break;
    case'7': c.value = 7; break;
    case'8': c.value = 8; break;
    case'9': c.value = 9; break;
    case'0': c.value = 10; break;
    case'A': c.value = 14; break;
    case'J': c.value = 11; break;
    case'Q': c.value = 12; break;
    case'K': c.value = 13; break;
 }
  switch (suit_let)
   {
   case 's': c.suit = 0; break;
   case 'h': c.suit = 1; break;
   case 'd': c.suit = 2; break;
   case 'c': c.suit = 3; break;
   default: break;
  }
    
  return c;
}


card_t card_from_num(unsigned c) {
  card_t temp;
  int x = (c % 13) + 1 , y = c / 13;
  if( x == 1)
    {
      temp.value = 14;
    }
  else
    {
      temp.value = x;
    }
  temp.suit = y;
 return temp;
}
