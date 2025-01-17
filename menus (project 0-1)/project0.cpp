#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	bool x = true, noVale = true;
	bool z = true;
	int i, a, number;
	double operand1, operand2, result, quantity, res1, res2, measure, converted1;
	char operatorChar, unit, b, c;
	const double CmPerInch = 2.54;
	const double MetersPerMile = 1609.344;
	const double LitersPerGallon = 4.5461;
	const double GramsPerOunce = 28.349523125;
	const double KgPerPound = 0.45359237;
	const double dollarpound = 0.7546;
	const double eurodollar = 1.18075;
	const double europound = 0.89099;
	string outputUnit1, letter1, letter2, outputUnit2;

	while (z) {
		cout << "Please enter a number between 0-4:" << endl;
		cout << "1 - Calculator" << endl;
		cout << "2 - Multiplication Table" << endl;
		cout << "3 - Measure Converter" << endl;
		cout << "4 - Currency Converter" << endl;
		cout << "0 - Exit" << endl;
		cout << "Your choice: ";
		cin >> a;
		if (a < 0) {
			cout << "Invalid number. Try again!" << endl;
		}
		if (a == 0) {
			z = false;
		}
		if (a == 1) {
			cout << "-----------------------------------------------------------------------" << endl;
			cout << "Operand Operator Operand (0 to end): ";
			cin >> operand1;
			while (operand1 != 0) {
				cin >> operatorChar >> operand2;
				if (operatorChar == '+') {
					result = operand1 + operand2;
				}
				if (operatorChar == '-') {
					result = operand1 - operand2;
				}
				if (operatorChar == '*') {
					result = operand1 * operand2;
				}
				if (operatorChar == '/') {
					result = operand1 / operand2;
				}
				cout << operand1 << " " << operatorChar << " " << operand2 << " = " << result << endl;
				cout << "Operand Operator Operand (0 to end): ";
				cin.sync();
				cin >> operand1;
			}
		}

		else if (a == 2) {
			cout << "-----------------------------------------------------------------------" << endl;
			while (x) {
				while (noVale) {
					cout << "Enter a number (1-100): ";
					cin >> number;
					if (number >= 1) {
						if (number <= 100) {
							noVale = false;
						}
					}
					else if (number == 0) {
						noVale = false;
					}
				}
				noVale = true;

				if (number != 0) {
					for (a = 1; a <= 10; a++) {
						cout << setw(3) << a << "  x  " << setw(4) << number << "  =  " << setw(5) << a * number << endl;
					}
					cout << endl;
					noVale = true;
				}
				else if (number == 0) {
					x = false;
				}
			}
			x = true;
		}

		else if (a == 3) {
			cout << "-----------------------------------------------------------------------" << endl;
			cout << "Units allowed: inches (i), miles (m), Fahrenheit degrees(f), gallons (g), ounces (o) and pounds (p)." << endl;
			cout << "Enter a measure (quantity followed by a unit letter; 0 to end): ";
			cin >> measure;

			while (measure != 0) {
				cin >> unit;
				if (unit == 'i') {
					converted1 = measure * CmPerInch;
					outputUnit1 = "cm";
				}
				if (unit == 'm') {
					converted1 = measure * MetersPerMile;
					outputUnit1 = "m";
				}
				if (unit == 'f') {
					converted1 = (measure - 32) * 5 / 9;
					outputUnit1 = "C";
				}
				if (unit == 'g') {
					converted1 = measure * LitersPerGallon;
					outputUnit1 = "l";
				}
				if (unit == 'o') {
					converted1 = measure * GramsPerOunce;
					outputUnit1 = "gr";
				}
				if (unit == 'p') {
					converted1 = measure * KgPerPound;
					outputUnit1 = "kg";
				}
				cout << "Equivalent to " << converted1 << " " << outputUnit1 << endl;
				cout << "Enter a measure (quantity followed by a unit letter; 0 to end): ";
				cin >> measure;
			}
		}

		else if (a == 4) {
			cout << "-----------------------------------------------------------------------" << endl;
			cout << "Currency allowed: Dollar (D), Euro (E) and Pound Sterling (P)." << endl;
			cout << "Enter a quantity (0 to end) followed by original currency letter and target currency letter: ";
			cin >> quantity;

			while (quantity != 0) {
				cin >> b;
				if (b == 'D') {
					cin >> c;
					if (c == 'E') {
						res1 = quantity / eurodollar;
						letter1 = "E";
						cout << quantity << " " << b << " is equivalent to " << res1 << " " << letter1 << endl;
					}
					else if (c == 'P') {
						res2 = quantity * dollarpound;
						letter2 = "P";
						cout << quantity << " " << b << " is equivalent to " << res2 << " " << letter2 << endl;
					}
				}
				else if (b == 'E') {
					cin >> c;
					if (c == 'D') {
						res1 = quantity * eurodollar;
						letter1 = "D";
						cout << quantity << " " << b << " is equivalent to " << res1 << " " << letter1 << endl;
					}
					else if (c == 'P') {
						res2 = quantity * europound;
						letter2 = "P";
						cout << quantity << " " << b << " is equivalent to " << res2 << " " << letter2 << endl;
					}
				}
				else if (b == 'P') {
					cin >> c;
					if (c == 'E') {
						res1 = quantity / europound;
						letter1 = "E";
						cout << quantity << " " << b << " is equivalent to " << res1 << " " << letter1 << endl;
					}
					else if (c == 'D') {
						res2 = quantity / dollarpound;
						letter2 = "D";
						cout << quantity << " " << b << " is equivalent to " << res2 << " " << letter2 << endl;
					}
				}
				cout << "Enter a quantity(0 to end) followed by original currency letter and target currency letter : ";
				cin >> quantity;
			}
		}
		if (a > 4) {
			cout << "Invalid option. Try again!" << endl;
		}
	}
	return 0;
}