#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert((SPADES <= c.suit) && (c.suit <= CLUBS));
  assert((2 <= c.value) && (c .value <= VALUE_ACE));
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH: return "Straight flush";
  case FOUR_OF_A_KIND: return "Four of a kind";
  case FULL_HOUSE: return "Full house";
  case FLUSH: return "Flush";
  case STRAIGHT: return "Straight";
  case THREE_OF_A_KIND: return "Three of a kind";
  case TWO_PAIR: return "Two pairs";
  case PAIR: return "Pair";
  case NOTHING: return "Nothing";
  }
  return "";
}

char value_letter(card_t c) {
  if (c.value > 1 && c.value < 10) {
    return '0' + c.value;
  }
  switch(c.value) {
    case 10: return '0';
    case 11: return 'J';
    case 12: return 'Q';
    case 13: return 'K';
    case 14: return 'A';
  }
   
  return 'x';
}


char suit_letter(card_t c) {
  switch(c.suit) {
    case SPADES: return 's';
    case HEARTS: return 'h';
    case DIAMONDS: return 'd';
    case CLUBS: return 'c';
    case NUM_SUITS: return 'x';
  }
  return 'x';
  
}

void print_card(card_t c) {
  printf("%c%c", value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  if (value_let > '1' && value_let <= '9') {
    temp.value = value_let - '0';
  } else {
      switch(value_let) {
        case '0': temp.value = 0; break;
        case 'J': temp.value = 11; break;
        case 'Q': temp.value = 12; break;
        case 'K': temp.value = 13; break;
        case 'A': temp.value = 14; break;
        //default: fprintf(stderr, "Invalid card value: %d\n", value_let); exit(EXIT_FAILURE);
      }
  }

  switch(suit_let) {
    case 's': temp.suit = SPADES; break;
    case 'h': temp.suit = HEARTS; break;
    case 'd': temp.suit = DIAMONDS; break;
    case 'c': temp.suit = CLUBS; break;
    //default: fprintf(stderr, "Invalid card suite: %c", suit_let); exit(EXIT_FAILURE);
  }
  return temp;
}

card_t card_from_num(unsigned c) {
  unsigned val, suit;

  val = c % 13;
  suit = c / 13;

  if (val == 0) {
    val = 0;
  } else if (val > 8) {
    val += 2;
  } else val++;

  card_t temp;
  temp.value = val;
  temp.suit = suit;
  return temp;
}

