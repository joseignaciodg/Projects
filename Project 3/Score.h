#ifndef Score_h
#define Score_h
#include <iostream>
#include <string>
#include <fstream>

const std::string SCORESTXT = "scores.txt";
const int MAX_PlayersTable = 10;

typedef struct {
	std::string name;
	int score;
}tPlayerScore;

typedef tPlayerScore tArrayScore[MAX_PlayersTable];

typedef struct {
	tArrayScore Scores;
	int num_players;
}tScores;

bool loadScore(tScores &scores, const std::string &SCORESTXT);
bool updateScore(tScores &scores, const std::string &name, int new_value);
void displayScore(const tScores &scores);
void saveScore(const tScores &scores, const std::string &SCORESTXT);

#endif