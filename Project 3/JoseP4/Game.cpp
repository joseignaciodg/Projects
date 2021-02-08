#include "Game.h"

bool loadGame(tGame &game) {
	bool cargado = false;
	tCard card;
	std::string file, line;
	char character;
	std::ifstream file1;
	int aux;
	int numTurtle;

	game.Actualturn = 0;

	std::cout << "Write the name of the filename: ";
	std::cin >> file;
	file1.open(file.c_str());

	if (file1.is_open()) {

		std::cout << "Introduce number of players: ";
		std::cin >> game.numPlayers;
		for (int i = 0; i < game.numPlayers; i++) {
			std::cout << "Introduce nickname of player " << i + 1 << ": ";
			std::cin >> game.players[i].name;
		}


		std::cout << std::endl;
		while (!cargado) {
			file1 >> aux;
			if (aux == game.numPlayers) {
				cargado = true;

				for (int i = 0; i < Rows; i++) {
					for (int j = 0; j < Column; j++) {
						file1 >> character;
						switch (character) {
						case '#':game.board[i][j].state = WALL;
							break;
						case '@':game.board[i][j].state = ICE;
							break;
						case 'C':game.board[i][j].state = BOX;
							break;
						case '$':game.board[i][j].state = GEM;
							break;
						case '*':game.board[i][j].state = EMPTY;
							break;
						default: game.board[i][j].state = TURTLE;

							switch (character) {

							case'U':
								numTurtle = 3;
								game.board[i][j].turtle.direction = NORTH;
								game.board[i][j].turtle.number = numTurtle;
								game.players[numTurtle].ActualPosition.x = i; 
								game.players[numTurtle].ActualPosition.y = j; 
								game.players[numTurtle].ActualDirection = NORTH;
								break;
							case'D':
								numTurtle = 0;
								game.board[i][j].turtle.direction = SOUTH;
								game.board[i][j].turtle.number = numTurtle;
								game.players[numTurtle].ActualPosition.x = i;
								game.players[numTurtle].ActualPosition.y = j;
								game.players[numTurtle].ActualDirection = SOUTH;
								break;
							case'R':
								numTurtle = 2;
								game.board[i][j].turtle.direction = EAST;
								game.board[i][j].turtle.number = numTurtle;
								game.players[numTurtle].ActualPosition.x = i;
								game.players[numTurtle].ActualPosition.y = j;
								game.players[numTurtle].ActualDirection = EAST;
								break;
							case'L':
								numTurtle = 1;
								game.board[i][j].turtle.direction = WEST;
								game.board[i][j].turtle.number = numTurtle;
								game.players[numTurtle].ActualPosition.x = i;
								game.players[numTurtle].ActualPosition.y = j;
								game.players[numTurtle].ActualDirection = WEST;
								break;
							}
						}
					}
				}
			}
			for (int i = 0; i < Rows; i++) {
				file1 >> line;
			}
		}
		file1.close();

		for (int i = 0; i < game.numPlayers; i++) {
			game.players[i].playshands.moveforward = 0;
			game.players[i].playshands.turnleft = 0;
			game.players[i].playshands.turnright = 0;
			game.players[i].playshands.lasergun = 0;
		}

		for (int i = 0; i < game.numPlayers; i++) {
			createEmpty(game.players[i].deck);
			createRandomPack(game.players[i].deck);
			for (int j = 0; j < 3; j++) {
				take(game.players[i].deck, card);
				includeCard(game.players[i].playshands, card);
			}
		}
	}
	return cargado;
}

