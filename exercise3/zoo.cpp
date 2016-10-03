// Create 5 more classes for different zoo animals that implement the Animal
// interface. A Human class has been created for you, which can be used as a
// model and refresher on syntax.

#include <iostream>

// Import the header files for your classes here.
// Make sure they're alphabetized!
#include "animal.h"
#include "human.h"

void PrintAnimal(const Animal& animal) {
  std::cout << "The " << animal.Name() << " says: " << animal.Greeting()
            << std::endl;
}

int main() {
  Human human;

  PrintAnimal(human);

  return 0;
}
