#include <iostream>
using namespace std;
int main() {
	typedef enum {noPresentado, suspenso, aprobado, notable, sobresaliente, matriculaDeHonor} tGrade;

	tGrade mygrade;
	myGrade = sobresaliente;
	cout << myGrade;

	if (myGrade == 0) {
		cout << "NP";
	}
	else if (myGrade == 1) {
		cout << "SS";
	}

	tGrade myDesiredGrade;
	myGrade = sobresaliente;

	return 0;
}