void displayGame(const tGame &game) { 
	system("cls");

	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Column; j++) {
			if (game.board[i][j].state == EMPTY) {
				backgroundColor(PALETTE[0]);
				std::cout << "  ";
			}
			else if (game.board[i][j].state == WALL) {
				backgroundColor(PALETTE[2]);
				std::cout << "||";
			}
			else if (game.board[i][j].state == ICE) {
				backgroundColor(PALETTE[1]);
				std::cout << "**";
			}
			else if (game.board[i][j].state == GEM) {
				backgroundColor(PALETTE[4]);
				std::cout << "00";
			}
			else if (game.board[i][j].state == BOX) {
				backgroundColor(PALETTE[3]);
				std::cout << "[]";
			}
			else {
				if (game.board[i][j].turtle.number == 0) {
					backgroundColor(PALETTE[5]);
					if (game.board[i][j].turtle.direction == NORTH) {
						std::cout << "^^";
					}
					else if (game.board[i][j].turtle.direction == SOUTH) {
						std::cout << "vv";
					}
					else if (game.board[i][j].turtle.direction == EAST) {
						std::cout << ">>";
					}
					else {
						std::cout << "<<";
					}
				}
				else if (game.board[i][j].turtle.number == 1) {
					backgroundColor(PALETTE[6]);
					if (game.board[i][j].turtle.direction == NORTH) {
						std::cout << "^^";
					}
					else if (game.board[i][j].turtle.direction == SOUTH) {
						std::cout << "vv";
					}
					else if (game.board[i][j].turtle.direction == EAST) {
						std::cout << ">>";
					}
					else {
						std::cout << "<<";
					}
				}
				else if (game.board[i][j].turtle.number == 2) {
					backgroundColor(PALETTE[7]);
					if (game.board[i][j].turtle.direction == NORTH) {
						std::cout << "^^";
					}
					else if (game.board[i][j].turtle.direction == SOUTH) {
						std::cout << "vv";
					}
					else if (game.board[i][j].turtle.direction == EAST) {
						std::cout << ">>";
					}
					else {
						std::cout << "<<";
					}
				}
				else if (game.board[i][j].turtle.number == 3) {
					backgroundColor(PALETTE[8]);
					if (game.board[i][j].turtle.direction == NORTH) {
						std::cout << "^^";
					}
					else if (game.board[i][j].turtle.direction == SOUTH) {
						std::cout << "vv";
					}
					else if (game.board[i][j].turtle.direction == EAST) {
						std::cout << ">>";
					}
					else {
						std::cout << "<<";
					}
				}
			}
		}
		std::cout << std::endl;
	}
	backgroundColor(0);
	std::cout << std::endl << std::endl;
	std::cout << "PLAYERS:" << std::endl << std::endl;
	for (int i = 0; i < game.numPlayers; i++) {
		if (i == 0) {
			backgroundColor(PALETTE[5]);
		}
		else if (i == 1) {
			backgroundColor(PALETTE[6]);
		}
		else if (i == 2) {
			backgroundColor(PALETTE[7]);
		}
		else if (i == 3) {
			backgroundColor(PALETTE[8]);
		}

		if (game.Actualturn == i) {
			std::cout << std::setw(1) << std::left << ">"; // It does not appear the arrow >
			std::cout << std::setw(3) << std::right << i + 1 << "." << std::setw(8) << game.players[i].name << ": ";
			backgroundColor(0);
			std::cout << " " << game.players[i].playshands.moveforward;
			backgroundColor(PALETTE[9]);
			std::cout << " ^ ";
			backgroundColor(0);
			std::cout << " ";
			std::cout << " " << game.players[i].playshands.turnleft;
			backgroundColor(PALETTE[9]);
			std::cout << " < ";
			backgroundColor(0);
			std::cout << " ";
			std::cout << " " << game.players[i].playshands.turnright;
			backgroundColor(PALETTE[9]);
			std::cout << " > ";
			backgroundColor(0);
			std::cout << " ";
			std::cout << " " << game.players[i].playshands.lasergun;
			backgroundColor(PALETTE[9]);
			std::cout << " ~ ";
			backgroundColor(0);
			std::cout << std::endl;
		}
		else {
			std::cout << std::setw(1) << std::left << " ";
			std::cout << std::setw(3) << std::right << i + 1 << "." << std::setw(8) << game.players[i].name << ": ";
			backgroundColor(0);
			std::cout << " " << game.players[i].playshands.moveforward;
			backgroundColor(PALETTE[9]);
			std::cout << " ^ ";
			backgroundColor(0);
			std::cout << " ";
			std::cout << " " << game.players[i].playshands.turnleft;
			backgroundColor(PALETTE[9]);
			std::cout << " < ";
			backgroundColor(0);
			std::cout << " ";
			std::cout << " " << game.players[i].playshands.turnright;
			backgroundColor(PALETTE[9]);
			std::cout << " > ";
			backgroundColor(0);
			std::cout << " ";
			std::cout << " " << game.players[i].playshands.lasergun;
			backgroundColor(PALETTE[9]);
			std::cout << " ~ ";
			backgroundColor(0);
			std::cout << std::endl;
		}
	}
}

