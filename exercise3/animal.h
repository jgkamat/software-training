#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
 public:
  // Return the name of the animal.
  //
  // For example, a human class would return "Human".
  virtual std::string Name() const = 0;

  // Return the standard greeting for this animal.
  virtual std::string Greeting() const = 0;
};

#endif // ANIMAL_H
