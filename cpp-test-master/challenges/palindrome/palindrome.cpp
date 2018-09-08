#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv){
	int lines;
	char yesno;
	bool repetir = true;
	while (repetir){
		bool pedirLines = true;
		while (pedirLines){
			cout << "How many words would you wish to test: " << endl;
			cin >> lines;
			if (lines > 0)
				pedirLines = false;
		}

		char palindrom[100][100];
		bool pedirPalindromo = true;
		int tmpLines = 0;
		cin.ignore();
		while (pedirPalindromo){
			cout << "Word " << tmpLines + 1 << ": " << endl;
			cin >> palindrom[tmpLines];

			tmpLines++;
			if (tmpLines == lines)
				pedirPalindromo = false;
		}

		bool testando = true;
		int tmpTeste = 0;
		bool palidromal[100];
		for (int i = 0; i < 100; i++)
			palidromal[i] = true;
		while (testando){
			int tmpI;
			for (int i = 0; i < 100; i++){
				if (palindrom[tmpTeste][i] == NULL){
					tmpI = i - 1;
				}
			}
			for (int i = 0; i < tmpI; i++){
				if (palindrom[tmpTeste][i] != palindrom[tmpTeste][tmpI - i]){
					palidromal[tmpTeste] = false;
				}
			}

			tmpTeste++;

			if (tmpTeste == lines){
				testando = false;
			}
		}

		for (int i = 0; i < lines; i++){
			if (palidromal[i] == true){
				cout << palindrom[i] << " is a palindrome" << endl;
			}
			else{
				cout << palindrom[i] << " is not a palindrome" << endl;
			}
		}

		cout << "Continue: (y/n)" << endl;
		cin >> yesno;
		if (yesno == 'n'){
			repetir = false;
		}
	}
	return 0;
}
