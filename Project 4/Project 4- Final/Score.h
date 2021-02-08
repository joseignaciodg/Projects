#ifndef Score_h
#define Score_h
#include <iostream>
#include <string>
#include <fstream>

const std::string SCORESTXT = "scores.txt";

const int Array_Size = 4;

typedef struct {
	std::string name;
	int score;
}tPlayerScore;

typedef tPlayerScore *tPlayerScorePtr;

typedef struct {
	tPlayerScorePtr *array_classification;
	int num_players;
	int capacity;
}tScores;

bool loadScore(tScores &scores, const std::string &SCORESTXT);
bool updateScore(tScores &scores, const std::string &name, int new_value);
void displayScore(const tScores &scores);
void saveScore(const tScores &scores, const std::string &SCORESTXT);
void resize(tScores &scores);
void free(tScores & scores);
void sort_scores(tScores & scores);
void sort_scores_alfabetically(tScores &score);
#endif