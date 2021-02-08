//PROJECT 4 - Robotic Turtles 2.0
#include "Card_Sequence.h"
#include "Game.h"
#include "Score.h"
#include "checkML.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm> 
#include <conio.h>
#include <Windows.h>
using namespace std;

int menu2();
int menu();

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(time(NULL));
	tGame game;
	tDeck deck;
	tScores scores;
	string name;
	int choice, choice2, new_value = 0;
	bool ok = false;
	bool ok2 = false;
	bool end;
	
	scores.capacity = Array_Size;
	scores.array_classification = new tPlayerScorePtr[Array_Size];

	if (loadScore(scores, SCORESTXT)) {
		while (!ok) {
			end = false;
			choice = menu();
			if (choice == 1) {
				if (loadGame(game)) {
					while (!end) {
						displayGame(game);
						executeTurn(game);
						if (isMatchEnd(game)) {
							system("cls");
							cout << game.players[game.Actualturn].name << " has won the game!" << endl;
							if (updateScore(scores, game.players[game.Actualturn].name, game.numPlayers)) {
								cout << "Scores update" << endl;
							}
							else {
								cout << "Couldn't save the user in the scores..." << endl;
							}
							end = true;
						}
						changeTurn(game);
					}
				}
				else {
					cout << "Couldn't load the game..." << endl;
					ok = true;
				}
			}
			else if (choice == 2) {
				while (!ok2) {
					choice2 = menu2();
					if (choice2 == 1) {
						sort_scores(scores);
						displayScore(scores);
						ok2 = false;
					}
					else if (choice2 == 2) {
						sort_scores_alfabetically(scores);
						displayScore(scores);
						ok2 = false;
					}
					else if (choice2 == 0) {
						ok2 = true;
					}
				}
			}
			else if (choice == 3) {
				cout << "The players are numbered from 1 to the total amount of players, " << endl <<
					"and the play each round by following an ascending order of their corresponding number." << endl <<
					"A player cant carry out one of this actions during her turn :" << endl <<
					"-Steal a card from the top of the pack deck and add it to her hand." << endl <<
					"-Create a sequence from a subset of the cards in the hand and execute the sequence by following the previously described rules." << endl <<
					"The used cards will go back to the bottom of the pack in any order.The player placing her turtle on a gem wins the game." << endl;
			}
			else if (choice == 0) {
				saveScore(scores, SCORESTXT);
				ok = true;
			}
		}
	}
	else {
		cout << "Couldn't load the scores..." << endl;
		ok = true;
	}
	free(scores);
	free(deck);
	return 0;
}

int menu() {
	int num;
	cout << endl;
	cout << "1- Play " << endl;
	cout << "2- Show scores" << endl;
	cout << "3- Instructions" << endl;
	cout << "0- Exit" << endl;
	cout << "Please choose an option: ";
	cin >> num;
	cout << endl;

	if ((num < 0) || (num > 3)) {
		cout << "Invalid option! Please try again... " << endl;
	}
	return num;
}

int menu2() {
	int num2;
	cout << endl;
	cout << "How do you want to display the list according to the following orders:" << endl;
	cout << "1- Decreasing ranking order" << endl;
	cout << "2- Alphabetic order" << endl;
	cout << "0- Exit" << endl;
	cout << "Please choose an option: ";
	cin >> num2;
	cout << endl;

	if ((num2 < 0) || (num2 > 2)) {
		cout << "Invalid option! Please try again... " << endl;
	}
	return num2;
}