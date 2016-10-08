#include "human.h"

#include <string>

Human::Human(int w) {
	weight = w;
}

Human::Human() {
	weight = 10;
}

std::string Human::Name() const {
  return "Human";
}

std::string Human::Greeting() const {
	return "Hey! I'm " + std::to_string(weight) + " heavy!";
}
