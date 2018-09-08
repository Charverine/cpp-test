#include <iostream>

using namespace std;

int Fibonacci(int x){
	if (x == 0 || x == 1){
		return x;
	}
	else{
		return Fibonacci(x - 1) + Fibonacci(x - 2);
	}
}

int main(int argc, char** argv){
	int fibo;
	bool repetir = true;
	char yesno;
	while (repetir){
		bool pequeno = true;
		while (pequeno){
			cout << "Wich number do you want to know: " << endl;
			cin >> fibo;
			if (fibo >= 0){
				pequeno = false;
			}
		}

		cout << Fibonacci(fibo) << endl;
		cout << "Continue: (y/n)" << endl;
		cin >> yesno;
		if (yesno == 'n')
			repetir = false;
	}
	return 0;
}
