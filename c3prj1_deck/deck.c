#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void add_card_to(deck_t * deck, card_t c)
{
  deck -> cards = realloc ( deck -> cards, (deck -> n_cards) *( sizeof(*deck -> cards)));
  deck -> cards[deck -> n_cards] -> value = c.value;
  deck -> cards[deck -> n_cards] -> suit = c.suit;
    
}


card_t * add_empty_card(deck_t * deck)
{
  card_t * ans;
  ans -> value = 0;
  ans -> suit = 0;
  deck -> cards[n_cards] -> value = ans -> value;
  deck ->cards[n_cards]-> suit = ans -> suit;
  return ans;
  
}


deck_t * make_deck_exclude(deck_t * excluded_cards)
{
  deck_t * ans = malloc (sizeof(*ans));
  ans -> n_cards = 52; 
  ans -> cards = malloc ((ans -> n_cards) * (sizeof(*ans-> cards)));
  for ( unsigned  i = 0; i < ans -> n_cards; i++)
    {
      ans -> cards[i] = card_from_num(i);
    }
  for ( unsigned i = 0; i < excluded_cards -> n_cards; i++)
    {
      int n =  deck_contains(ans, excluded_cards -> cards[i]);
      if ( n == 1)
	{
	  for ( int j = 0; j < 52; j++)
	    {
	      if ( ans -> cards[j] -> value == excluded_cards -> cards[i] -> value)
		{
		  if ( ans -> cards[j] -> suit == excluded_cards -> cards[i] -> suit)
		    {
		      ans -> cards[j] = NULL;
		      ans -> n_cards--;
		    }
		}
	    }
	}
    }
  return ans;
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands)
{
  deck_t * temp = malloc ( sizeof(*temp));
  temp -> n_cards = 0;
  temp -> cards = malloc ( (temp -> n_cards + 1) * ( sizeof(*temp -> cards)));
  for ( int i = 0; i < n_hands; i++)
    {
      for ( int j = 0; j < hands[i] -> n_cards; j++)
	{
	  temp -> n_cards++;
	  add_card_to(temp, hands[i]->cards[j]);
	}
    }
  deck_t * ans = make_deck_exclude(temp);
  free_deck(ans);
  free_deck(temp);
  return ans;
  
}

void free_deck(deck_t * deck)
{
  for ( int i = 0; i < deck -> n_cards; i++)
    {
      free(deck -> cards[i]);
    }
  free(deck -> cards);
  free(deck);
  
}

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