void changeTurn(tGame &game) {

	if (game.Actualturn == game.numPlayers - 1) { 
		game.Actualturn = 0;
	}
	else {
		game.Actualturn++;
	}
}

bool executeTurn(tGame &game) {
	bool executed = false;
	tKey option;
	tDeck deck;

	while (!executed) {
		std::cout << std::endl;
		std::cout << "Choose an option" << std::endl;
		std::cout << "S: Steal" << std::endl;
		std::cout << "E: Execute a sequence" << std::endl;
		option = readKey();

		if (option == Execute) {
			std::cout << "Choose sequence" << std::endl;
			if (sequenceAction(game.players[game.Actualturn].playshands, game, deck)) {
				executed = true;
			}
		}

		else if (option == Steal) {
			if (stealAction(game)) {
				std::cout << "Card stolen" << std::endl;
				executed = true;
			}
			else {
				std::cout << "Steal action unexecuted" << std::endl;
			}
		}
	}

	return executed;
}

bool isMatchEnd(tGame &game) {
	bool end = false;
	for (int i = 3; i <= 4; i++) {
		for (int j = 3; j <= 4; j++) {
			if (game.players[game.Actualturn].ActualPosition.x == i && game.players[game.Actualturn].ActualPosition.y == j) {
				end = true;
			}
		}
	}
	return end;
}

bool stealAction(tGame &game) {
	bool steal;
	tCard card;

	steal = take(game.players[game.Actualturn].deck, card);
	if (steal) {
		includeCard(game.players[game.Actualturn].playshands, card);
	}
	return steal;
}

