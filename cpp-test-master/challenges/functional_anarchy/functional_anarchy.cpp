#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

int main(int argc, char** argv){
	int lines;
	bool repetir = true;
	char yesno;

	while (repetir){
		bool pedirLinhas = true;
		while (pedirLinhas){
			cout << "How many lines: " << endl;
			cin >> lines;
			if (lines >= 0){
				pedirLinhas = false;
			}
		}

		bool pedirnumeros = true;
		int counter = 0;
		int anarchy[10000];
		while (pedirnumeros){
			cout << "Number " << counter + 1 << ": " << endl;
			cin >> anarchy[counter];
			lines--;
			counter++;
			if (lines <= 0){
				pedirnumeros = false;
				cout << "counter: " << counter << endl;
			}
		}

		bool anarquizando = true;
		bool anarquizado = false;
		while (anarquizando){
			if (anarchy[lines] > anarchy[lines + 1]){
				int tmp = anarchy[lines];
				anarchy[lines] = anarchy[lines + 1];
				anarchy[lines + 1] = tmp;
				anarquizado = true;
			}
			lines++;
			if (lines == counter - 1){
				lines = 0;
				if (anarquizado == false){
					anarquizando = false;
				}
				else {
					anarquizado = false;
				}
			}
		}

		for (int i = 0; i < counter; i++){
			cout << anarchy[i] << endl;
		}

		cout << "Continue: (y/n)" << endl;
		cin >> yesno;
		if (yesno == 'n')
			repetir = false;
	}
	return 0;
}
