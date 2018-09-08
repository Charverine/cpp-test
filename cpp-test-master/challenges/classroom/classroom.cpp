#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <vector>

using namespace std;

int main(int argc, char** argv){
	int tarefas;
	int selecao;
	int operacao;
	bool repete = true;
	char alunos[1000][1000];


	while (repete){
		cout << "How many querys: " << endl;
		cin >> tarefas;
		bool inprogress = true;
		int tmpTarefas = tarefas;

		while (inprogress){
			bool teste = true;
			while (teste){
				cout << "Insert or query: " << endl;
				cin >> selecao >> operacao;

				if ((selecao < 1 || selecao > 2) || operacao < 1){
					cout << "Insert a valid value" << endl;
				}
				else {
					teste = false;
				}
			}

			if (selecao == 1){
				bool registro = true;
				int tmpAluno = 0;
				cin.ignore();
				while (registro){
					cout << "Insert student " << tmpAluno + 1 << ": " << operacao << endl;

					cin.getline(alunos[tmpAluno], 1000);
					tmpAluno++;
					if ((tmpAluno + 1) > operacao)
						registro = false;
				}

				for (int i = 0; i < operacao; i++){
					cout << alunos[i] << endl;
				}

				bool organiza = true;
				bool organizou = false;
				int tmpOrganizador = 0;
				int indexLetra1 = 0;
				while (organiza){
					int tmpMaxChar;
					if (strlen(alunos[tmpOrganizador]) > strlen(alunos[tmpOrganizador + 1])){
						tmpMaxChar = strlen(alunos[tmpOrganizador + 1]);
					}
					else {
						tmpMaxChar = strlen(alunos[tmpOrganizador]);
					}

					if (strncmp(alunos[tmpOrganizador], alunos[tmpOrganizador + 1], tmpMaxChar) > 0){
						char superTmp[1000];
						cout << "trocando " << alunos[tmpOrganizador] << " por " << alunos[tmpOrganizador + 1] << endl;
						for (int i = 0; i < 1000; i++){
							superTmp[i] = alunos[tmpOrganizador][i];
						}

						for (int i = 0; i < 1000; i++){
							alunos[tmpOrganizador][i] = alunos[tmpOrganizador + 1][i];
						}

						for (int i = 0; i < 1000; i++){
							alunos[tmpOrganizador + 1][i] = superTmp[i];
						}
						cout << "troquei " << alunos[tmpOrganizador] << " por " << alunos[tmpOrganizador + 1] << endl;
						organizou = true;
					}

					tmpOrganizador++;
					if (tmpOrganizador >= operacao){
						tmpOrganizador = 0;
						if (organizou == false){
							organiza = false;
						}
						else {
							organizou = false;
						}
					}
				}

				for (int i = 0; i < operacao; i++){
					cout << alunos[i] << endl;
				}

			}
			else if (selecao == 2) {
				bool demonstrando = true;
				int demostracao[1000];
				int counterDemo = 0;
				while (demonstrando){
					cin >> demostracao[counterDemo];
					counterDemo++;
					if ((counterDemo) >= operacao){
						demonstrando = false;
					}
				}
				for (int i = 0; i < counterDemo; i++){
					cout << alunos[demostracao[i] - 1] << endl;// " " << sobrenome[demostracao[i]] << endl;
				}
			}

			tmpTarefas--;
			if (tmpTarefas <= 0){
				inprogress = false;
			}
		}

		if (tmpTarefas <= 0){
			cout << "Continue? (y/n)";
			char yesno;
			cin >> yesno;
			if (yesno == 'n')
				repete = false;
		}
	}

	return 0;
}