bool moveTurtle(tGame &game, tCard Card) {
	int iterator = 0, numberTurtle;
	int horizontal, vertical;
	bool ice = false;
	bool move = false;

	horizontal = game.players[game.Actualturn].ActualPosition.x;
	vertical = game.players[game.Actualturn].ActualPosition.y;

	numberTurtle = game.board[horizontal][vertical].turtle.number;

	if (Card == ADVANCE) {

		if (game.board[horizontal][vertical].turtle.direction == NORTH) {

			if ((game.board[horizontal - 1][vertical].state == EMPTY) || (game.board[horizontal - 1][vertical].state == GEM)) {
				game.board[horizontal - 1][vertical].state = TURTLE;
				game.board[horizontal - 1][vertical].turtle.direction = NORTH;
				game.board[horizontal - 1][vertical].turtle.number = numberTurtle;
				game.board[horizontal][vertical].state = EMPTY; //turn the tile where the turtle was into a empty tile
				game.players[game.Actualturn].ActualPosition.x = horizontal - 1;
				game.players[game.Actualturn].ActualPosition.y = vertical;
				move = true;
			}
			else if (game.board[horizontal - 1][vertical].state == BOX) {
				if (game.board[horizontal - 2][vertical].state == EMPTY) {
					game.board[horizontal - 2][vertical].state = BOX; //pushes the box
					game.board[horizontal - 1][vertical].state = TURTLE;
					game.board[horizontal - 1][vertical].turtle.direction = NORTH;
					game.board[horizontal - 1][vertical].turtle.number = numberTurtle;
					game.board[horizontal][vertical].state = EMPTY;
					game.players[game.Actualturn].ActualPosition.x = horizontal - 1;
					game.players[game.Actualturn].ActualPosition.y = vertical;
					move = true;
				}
			}
		}

		else if (game.board[horizontal][vertical].turtle.direction == SOUTH) {

			if ((game.board[horizontal + 1][vertical].state == EMPTY) || (game.board[horizontal + 1][vertical].state == GEM)) {
				game.board[horizontal + 1][vertical].state = TURTLE;
				game.board[horizontal + 1][vertical].turtle.direction = SOUTH;
				game.board[horizontal + 1][vertical].turtle.number = numberTurtle;
				game.board[horizontal][vertical].state = EMPTY; //turn the tile where the turtle was into a empty tile
				game.players[game.Actualturn].ActualPosition.x = horizontal + 1;
				game.players[game.Actualturn].ActualPosition.y = vertical;
				move = true;
			}
			else if (game.board[horizontal + 1][vertical].state == BOX) {
				if (game.board[horizontal + 2][vertical].state == EMPTY) {
					game.board[horizontal + 2][vertical].state = BOX; //pushes the box
					game.board[horizontal + 1][vertical].state = TURTLE;
					game.board[horizontal + 1][vertical].turtle.direction = SOUTH;
					game.board[horizontal + 1][vertical].turtle.number = numberTurtle;
					game.board[horizontal][vertical].state = EMPTY;
					game.players[game.Actualturn].ActualPosition.x = horizontal + 1;
					game.players[game.Actualturn].ActualPosition.y = vertical;
					move = true;
				}
			}
		}

		else if (game.board[horizontal][vertical].turtle.direction == WEST) {

			if ((game.board[horizontal][vertical - 1].state == EMPTY) || (game.board[horizontal][vertical - 1].state == GEM)) {
				game.board[horizontal][vertical - 1].state = TURTLE;
				game.board[horizontal][vertical - 1].turtle.direction = WEST;
				game.board[horizontal][vertical - 1].turtle.number = numberTurtle;
				game.board[horizontal][vertical].state = EMPTY; //turn the tile where the turtle was into a empty tile
				game.players[game.Actualturn].ActualPosition.x = horizontal;
				game.players[game.Actualturn].ActualPosition.y = vertical - 1;
				move = true;
			}
			else if (game.board[horizontal][vertical - 1].state == BOX) {
				if (game.board[horizontal][vertical - 2].state == EMPTY) {
					game.board[horizontal][vertical - 2].state = BOX; //pushes the box
					game.board[horizontal][vertical - 1].state = TURTLE;
					game.board[horizontal][vertical - 1].turtle.direction = WEST;
					game.board[horizontal][vertical - 1].turtle.number = numberTurtle;
					game.board[horizontal][vertical].state = EMPTY;
					game.players[game.Actualturn].ActualPosition.x = horizontal;
					game.players[game.Actualturn].ActualPosition.y = vertical - 1;
					move = true;
				}
			}
		}

		else if (game.board[horizontal][vertical].turtle.direction == EAST) {

			if ((game.board[horizontal][vertical + 1].state == EMPTY) || (game.board[horizontal][vertical + 1].state == GEM)) {
				game.board[horizontal][vertical + 1].state = TURTLE;
				game.board[horizontal][vertical + 1].turtle.direction = EAST;
				game.board[horizontal][vertical + 1].turtle.number = numberTurtle;
				game.board[horizontal][vertical].state = EMPTY; //turn the tile where the turtle was into a empty tile
				game.players[game.Actualturn].ActualPosition.x = horizontal;
				game.players[game.Actualturn].ActualPosition.y = vertical + 1;
				move = true;
			}
			else if (game.board[horizontal][vertical + 1].state == BOX) {
				if (game.board[horizontal][vertical + 2].state == EMPTY) {
					game.board[horizontal][vertical + 2].state = BOX; //pushes the box
					game.board[horizontal][vertical + 1].state = TURTLE;
					game.board[horizontal][vertical + 1].turtle.direction = EAST;
					game.board[horizontal][vertical + 1].turtle.number = numberTurtle;
					game.board[horizontal][vertical].state = EMPTY;
					game.players[game.Actualturn].ActualPosition.x = horizontal;
					game.players[game.Actualturn].ActualPosition.y = vertical + 1;
					move = true;
				}
			}
		}
	}
	else if (Card == TURNLEFT) {
		
		if (game.board[horizontal][vertical].turtle.direction == NORTH) {
			game.board[horizontal][vertical].turtle.direction = WEST;
		}
		else if (game.board[horizontal][vertical].turtle.direction == WEST) {
			game.board[horizontal][vertical].turtle.direction = SOUTH;
		}
		else if (game.board[horizontal][vertical].turtle.direction == SOUTH) {
			game.board[horizontal][vertical].turtle.direction = EAST;
		}
		else if (game.board[horizontal][vertical].turtle.direction == EAST) {
			game.board[horizontal][vertical].turtle.direction = NORTH;
		}
		move = true;
	}
	else if (Card == TURNRIGHT) {
		
		if (game.board[horizontal][vertical].turtle.direction == NORTH) {
			game.board[horizontal][vertical].turtle.direction = EAST;
		}
		else if (game.board[horizontal][vertical].turtle.direction == EAST) {
			game.board[horizontal][vertical].turtle.direction = SOUTH;
		}
		else if (game.board[horizontal][vertical].turtle.direction == SOUTH) {
			game.board[horizontal][vertical].turtle.direction = WEST;
		}
		else if (game.board[horizontal][vertical].turtle.direction == WEST) {
			game.board[horizontal][vertical].turtle.direction = NORTH;
		}
		move = true;
	}
	else if (Card == LASER) {
		
		if (game.board[horizontal][vertical].turtle.direction == NORTH) {
			iterator = horizontal;
			while ((!ice) && (iterator > 0)) {
				if (game.board[iterator - 1][vertical].state == ICE) {
					game.board[iterator - 1][vertical].state = EMPTY;
					ice = true; //found ice block
				}
				else if ((game.board[iterator - 1][vertical].state == WALL) && (game.board[iterator - 1][vertical].state == GEM)) {
					ice = true;
				}
				else {
					iterator--;
				}
			}

		}

		else if (game.board[horizontal][vertical].turtle.direction == EAST) {
			iterator = vertical;
			while ((!ice) && (iterator < Column)) {
				if (game.board[horizontal][iterator - 1].state == ICE) {
					game.board[horizontal][iterator - 1].state = EMPTY;
					ice = true; //found ice block
				}
				else if ((game.board[horizontal][iterator - 1].state == WALL) && (game.board[horizontal][iterator - 1].state == GEM)) {
					ice = true;
				}
				else {
					iterator++;
				}
			}
		}

		else if (game.board[horizontal][vertical].turtle.direction == WEST) {
			iterator = vertical;
			while ((!ice) && (iterator > 0)) {
				if (game.board[horizontal][iterator + 1].state == ICE) {
					game.board[horizontal][iterator + 1].state = EMPTY;
					ice = true; //found ice block
				}
				else if ((game.board[horizontal][iterator + 1].state == WALL) && (game.board[horizontal][iterator + 1].state == GEM)) {
					ice = true;
				}
				else {
					iterator--;
				}
			}
		}

		else if (game.board[horizontal][vertical].turtle.direction == SOUTH) {
			iterator = horizontal;
			while ((!ice) && (iterator < Rows)) {
				if (game.board[iterator + 1][vertical].state == ICE) {
					game.board[iterator + 1][vertical].state = EMPTY;
					ice = true; //found ice block
				}
				else if ((game.board[iterator + 1][vertical].state == WALL) && (game.board[iterator + 1][vertical].state == GEM)) {
					ice = true;
				}
				else {
					iterator++;
				}
			}
		}
		move = true;
	}
	return move;
}

