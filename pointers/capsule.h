#pragma once

#include <string>

class Capsule {

private:
  std::string state;

public:
  std::string getData();
  ~Capsule();
  Capsule();
  Capsule(std::string);
};
