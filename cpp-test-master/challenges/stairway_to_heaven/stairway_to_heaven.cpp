#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char** argv){
	int size;
	bool repetir = true;
	char yesno;
	while (repetir){
		cout << "How will the size be: " << endl;
		cin >> size;
		cin.ignore();

		char leftRight;
		cout << "Would you like to be on the left or on the right: (l/r)" << endl;
		cin >> leftRight;

		int tmp = 1;
		for (int i = 0; i < size; i++){
			if (leftRight == 'r'){
				for (int t = 0; t < size - tmp; t++){
					cout << " ";
				}
			}
			for (int j = 0; j < tmp; j++){
				cout << "#";
			}
			tmp++;
			cout << endl;
		}

		cout << "Continue: (y/n)" << endl;
		cin >> yesno;
		if (yesno == 'n'){
			repetir = false;
		}
	}

	return 0;
}
