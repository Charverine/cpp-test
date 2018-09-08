#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv){
	int inputN;
	cout << "How many input: " << endl;
	cin >> inputN;

	int billsN[100];
	bool billsB[100];
	char billsD[5];
	int counterBills = 0;
	bool recebendoInput = true;
	while (recebendoInput){
		cout << "How many bills: " << endl;
		cin >> billsN[counterBills];
		bool verifying = true;
		while (verifying){
			cout << "What is it state: " << endl;
			cin >> billsD;
			if ((billsD[0] == 'd' || billsD[0] == 'D') && (billsD[1] == 'i' || billsD[1] == 'i') &&
				(billsD[2] == 'r' || billsD[2] == 'R') && (billsD[3] == 't' || billsD[3] == 'T') && (billsD[4] == 'y' || billsD[4] == 'Y')){
				verifying = false;
				billsB[counterBills] = true;
			}
			else if ((billsD[0] == 'c' || billsD[0] == 'C') && (billsD[1] == 'l' || billsD[1] == 'L') &&
				(billsD[2] == 'e' || billsD[2] == 'E') && (billsD[3] == 'a' || billsD[3] == 'A') && (billsD[4] == 'n' || billsD[4] == 'N')){
				verifying = false;
				billsB[counterBills] = false;
			}
		}
		counterBills++;
		inputN--;
		if (inputN <= 0){
			recebendoInput = false;
		}
	}

	int soma = 0;
	for (int i = 0; i < 100; i++){
		if (billsB[i] == true){
			soma += billsN[i];
		}
	}

	cout << "There are " << soma << " dirty bills." << endl;

	return 0;
}
