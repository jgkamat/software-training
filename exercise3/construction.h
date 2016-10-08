#ifndef CONSTRUCTION_H
#define CONSTRUCTION_H

#include <string>

#include "human.h"

class Construction : public Human {
 public:
  std::string Name() const override;
  std::string Greeting() const override;
};

#endif // CONSTRUCTION_H
