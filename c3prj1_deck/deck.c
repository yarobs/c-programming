#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t *hand){
    int i;
    card_t c;

    for (i = 0; i < hand->n_cards; i++){
        c = *(hand->cards[i]);
        print_card(c);
        printf(" ");
    }
}

int deck_contains(deck_t *d, card_t c){
    int i;
    card_t d_card;

    for (i = 0; i < d->n_cards; i++){
        d_card = *(d->cards[i]);
        if (c.value == d_card.value && c.suit == d_card.suit){
            return 1;
        }
    }
    return 0;
}

void shuffle(deck_t *d){
    int i, r;
    size_t n_cards = d->n_cards - 1;
    card_t *temp_c;
    card_t **deck = d->cards;
    
    for (i = 0; i < n_cards; i++){
        r = rand() % (n_cards + 1 - i) + i;
        temp_c = deck[i];
	deck[i] = deck[r];
	deck[r] = temp_c;
    }
}

void assert_full_deck(deck_t * d){
    int i;
    card_t c;
    for (i = 0; i < d->n_cards - 1; i++){
        c = *(d->cards[i]);
        assert_card_valid(c);
        assert(deck_contains(d, c));
    }
}
