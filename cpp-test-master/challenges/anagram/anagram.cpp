#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char** argv){
	bool continua = true;
	while (continua){
		int lines = 0;
		cout << "Type lines: ";
		cin >> lines;

		char input1[100];
		char input2[100];
		for (int i = 0; i < lines; i++) {
			cin >> input1 >> input2;
			bool anagrama = true;


			if (strlen(input1) != strlen(input2)){
				anagrama = false;
			}
			else {
				int tmp = 0;
				for (int i = 0; i < strlen(input2); i++){
					bool igual = false;
					char tmp2;
					for (int j = 0; j < strlen(input1); j++){
						if (input1[j] == input2[i]){
							tmp++;
							igual = true;
							tmp2 = input1[j];
						}
						else if (input1[j] != input2[i] && j == strlen(input1) - 1 && igual == false){
							anagrama = false;
							i = strlen(input2);
							j = strlen(input1);
						}
					}
				}



			}

			if (anagrama == true)
				cout << input1 << " and " << input2 << " are anagrams" << endl;
			else
				cout << input1 << " and " << input2 << " are not anagrams" << endl;

		}

		cout << "Continue? (y/n)";
		char yesno;
		cin >> yesno;
		if (yesno == 'n')
			continua = false;
	}
	return 0;
}

