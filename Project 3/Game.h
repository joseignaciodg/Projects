#ifndef Game_h
#define Game_h
#include "Card_Sequence.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm> 
#include <conio.h>
#include <Windows.h>

const int NUMBER_OF_TILE_TYPES = 6;
const int MAX_PLAYERS = 4;
const int Rows = 8;
const int Column = 8;
const int PALETTE[NUMBER_OF_TILE_TYPES + MAX_PLAYERS] = { 1, 11, 7, 4, 12, 5, 13, 9, 10, 3 };

typedef enum { NORTH, SOUTH, EAST, WEST } tDir;
typedef enum { EMPTY, ICE, WALL, BOX, GEM, TURTLE } tTileState;
typedef enum { Advance, Turnright, Turnleft, Laser, Exit, Execute, Steal, Nothing } tKey;

typedef struct {
	int x;
	int y;
}tCoordenate;

typedef struct {
	int number;
	tDir direction;
}tTurtle;

typedef struct {
	tTileState state;
	tTurtle turtle;
}tTile;

typedef tTile tBoard[Rows][Column];

typedef struct {
	std::string name;
	tDeck deck;
	tHand playshands;
	tDir ActualDirection;
	tCoordenate ActualPosition;
}tPlayer;

typedef struct {
	int numPlayers;
	int Actualturn;
	tPlayer players[MAX_PLAYERS];
	tBoard board;
}tGame;

tKey readKey();
bool loadGame(tGame &game);
void displayGame(const tGame &game);
void changeTurn(tGame &game);
void includeCard(tHand &hand, tCard card);
bool sequenceAction(tHand &hand, tGame & game, tDeck & cards);
bool isMatchEnd(tGame &game);
bool executeTurn(tGame &game);
bool stealAction(tGame &game);
void backgroundColor(int color);
bool moveTurtle(tGame &game, tCard Card);
tCard KeyToCard(tKey key);

#endif