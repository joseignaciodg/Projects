#include "Card_Sequence.h"

void createEmpty(tDeck &deck) {

	for (int i = 0; i < MAX; i++) {
		if (i < 18) {
			deck.cards_total[i] = ADVANCE;
		}
		else if ((i < 26) && (i >= 18)) {
			deck.cards_total[i] = TURNRIGHT;
		}
		else if ((i < 34) && (i >= 26)) {
			deck.cards_total[i] = TURNLEFT;
		}
		else {
			deck.cards_total[i] = LASER;
		}
	}
	deck.counter = MAX - 1;
}

bool take(tDeck &deck, tCard &card) {
	bool ok = false;

	if (deck.counter >= 0) {
		card = deck.cards_total[deck.counter];
		deck.cards_total[deck.counter] = NOTHING;
		ok = true;
		deck.counter--;
	}
	return ok;
}

void insert(tDeck &deck, tCard card) {
	if (deck.counter < MAX - 1) {
		deck.counter++;
		deck.cards_total[deck.counter] = card;
	}
}

void createRandomPack(tDeck &deck) {
	std::random_shuffle(std::begin(deck.cards_total), std::end(deck.cards_total));
}