bool sequenceAction(tHand &hand, tGame & game, tDeck & cards) {
	tKey key;
	tCard card;
	int i = 0;
	bool ok = true;
	cards.numCards = 0;

	key = readKey();

	while (key != Exit) {
		card = KeyToCard(key);

		if (card == ADVANCE) {
			if (hand.moveforward > 0) {
				hand.moveforward--;
				std::cout << "^^ ";
			}
		}
		else if (card == TURNRIGHT) {
			if (hand.turnright > 0) {
				hand.turnright--;
				std::cout << ">> ";
			}
		}
		else if (card == TURNLEFT) {
			if (hand.turnleft > 0) {
				hand.turnleft--;
				std::cout << "<< ";
			}
		}
		else if (card == LASER) {
			if (hand.lasergun > 0) {
				hand.lasergun--;
				std::cout << "~ ";
			}
		}
		if (card != NOTHING) {
			cards.cards_sequence[cards.numCards] = card;
			cards.numCards++;
		}
		key = readKey();

	}
	
	while (i < cards.numCards && !isMatchEnd(game) && ok) {
		ok = moveTurtle(game, cards.cards_sequence[i]);
		if (!ok) {
			std::cout << "Couldn't execute after the " << i + 1 << " action." << std::endl;
		}
		i++;
	}

	if (!ok) {
		ok = true;
		for (int j = i - 1; j < cards.numCards; j++) {
			includeCard(game.players[game.Actualturn].playshands, cards.cards_sequence[j]);
			cards.cards_sequence[j] = NOTHING;
		}
		for (int j = 0; j < i - 1; j++) {
			insert(game.players[game.Actualturn].deck, cards.cards_sequence[j]);
			cards.cards_sequence[j] = NOTHING;
		}
	}

	else {
		for (int j = 0; j < cards.numCards; j++) {
			insert(game.players[game.Actualturn].deck, cards.cards_sequence[j]);
			cards.cards_sequence[j] = NOTHING;
		}
	}
	return ok;
}

