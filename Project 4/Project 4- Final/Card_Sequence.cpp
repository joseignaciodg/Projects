#include "Card_Sequence.h"
#include "checkML.h"

void createEmpty(tDeck &deck) {


	for (int i = 0; i < MAX; i++) {
		if (i < 18) {
			deck.cards_total[i] = new tCard (ADVANCE);//modificated
		}
		else if ((i < 26) && (i >= 18)) {
			deck.cards_total[i] = new tCard(TURNRIGHT);//modificated
		}
		else if ((i < 34) && (i >= 26)) {
			deck.cards_total[i] = new tCard(TURNLEFT);//modificated
		}
		else {
			deck.cards_total[i] = new tCard(LASER);//modificated
		}
	}
	deck.counter = MAX - 1;
}

bool take(tDeck &deck, tCard &card) {
	bool ok = false;

	if (deck.counter >= 0) {
		card = *deck.cards_total[deck.counter];//modificated
		deck.cards_total[deck.counter] = new tCard(NOTHING);//modificated
		ok = true;
		deck.counter--;
	}
	return ok;
}

void insert(tDeck &deck, tCard card) {
	if (deck.counter < MAX - 1) {
		deck.counter++;
		*deck.cards_total[deck.counter] = card;//modificated
		
	}
}

void createRandomPack(tDeck &deck) {
	std::random_shuffle(std::begin(deck.cards_total), std::end(deck.cards_total));
}

void free(tDeck & deck) {
	for (int i = 0; i < deck.counter; i++) {
		delete deck.cards_total[i];
	}
	*deck.cards_total = nullptr;// * added
	deck.counter = 0;
	deck.numCards = 0;
}