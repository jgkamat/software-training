
#include "capsule.h"
#include <iostream>
using namespace std;

Capsule::Capsule() {
  state = "Unnamed Capsule";
  cout << "Creating my " << state << " Capsule" << endl;
}

Capsule::Capsule(std::string a) {
  state = a;
  cout << "Creating my " << state << " Capsule" << endl;
}

Capsule::~Capsule() {
  cout << "Destroying my " << state << " Capsule" << endl;
}

string Capsule::getData() {
  return state;
}
