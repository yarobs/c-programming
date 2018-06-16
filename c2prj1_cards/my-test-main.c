#include <stdio.h>
#include "cards.h"

int main(void) {
  card_t c1, c2, c3, c4, c5;

  c5.value = 14;
  c5.suit = 3;

  assert_card_valid(c5);
  
  c1 = card_from_letters('A', 's');
  c2 = card_from_letters('K', 'd');
  c3 = card_from_letters('9', 'h');
  c4 = card_from_letters('0', 'c');

  print_card(c1);
  printf("\n");
  print_card(c2);
  printf("\n");
  print_card(c3);
  printf("\n");
  print_card(c4);
  printf("\n");
  print_card(c5);
  printf("\n");

}
