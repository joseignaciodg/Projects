#include "Score.h"

bool loadScore(tScores &scores, const std::string &SCORESTXT) {
	bool cargado = false;
	std::ifstream file;
	scores.num_players = 0;
	file.open(SCORESTXT);

	if (file.is_open() && (scores.num_players < MAX_PlayersTable)) {
		cargado = true;
		while (file.eof() == false) { //end of file
			file >> scores.Scores[scores.num_players].name;
			file >> scores.Scores[scores.num_players].score;
			scores.num_players++;
		}
		file.close();
	}
	else {
		std::cout << "Couldn not open the file..." << std::endl;
	}
	return cargado;
}

bool updateScore(tScores &scores, const std::string &name, int new_value) {
	bool insert = false;
	bool found = false;
	int i = 0;
	while ((i < scores.num_players) && (!found)) {
		if (scores.Scores[i].name == name) {
			found = true;
			insert = true;
			scores.Scores[i].score = scores.Scores[i].score + new_value;
		}
		else {
			i++;
		}
	}
	if ((found == false) && (scores.num_players < MAX_PlayersTable)) {
		scores.Scores[scores.num_players].name = name;
		scores.Scores[scores.num_players].score = new_value;
		scores.num_players++;
		insert = true;
		
	}
	if (!insert) {
		int min = 0;
		scores.Scores[0].score = min;
		int position = 0;

		for (int i = 0; i < scores.num_players; i++) {
			if (scores.Scores[i].score < min) {
				min = scores.Scores[i].score;
				position = i;
			}
		}
		if (new_value > min) {
			new_value = scores.Scores[position].score;
			scores.Scores[position].name = name;
			insert = true;
		}
	}
	return insert;
}  

void displayScore(const tScores &scores) {
	
	for (int i = 0; i < scores.num_players; i++) {
		std::cout << scores.Scores[i].name;
		std::cout << " ";
		std::cout << scores.Scores[i].score << std::endl;
	}
}

void saveScore(const tScores &scores, const std::string &SCORESTXT) {
	std::ofstream file;
	file.open(SCORESTXT);

	for (int i = 0; i < scores.num_players; i++) {
		file << scores.Scores[i].name << " ";
		file << scores.Scores[i].score << std::endl;
	}
	file.close();
}