#include "capsule.h"
#include <iostream>
#include <memory>

using namespace std;

int main() {
  // On the stack
  cout << "Stack:" << endl;
  Capsule c("Stack");

  // Pointers!
  cout << endl << "Heap:" << endl;
  Capsule* capsulePtr = new Capsule("Heap - Ptr");
  cout << "My capsule pointer points to: " << capsulePtr << endl;
  cout << "Following it gives us: " << (*capsulePtr).getData() << endl;
  // Shortform
  cout << "Following it gives us: " << capsulePtr->getData() << endl;

  // Unless we free, we have a memory leak!
  delete capsulePtr;

  // References
  cout << endl << "Heap:" << endl;
  Capsule* cPtr = new Capsule("Heap - Ref");
  Capsule& cRef = *cPtr;
  cout << "My capsule pointer points to: " << &cRef << endl;
  cout << "Following it gives us: " << cRef.getData() << endl;

  // Clean up after ourselves
  delete &cRef; // or delete cPtr


  // Unique Pointers
  std::unique_ptr<Capsule> p1(new Capsule("Heap - UniquePtr"));
  // p1.get() gives us a good ol' fashioned pointer. Don't pass it around!
  cout << "My capsule pointer points to: " << p1.get() << endl;
  cout << "Following it gives us: " << p1->getData() << endl;
  // Our Unique Pointer will autodelete this when we reach end of scope, at the bottom

  cout << endl << "Ending Main" << endl;
}
