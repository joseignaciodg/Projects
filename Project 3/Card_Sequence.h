#ifndef Card_Sequence_h
#define Card_Sequence_h
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdlib>

typedef enum { ADVANCE, TURNLEFT, TURNRIGHT, LASER, NOTHING } tCard;

const int MAX = 38;

typedef tCard tArray[MAX];

typedef struct {
	tArray cards_total;
	tArray cards_sequence;
	int counter; //cards_totals counter
	int numCards; //cards_sequences counter
}tDeck;

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

#endif
