// Proyect 1 v.2 -> MADE BY JOSE IGNACIO DAGUERRE
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

typedef enum { rock, paper, scissors, lizard, spock } tElement;
typedef enum { tie, aiWins, playerWins } tResult;

bool locatePlayer(string nickname);
int menu();
bool displayHelp();
tElement humanChoice();
string elementToString(tElement element);
tResult findResult(tElement computer, tElement player);

int main() {
	srand(time(NULL));
	tElement player, computer;
	tResult result;
	string nickname, a, b;
	int choice, AI, win = 0, tied = 0, lost = 0;
	bool ok = true;
	
	cout << "Please enter your nickname: ";
	cin >> nickname;
	cout << endl;

	if (locatePlayer(nickname)) {
		while (ok) {
			choice = menu();
			if (choice == 1) {
				player = humanChoice();
				a = elementToString(player);
				AI = rand() % 5;
				if (AI == 0) {
					b = "Rock";
				}
				else if (AI == 1) {
					b = "Paper";
				}
				else if (AI == 2) {
					b = "Scissors";
				}
				else if (AI == 3) {
					b = "Lizard";
				}
				else if (AI == 4) {
					b = "Spock";
				}
				computer = tElement(AI);
				b = elementToString(computer);
				if (player == tResult(-1)) {
					ok = false;
				}
				else {
					cout << "Computer: " << b << endl;
					cout << "Your choice: " << a << endl;
					cout << "................." << endl;
					result = findResult(computer, player);
					if (result == tie) {
						cout << "Tied" << endl;
						cout << endl;
						tied++;
					}
					else if (result == playerWins) {
						cout << "You win!" << endl;
						cout << endl;
						win++;
					}
					else if (result == aiWins) {
						cout << "You lost" << endl;
						cout << endl;
						lost++;
					}
				}
			}
			else if (choice == 2) {
				displayHelp();
				cout << endl;
			}
			else if (choice == 0) {
				cout << "Matches: " << win + tied + lost << endl;
				cout << "Won matches: " << win << endl;
				cout << "Ties: " << tied << endl;
				cout << "Lost matches: " << lost << endl;
				cout << endl;
				ok = false;
			}
		}
	}
	else {
		cout << "Sorry, player not registered or file not found. Impossible to play!" << endl << endl;
	}
	system("pause");
	return 0;
}

bool locatePlayer(string nickname) {
	string username;

	ifstream file;
	file.open("register.txt");
	if (file.is_open()) {
		getline(file, username);
		while (username != "XXX") {
			if (username == nickname) {
				return true;
			}
			else {
				getline(file, username);
			}
		}
	}
	else {
		cout << "Couldn't find the file" << endl;
	}
	file.close();
	return false;
}

int menu() {
	int num;
	cout << "Choose an option:" << endl;
	cout << "1- Play a match" << endl;
	cout << "2- Help" << endl;
	cout << "0- Exit" << endl;
	cout << "Your choice: ";
	cin >> num;
	cout << endl;

	if ((num < 0) || (num > 2)) {
		cout << "Invalid Option! Try again." << endl;
		cout << endl;
	}
	return num;
}

bool displayHelp() {
	string ans;

	ifstream fileinput2;
	fileinput2.open("rules.txt");
	getline(fileinput2, ans);

	while (ans != "XXX") {
		cout << ans << endl;
		getline(fileinput2, ans);
	}
	fileinput2.close();
	return false;
}

tElement humanChoice() {
	int num2;
	bool ok = true;

	while (ok) {
		cout << "Please choose an element:" << endl;
		cout << "1 - Rock" << endl;
		cout << "2 - Paper" << endl;
		cout << "3 - Scissors" << endl;
		cout << "4 - Lizard" << endl;
		cout << "5 - Spock" << endl;
		cout << "Choice number: ";
		cin >> num2;
		cout << endl;
		if ((num2 >= 1) && (num2 <= 5)) {
			ok = false;
		}
		else {
			cout << "Invalid element! Try again..." << endl << endl;
		}
	}
	return tElement(num2 - 1);
}

string elementToString(tElement element) {
	string str;

	if (element == rock) {
		str = "Rock";
	}
	else if (element == paper) {
		str = "Paper";
	}
	else if (element == scissors) {
		str = "Scissors";
	}
	else if (element == lizard) {
		str = "Lizard";
	}
	else {
		str = "Spock";
	}
	return str;
}

tResult findResult(tElement computer, tElement player) {
	tResult result;
	if (player == 0) {
		if (computer == rock) {
			result = tResult(tie);
		}
		else if (computer == paper) {
			result = tResult(aiWins);
		}
		else if (computer == scissors) {
			result = tResult(playerWins);
		}
		else if (computer == lizard) {
			result = tResult(playerWins);
		}
		else if (computer == spock) {
			result = tResult(aiWins);
		}
	}
	if (player == 1) {
		if (computer == paper) {
			result = tResult(tie);
		}
		else if (computer == scissors) {
			result = tResult(aiWins);
		}
		else if (computer == rock) {
			result = tResult(playerWins);
		}
		else if (computer == spock) {
			result = tResult(playerWins);
		}
		else if (computer == lizard) {
			result = tResult(aiWins);
		}
	}
	if (player == 2) {
		if (computer == scissors) {
			result = tResult(tie);
		}
		else if (computer == rock) {
			result = tResult(aiWins);
		}
		else if (computer == paper) {
			result = tResult(playerWins);
		}
		else if (computer == lizard) {
			result = tResult(playerWins);
		}
		else if (computer == spock) {
			result = tResult(aiWins);
		}
	}
	if (player == 3) {
		if (computer == lizard) {
			result = tResult(tie);
		}
		else if (computer == rock) {
			result = tResult(aiWins);
		}
		else if (computer == paper) {
			result = tResult(playerWins);
		}
		else if (computer == spock) {
			result = tResult(playerWins);
		}
		else if (computer == scissors) {
			result = tResult(aiWins);
		}
	}
	if (player == 4) {
		if (computer == spock) {
			result = tResult(tie);
		}
		else if (computer == paper) {
			result = tResult(aiWins);;
		}
		else if (computer == scissors) {
			result = tResult(playerWins);
		}
		else if (computer == rock) {
			result = tResult(playerWins);
		}
		else if (computer == lizard) {
			result = tResult(aiWins);
		}
	}
	return result;
}

