// Proyect 1 v.1 -> MADE BY JOSE IGNACIO DAGUERRE
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef enum { Rock, Paper, Scissors, Lizard, Spock } tElement;
typedef enum { tie, aiWins, playerWins } tResult;

int main() {
	int num, num2, AI, c = 0, d = 0, e = 0;
	tElement element;
	string a, b;
	srand(time(NULL));
	bool i = true, ok = true, j = true;
	while (i) {
		cout << "Choose an option:" << endl;
		cout << "1- Play a match" << endl;
		cout << "2- Help" << endl;
		cout << "0- Exit" << endl;
		cout << "Your choice: ";
		cin >> num;
		cout << endl;
		if (num == 1) {
			while (j) {
				ok = true;
				while (ok) {
					cout << "Please choose an element:" << endl;
					cout << "1 - Rock" << endl;
					cout << "2 - Paper" << endl;
					cout << "3 - Scissors" << endl;
					cout << "4 - Lizard" << endl;
					cout << "5 - Spock" << endl;
					cout << "Choice number: ";
					cin >> num2;
					if ((num2 >= 1) && (num2 <= 5)) {
						ok = false;
					}
					else {
						cout << endl;
						cout << "Invalid element! Try again..." << endl << endl;
					}
				}
				AI = rand() % 5 + 1;
				if (AI == 0) {
					b = "Rock";
				}
				if (AI == 1) {
					b = "Paper";
				}
				if (AI == 2) {
					b = "Scissors";
				}
				if (AI == 3) {
					b = "Lizard";
				}
				if (AI == 4) {
					b = "Spock";
				}
				element = tElement(num2 - 1);
				if (element == 0) {
					a = "Rock";
					if (b == "Rock") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "Tied" << endl;
						cout << endl;
						e++;
					}
					else if (b == "Paper") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "You lost" << endl;
						cout << endl;
						d++;
					}
					else if (b == "Scissors") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "You win!" << endl;
						cout << endl;
						c++;
					}
					else if (b == "Lizard") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "You win!" << endl;
						cout << endl;
						c++;
					}
					else if (b == "Spock") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "You lost" << endl;
						cout << endl;
						d++;
					}
				}
				if (element == 1) {
					a = "Paper";
					if (b == "Paper") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "Tied" << endl;
						cout << endl;
						e++;
					}
					else if (b == "Scissors") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "You lost" << endl;
						cout << endl;
						d++;
					}
					else if (b == "Rock") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "You win!" << endl;
						cout << endl;
						c++;
					}
					else if (b == "Spock") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "You win!" << endl;
						cout << endl;
						c++;
					}
					else if (b == "Lizard") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "You lost" << endl;
						cout << endl;
						d++;
					}
				}
				if (element == 2) {
					a = "Scissors";
					if (b == "Scissors") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "Tied" << endl;
						cout << endl;
						e++;
					}
					else if (b == "Rock") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "You lost" << endl;
						cout << endl;
						d++;
					}
					else if (b == "Paper") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "You win!" << endl;
						cout << endl;
						c++;
					}
					else if (b == "Lizard") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "You win!" << endl;
						cout << endl;
						c++;
					}
					else if (b == "Spock") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "You lost" << endl;
						cout << endl;
						d++;
					}
				}
				if (element == 3) {
					a = "Lizard";
					if (b == "Lizard") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "Tied" << endl;
						cout << endl;
						e++;
					}
					else if (b == "Rock") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "You lost" << endl;
						cout << endl;
						d++;
					}
					else if (b == "Paper") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "You win!" << endl;
						cout << endl;
						c++;
					}
					else if (b == "Spock") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "You win!" << endl;
						cout << endl;
						c++;
					}
					else if (b == "Scissors") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "You lost" << endl;
						cout << endl;
						d++;
					}
				}
				if (element == 4) {
					a = "Spock";
					if (b == "Spock") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "Tied" << endl;
						cout << endl;
						e++;
					}
					else if (b == "Paper") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "You lost" << endl;
						cout << endl;
						d++;
					}
					else if (b == "Scissors") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "You win!" << endl;
						cout << endl;
						c++;
					}
					else if (b == "Rock") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "You win!" << endl;
						cout << endl;
						c++;
					}
					else if (b == "Lizard") {
						cout << endl;
						cout << "Computer: " << b << endl;
						cout << "Your choice: " << a << endl;
						cout << "................." << endl;
						cout << "You lost" << endl;
						cout << endl;
						d++;
					}
				}
				j = false;
			}
		}
		if (num == 2) {
			cout << "The game is played between two players: the computer and the user." << endl;
			cout << "In each match, the computer first chooses an element and then asks the user to also choose an element." << endl;
			cout << "If both elements are the same, then the result is a tie. " << endl;
			cout << "In other cases, the following rules apply:" << endl;
			cout << "   - Scissors cuts paper" << endl;
			cout << "   - Paper covers rock" << endl;
			cout << "   - Rock crushes lizard" << endl;
			cout << "   - Lizard poisons Spock" << endl;
			cout << "   - Spock smashes scissors" << endl;
			cout << "   - Scissors decapitates lizard" << endl;
			cout << "   - Lizard eats paper" << endl;
			cout << "   - Paper disproves Spock" << endl;
			cout << "   - Spock vaporizes rock" << endl;
			cout << "   - Rock crushes scissors" << endl << endl;
		}
		if (num == 0) {
			i = false;
		}
		if ((num < 1) || (num > 2)) {
			cout << "Invalid Option! Try again." << endl;
			cout << endl;
		}
	}
	cout << endl;
	cout << "Matches: " << c + d + e << endl;
	cout << "Won matches: " << c << endl;
	cout << "Ties: " << e << endl;
	cout << "Lost matches: " << d << endl;
	cout << endl;

	system("pause");
	return 0;
}


