#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>
#include <string>
using namespace std;



class Animal {

private: 
//protected: //only accissible insed class
	string name;
	double height;
	double weight;
	
	static int numOfAnimals; //static changes with everything

public:
	string GetName() {return name;}

	void SetName(string name) { this->name = name; }

	double GetHeight() { return height; }
	void SetHeight(double height) { this->height = height; }

	double GetWeight() { return weight; }
	void SetWeight(double weight) { this->weight = weight; }

	void SetAll(string, double, double);

	Animal(string, double, double); //constructor

	Animal(); //overload in case no attributes

	~Animal(); //deconstructor

	static int GetNumOfAnimals() { return numOfAnimals; }

	void toString(); 

};

int Animal::numOfAnimals = 0;
void Animal::SetAll(string name, double height, double weight) {
	this->name = name;
	this->weight = weight;
	this->height = height;
	Animal::numOfAnimals++;
}
	
Animal::Animal(string name, double height, double weight) {
	this->name = name;
	this->weight = weight;
	this->height = height;
	Animal::numOfAnimals++;
}

Animal::Animal() {
	this->name = "";
	this->weight = 0;
	this->height = 0;
	Animal::numOfAnimals++;
}

Animal::~Animal() {
	cout << " Animal " << this->name << " Removed ";
}

void Animal::toString() {
	cout << this->name << "is " << this->height << "cm tall " << this->weight << "kgs in weight\n";
}

class Dog : public Animal {
private:
	string sound = "Woof";
public:
	void MakeSound() {
		cout << "The dog " << this->GetName() << " says " << this->sound << "\n";
	}
	Dog(string, double, double, string);
	Dog() : Animal() {}; // 0 0 0
	void toString();
};

Dog::Dog(string name, double height, double weight, string sound) :Animal(name, height, weight) {


	this->sound = sound;
}

void Dog::toString() {

	cout << this-> GetName() << "is " << this->GetHeight() << "cm tall " << this->GetWeight() << "kgs in weight "
		"and makes the sound "<< this->sound << "\n";
}

int main() 
{
	Animal fred;
	fred.SetHeight(33);
	fred.SetWeight(100);
	fred.SetName("fred");
	fred.toString();

	Animal Jerry("Jerry", 36, 15);
	Jerry.toString();

	Dog Clifford("Clifford ", 38, 16, " Woof ");
	Clifford.toString();

	cout << "Number of animals" << Animal::GetNumOfAnimals() << endl;

	return 0;
}
