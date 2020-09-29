#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void add_card_to(deck_t * deck, card_t c)
{
  card_t* c1 = malloc(sizeof(*c1));

  c1->value = c.value;

  c1->suit = c.suit;
  deck -> cards = realloc ( deck -> cards, (deck -> n_cards + 1 ) *( sizeof(*deck -> cards)));
  deck -> cards[deck -> n_cards] = c1;
  deck -> n_cards++;
    
}


card_t * add_empty_card(deck_t * deck)
{
  card_t * temp =malloc(sizeof(*temp)) ;
  temp -> value = 0;
  temp -> suit = 0; 
  deck -> cards = realloc ( deck -> cards, (deck -> n_cards + 1)*(sizeof(*deck -> cards)));
  deck -> cards[deck -> n_cards  ] =  temp;
  deck -> n_cards++;
  return temp;
  
}


deck_t * make_deck_exclude(deck_t * excluded_cards)
{
  deck_t * ans = malloc (sizeof(*ans));
  ans -> n_cards = 0; 
  ans -> cards = NULL;
  for ( unsigned  i = 0; i < 52; i++)
    {
      card_t c  = card_from_num(i);
      if (! deck_contins(excluded_cards, c))
	{
	  add_card_to(ans,c);
	}
    }
  return ans;
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands)
{
  deck_t * temp = malloc ( sizeof(*temp));
  temp -> n_cards = 0;
  temp -> cards = NULL;
  for ( int i = 0; i < n_hands; i++)
    {
      for ( int j = 0; j < hands[i] -> n_cards; j++)
	{
	  add_card_to(temp, *hands[i]-> cards[j]);
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

