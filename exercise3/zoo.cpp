// Create 5 more classes for different zoo animals that implement the Animal
// interface. A Human class has been created for you, which can be used as a
// model and refresher on syntax.

#include <iostream>

// Import the header files for your classes here.
// Make sure they're alphabetized!
#include "animal.h"
#include "human.h"
#include "construction.h"

void PrintAnimal(const Animal& myAnimal) {
  std::cout << "The " << myAnimal.Name() << " says: " << myAnimal.Greeting()
            << std::endl;
}

int main() {
	Human* human = new Human(24);
	Construction bob;

	PrintAnimal(*human);
	PrintAnimal(bob);

	delete human;

	return 0;
}
