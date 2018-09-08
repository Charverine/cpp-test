#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv){
	bool repetir = true;
	char yesno;
	while (repetir){
		int lines;
		bool pedirLines = true;
		while (pedirLines){
			cout << "How many person: " << endl;
			cin >> lines;
			if (lines > 0)
				pedirLines = false;
		}

		cin.ignore();
		char frases[100][100];
		int tmpLines = 0;
		bool pedirFrases = true;
		while (pedirFrases){
			cout << "Type here: " << endl;
			cin.getline(frases[tmpLines], 100);
			tmpLines++;
			if (tmpLines == lines)
				pedirFrases = false;
		}

		char texto[4][100];
		int separador = 0;
		int tmpPegaTexto = 0;
		int pegaNull[4];

		for (int i = 0; i < lines; i++){
			separador = 0;
			tmpPegaTexto = 0;
			for (int j = 0; j < 100; j++){
				if (frases[i][j] == ','){
					separador++;
					tmpPegaTexto = 0;
				}

				if (separador == 0){
					texto[0][tmpPegaTexto] = frases[i][j];
					pegaNull[0] = tmpPegaTexto;
				}

				if (separador == 1){
					texto[3][tmpPegaTexto] = frases[i][j];
					pegaNull[3] = tmpPegaTexto;
				}

				if (separador == 2){
					texto[2][tmpPegaTexto] = frases[i][j];
					pegaNull[2] = tmpPegaTexto;
				}

				if (separador == 4){
					texto[1][tmpPegaTexto] = frases[i][j];
					pegaNull[1] = tmpPegaTexto;
				}
				tmpPegaTexto++;

				if (frases[i][j] == NULL){
					j = 100;
				}
			}
			string textoFinal[4];
			textoFinal[0] = " is ";
			textoFinal[1] = "years old and lives in ";
			textoFinal[2] = ", ";
			textoFinal[3] = ".";
			for (int k = 0; k < 4; k++){
				for (int j = 0; j < pegaNull[k] + 1; j++){
					if (k == 0)
						cout << texto[k][j];
					else if (k > 0){
						if (j < pegaNull[k])
							cout << texto[k][j + 1];
					}
				}
				cout << textoFinal[k];
			}
			cout << endl;

		}
		////////////////////////////////////////////////////////////////////////////////////////////
		cout << "Continue: (y/n)" << endl;
		cin >> yesno;
		if (yesno == 'n')
			repetir = false;
	}

	return 0;
}