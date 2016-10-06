#ifndef HUMAN_H
#define HUMAN_H

#include <string>

#include "animal.h"

class Human : public Animal {
 public:
  std::string Name() const override;

  std::string Greeting() const override;
};

#endif // HUMAN_H
