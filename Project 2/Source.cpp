#include <iostream>
#include <string>
#include <ctime>

using namespace std;

const int CODE_SIZE = 4; // sets the current code length

typedef enum { RED, BLUE, GREEN, YELLOW, PINK, WHITE, WRONG } tColor;
typedef tColor tCode[CODE_SIZE];
typedef bool tComparecodes[CODE_SIZE];

void humanChoice(tCode code);
int menu();
void randomCode(tCode code, bool acceptsRepeated);
void compareCodes(const tCode code, const tCode hypothesis, int& wellPlaced, int& misPlaced);
char color2char(tColor color);
tColor char2color(char chr);

int main() {
	bool ok = true;
	char AIcode;
	tCode code;
	int wellPlaced = 0, misPlaced = 0;
	bool acceptsRepeated = true;
	srand(time(NULL));
	int choice;
	tColor color;

	cout << "                                  Mastermind  " << endl;
	cout << "                                  ==========  " << endl;
	cout << "Guess the secret code! I will think of a secret color code that you will have to " << endl;
	cout << "guess.For each try I will give you hints, telling you how many colors are correctly " << endl;
	cout << "placed, and how many are misplaced. " << endl;
	cout << "Guess the code with as few tries as possible! " << endl;

	while (ok) {
		choice = menu();

		if (choice == 1) { // without repetition
			acceptsRepeated = false;
			randomCode(code, acceptsRepeated);
			cout << "[INFO debugging] Secret code: ";
			
			for (int i = 0; i < CODE_SIZE; i++) {
				AIcode = color2char(code[i]);
				cout << AIcode;
			}
			cout << "" << endl;
			humanChoice(code);
		}

		else if (choice == 2) { // with repetition
			acceptsRepeated = true;
			randomCode(code, acceptsRepeated);
			cout << "[INFO debugging] Secret code: ";

			for (int i = 0; i < CODE_SIZE; i++) {
				color = code[i];
				AIcode = color2char(color);
				cout << AIcode;
			}
			cout << "" << endl;
			humanChoice(code);
		}
		else if (choice == 0) {
			ok = false;
		}
	}
	return 0;
}

void humanChoice(tCode code) {
	bool ok = true;
	bool correct = true;
	bool ok2 = true;
	char displayinput;
	string guess;
	string compare;
	tCode hypothesis;
	int wellPlaced = 0, misPlaced = 0, numberoftries = 0;
	tColor  colour;
	int k = 0;

	while ((numberoftries < 15) && ok) {  // user has 15 tries (0 up to 14) to guess the code including the try number 15
		ok2 = true;

		while (ok2) {
			cout << "Input hypothesis (4 letters Word with R, B, G, Y, P or W): ";
			cin >> guess;

			while (k < CODE_SIZE && correct) {   //turns every character of the string to uppercase
				guess[k] = toupper(guess[k]);
				hypothesis[k] = char2color(guess[k]);

				if (hypothesis[k] == WRONG) {
					correct = false;  //checks if the input is valid
				}

				else {
					correct = true; // goes to the comparison of the hypothesis and code
				}
				k++;
			}
			k = 0;

			if (guess.size() > CODE_SIZE) {
				cout << "Too many colors! Try again..." << endl;
			}

			else if (!correct) {
				cout << "Invalid color! Try again..." << endl;
				correct = true;
			}
			else {
				ok2 = false;
			}
		}

		for (int h = 0; h < CODE_SIZE; h++) {
			colour = char2color(guess[h]);
			hypothesis[h] = colour;
		}
		for (int j = 0; j < CODE_SIZE; j++) {
			displayinput = color2char(hypothesis[j]);
			cout << displayinput;
		}
		numberoftries++;
		compareCodes(code, hypothesis, wellPlaced, misPlaced);
		cout << " Correctly placed: " << wellPlaced << "; " << "misplaced: " << misPlaced << endl;

		if (wellPlaced == CODE_SIZE) { // CODE_SIZE = 4
			cout << "Congrats! You found it!" << endl;
			cout << "That took " << numberoftries << " tries" << endl;
			cout << "..." << endl;
			ok = false;
		}
	}

	if (numberoftries >= 14) {
		cout << endl;
		cout << "You lost, you took " << numberoftries << " tries!" << endl;
	}
}

int menu() {
	int num;
	cout << endl;
	cout << "1- Play without repeated codes" << endl;
	cout << "2- Play with repeated codes" << endl;
	cout << "0- Exit" << endl;
	cout << "Please choose an option: ";
	cin >> num;
	cout << endl;

	if ((num < 0) || (num > 2)) {
		cout << "Invalid option! Please try again... " << endl; 
	}
	return num;
}

void randomCode(tCode code, bool acceptsRepeated) {

	if (acceptsRepeated) {

		for (int i = 0; i < CODE_SIZE; i++) {
			code[i] = tColor(rand() % 6);
		}
	}

	else {
		code[0] = tColor(rand() % 6);
		code[1] = tColor(rand() % 6);

		while (code[1] == code[0]) {
			code[1] = tColor(rand() % 6);
		}
		code[2] = tColor(rand() % 6);

		while (code[2] == code[1] || code[2] == code[0]) {
			code[2] = tColor(rand() % 6);
		}
		code[3] = tColor(rand() % 6);

		while (code[3] == code[2] || code[3] == code[1] || code[3] == code[0]) {
			code[3] = tColor(rand() % 6);
		}
	}
}

void compareCodes(const tCode code, const tCode hypothesis, int &wellPlaced, int &misPlaced) {
	tComparecodes boolcode, boolhypotesis;
	wellPlaced = 0;
	misPlaced = 0;

	for (int i = 0; i < CODE_SIZE; i++) {
		boolcode[i] = false;
		boolhypotesis[i] = false;
	}

	for (int j = 0; j < CODE_SIZE; j++) {

		if (code[j] == hypothesis[j]) {
			wellPlaced++;
			boolcode[j] = true;
			boolhypotesis[j] = true;
		}
	}

	for (int k = 0; k < CODE_SIZE; k++) {

		if (!boolcode[k]) {

			for (int h = 0; h < CODE_SIZE; h++) {

				if ((boolhypotesis[h] == false) && (code[k] == hypothesis[h]) && (boolcode[k] == false)) {
					boolcode[k] = true;
					boolhypotesis[h] = true;
					misPlaced++;
				}
			}
		}
	}
}

char color2char(tColor color) {
	char chr;

	if (color == RED) {
		chr = 'R';
	}

	else if (color == BLUE) {
		chr = 'B';
	}

	else if (color == GREEN) {
		chr = 'G';
	}

	else if (color == YELLOW) {
		chr = 'Y';
	}

	else if (color == PINK) {
		chr = 'P';
	}

	else if (color == WHITE) {
		chr = 'W';
	}
	return chr;
}

tColor char2color(char chr) {
	tColor color;

	if (chr == 'R') {
		color = RED;
	}

	else if (chr == 'B') {
		color = BLUE;
	}

	else if (chr == 'G') {
		color = GREEN;
	}

	else if (chr == 'Y') {
		color = YELLOW;
	}

	else if (chr == 'P') {
		color = PINK;
	}

	else if (chr == 'W') {
		color = WHITE;
	}

	else {
		color = WRONG;
	}
	return color;
}