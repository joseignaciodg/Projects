#ifndef Card_Sequence_h
#define Card_Sequence_h
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdlib>

typedef enum { ADVANCE, TURNLEFT, TURNRIGHT, LASER, NOTHING } tCard;

const int MAX = 38;

typedef tCard * tArrayPtrCards;
typedef tCard tDeckArray[MAX];
typedef tArrayPtrCards tArraytoArray[MAX];

typedef struct {
	int counter;//cards_totals counter
	int numCards;//cards_sequences counter
	tArraytoArray cards_total;
	tDeckArray cards_sequence;
} tDeck;

typedef struct {
	int moveforward;
	int turnleft;
	int turnright;
	int lasergun;
}tHand;

void createEmpty(tDeck &deck);
bool take(tDeck &deck, tCard &card);
void insert(tDeck &deck, tCard card);
void createRandomPack(tDeck &deck);
void free(tDeck & deck);
#endif
