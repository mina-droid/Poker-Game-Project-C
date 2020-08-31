#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  size_t n = hand->n_cards;
  card_t temp;
  for ( int i = 0; i < n; i++)
    {
      temp = * hand -> cards[i];
      print_card(temp);
      printf(" ");
    
    }
}

int deck_contains(deck_t * d, card_t c) {
for ( int i = 0; i < d -> n_cards; i++)
   {
     if (d -> cards[i] -> value == c.value){
       if( d -> cards[i] -> suit == c.suit){
       
	 return 1;
       }
     }
       }
   
 
  return 0;
}

void shuffle(deck_t * d){
  card_t ** temp = d -> cards;
  size_t n = d -> n_cards;
  for ( int i = 1; i < n; i++)
    {
      int r = random() % (i+1);
      card_t ** temp1 = temp + r;
      card_t ** temp2 = temp + n - i;
      card_t * temp3 = *temp1;
      *temp1 = *temp2;
      *temp2 = temp3;
    }
  

}

void assert_full_deck(deck_t * d) {
  for ( int i = 0; i < d -> n_cards; i++){
    assert( d -> cards[i] -> value >= 2 && d -> cards[i] -> value <= 14);
    assert ( d -> cards[i] -> suit >= 0 && d -> cards[i] -> suit <= 3);
  }
}