tCard KeyToCard(tKey key) {
	tCard card;

	if (key == Advance) {
		card = ADVANCE;
	}
	else if (key == Turnleft) {
		card = TURNLEFT;
	}
	else if (key == Turnright) {
		card = TURNRIGHT;
	}
	else if (key == Laser) {
		card = LASER;
	}
	else {
		card = NOTHING;
	}
	return card;
}

void backgroundColor(int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}

void includeCard(tHand &hand, tCard card) {

	if (card == ADVANCE) {
		hand.moveforward++;
	}
	else if (card == TURNRIGHT) {
		hand.turnright++;
	}
	else if (card == TURNLEFT) {
		hand.turnleft++;
	}
	else {
		hand.lasergun++;
	}
}

tKey readKey() {

	tKey keyboard;
	int dir;
	std::cin.sync();
	dir = _getch();

	if (dir == 0xe0) {
		dir = _getch();
		if (dir == 75) {
			keyboard = Turnleft;
		}
		else if (dir == 77) {
			keyboard = Turnright;
		}
		else if (dir == 72) {
			keyboard = Advance;
		}
		else {
			keyboard = Nothing;
		}
	}

	else if (dir == 32) {
		keyboard = Laser;
	}

	else if (dir == 13) {
		keyboard = Exit;
	}

	else if (dir == 69) {
		keyboard = Execute;
	}

	else if (dir == 101) {
		keyboard = Execute;
	}

	else if (dir == 83) {
		keyboard = Steal;
	}

	else if (dir == 115) {
		keyboard = Steal;
	}

	else {
		keyboard = Nothing;
	}
	return keyboard;
}