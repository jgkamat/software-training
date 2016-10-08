#include "construction.h"

#include <string>

std::string Construction::Name() const {
  return "Construction Worker";
}

std::string Construction::Greeting() const {
  return "Hey, I'm bob the builder, and I'm "
	  + std::to_string(weight) + " heavy!";
}
