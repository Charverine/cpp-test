#include <iostream>
#include <string>

using namespace std;

class Animal{
private:
	string vozes[10];
	string animais[10];
	string box;
public:
	/// This is the function which will be called to reproduce the sound each
	/// animal makes.
	virtual void makeSound(){
		bool sonzao = true;
		int i = 0;
		while (sonzao){
			if (box == animais[i]){
				sonzao = false;
				std::cout << vozes[i] << endl;
			}
			else{
				i++;
			}
		}
	}

	/// This is our factory. You need to code the missing implementation.
	//Animal* create(const std::string& name);
	Animal(const std::string& name);

	/// This function will terminate the class instance.
	static void destroy(Animal* animal){
		delete animal;
	}
};

// Write your classes here
// This is the function you need to change in order to instantiate the required
// classes.
Animal::Animal(const std::string& name){
	vozes[0] = "woof";
	vozes[1] = "meow";
	vozes[2] = "tweet";
	vozes[3] = "squeek";
	vozes[4] = "moo";
	vozes[5] = "croak";
	vozes[6] = "toot";
	vozes[7] = "quack";
	vozes[8] = "blub";
	vozes[9] = "ow ow ow";
	animais[0] = "dog";
	animais[1] = "cat";
	animais[2] = "bird";
	animais[3] = "mouse";
	animais[4] = "cow";
	animais[5] = "frog";
	animais[6] = "elephant";
	animais[7] = "duck";
	animais[8] = "fish";
	animais[9] = "seal";
	box = name;
	//return 0;
}

void makeSound(const std::string& name){
	// Create our instance
	//Animal* animal = Animal::create(name);
	Animal* animal = new Animal(name);

	animal->makeSound();

	// Destroy our instance
	Animal::destroy(animal);
}

int main(int argc, char** argv){
	int n = 0;
	std::cin >> n;

	while (n--){
		std::string animal;

		std::cin.ignore();
		std::cin >> animal;

		makeSound(animal);
	}

	return 0;
}
