#pragma once

#include <string>

class Capsule {

private:
  std::string state;

public:
  std::string getData() const;
  ~Capsule();
  Capsule();
  Capsule(std::string);
};
