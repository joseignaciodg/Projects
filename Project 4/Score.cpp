#include "Score.h"
#include "checkML.h"
#include <ctype.h>


void free(tScores &scores) { //final del main
	for (int i = 0; i < scores.num_players; i++) {
		delete scores.array_classification[i];
	}
	delete[] scores.array_classification; //[] eliminar toda array tScores
	scores.array_classification = nullptr;
	scores.num_players = 0;
}

void resize(tScores &scores) {

	tPlayerScorePtr *aux = nullptr;
	aux = new tPlayerScorePtr[4 + scores.capacity]; // de 4 en 4

	for (int i = 0; i < scores.num_players; i++) {
		aux[i] = scores.array_classification[i];
	}
	delete[] scores.array_classification;
	scores.array_classification = aux;
	scores.capacity += 4;
	aux = nullptr;
}

bool loadScore(tScores &scores, const std::string &SCORESTXT) {
	bool cargado = false;
	std::ifstream file;
	scores.num_players = 0;
	file.open(SCORESTXT);

	if (file.is_open()) {
		cargado = true;
		while (file.eof() == false) { //end of file
			if (scores.capacity == scores.num_players) {
				resize(scores);
			}
			scores.array_classification[scores.num_players] = new tPlayerScore;
			file >> scores.array_classification[scores.num_players]->name;
			file >> scores.array_classification[scores.num_players]->score;
			scores.num_players++;
		}
		file.close();
	}
	else {
		std::cout << "Couldn not open the file..." << std::endl;
	}
	return cargado;
}

bool updateScore(tScores &scores, const std::string &name, int new_value) { //poner funcion de resize y ordenar
	bool insert = false;
	bool found = false;
	int i = 0;

	while ((i < scores.num_players) && (!found)) {
		if (scores.array_classification[i]->name == name) {
			found = true;
			insert = true;
			scores.array_classification[i]->score = scores.array_classification[i]->score + new_value;
		}
		else {
			i++;
		}
	}
	if (found == false) {

		if (scores.capacity == scores.num_players) {
			resize(scores);
		}
		
		scores.array_classification[scores.num_players] = new tPlayerScore;
		scores.array_classification[scores.num_players]->name = name;
		scores.array_classification[scores.num_players]->score = new_value;
		scores.num_players++; //works as a counter
		insert = true;

	}
	return insert;
}

void displayScore(const tScores &scores) {

	for (int i = 0; i < scores.num_players; i++) {
		std::cout << scores.array_classification[i]->name;
		std::cout << " ";
		std::cout << scores.array_classification[i]->score << std::endl;
	}
}

void saveScore(const tScores &scores, const std::string &SCORESTXT) {
	std::ofstream file;
	file.open(SCORESTXT);

	for (int i = 0; i < scores.num_players; i++) {
		file << scores.array_classification[i]->name << " ";
		file << scores.array_classification[i]->score << std::endl;
	}
	file.close();
}

void sort_scores(tScores & scores) {
	tPlayerScorePtr tmp; 

	for (int i = 0; i < (scores.num_players - 1); i++) {
		for (int j = (scores.num_players - 1); j > 0; j--) {
			if (scores.array_classification[j]->score > scores.array_classification[j - 1]->score) {
				tmp = scores.array_classification[j];
				scores.array_classification[j] = scores.array_classification[j - 1];
				scores.array_classification[j - 1] = tmp;
			}
			else if (scores.array_classification[j]->score == scores.array_classification[j - 1]->score) {
				for (int k = 0; k < (scores.num_players); k++) {
					scores.array_classification[k]->name[0] = toupper(scores.array_classification[k]->name[0]);
				}
				if (scores.array_classification[j]->name < scores.array_classification[j - 1]->name) {
					tmp = scores.array_classification[j];
					scores.array_classification[j] = scores.array_classification[j - 1];
					scores.array_classification[j - 1] = tmp;
				}
			}
		}
	} 
}

void sort_scores_alfabetically(tScores &scores) {
	tPlayerScorePtr tmp;

	for (int k = 0; k < (scores.num_players); k++) {
		scores.array_classification[k]->name[0] = toupper(scores.array_classification[k]->name[0]);
	}
	for (int i = 0; i < (scores.num_players - 1); i++) {
		for (int j = (scores.num_players - 1); j > 0; j--) {
			if (scores.array_classification[j]->name < scores.array_classification[j - 1]->name) {
				tmp = scores.array_classification[j];
				scores.array_classification[j] = scores.array_classification[j - 1];
				scores.array_classification[j - 1] = tmp;
			}
		}
	}
}