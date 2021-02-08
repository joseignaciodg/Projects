#include <iostream>
using namespace std;

typedef enum {spanish, english, french, german, italian, portuguese} tLanguage;

tLanguage readLanguage();
string languageStr(tLanguage lang);

tLanguage readLanguage() {
	tLanguage lang;
	bool ok = false;
	int num;
	while (!ok) {
		cout << "Film genre:" << endl;
		cout << "1 - Spanish" << endl;
		cout << "2 - English" << endl;
		cout << "3 - French" << endl;
		cout << "4 - German" << endl;
		cout << "5 - Italian" << endl;
		cout << "6 - Portuguese" << endl;
		cout << "Language number: ";
		cin >> num;
		if ((num >= 1) && (num <= 6)) {
			ok = true;
		}
	}
	lang = tLanguage(num - 1);
	return lang;
}

string languageStr(tLanguage lang) {
	string str;
	if (lang == spanish) {
		str = "Spanish";
	}
	else if (lang == english) {
		str = "English";
	}
	else if (lang == french) {
		str = "French";
	}
	else if (lang == german) {
		str = "German";
	}
	else if (lang == italian) {
		str = "Italian";
	}
	else {
		str = "Portuguese";
	}
	return str;
}

int main() {
	tLanguage lang;
	lang = readLanguage();
	cout << "Selected language: " << languageStr(lang) << endl;

	return 0;
}



