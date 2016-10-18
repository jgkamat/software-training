#include "capsule.h"
#include <iostream>
#include <memory>

using namespace std;

/* CheatSheet
   | item     | def                              |
   |----------+----------------------------------|
   | int*     | int pointer                      |
   | int&     | int References                   |
   | &a       | address of variable a            |
   | *a       | dereference pointer a            |
   | new a()  | create object a in Heap          |
   | delete a | free a pointer, created with new |
*/

// Classic c swapping function
int swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

// C++ swapping function
int swap2(int& a, int& b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int main() {

  cout << "Swapping test:" << endl;
  int a = 1;
  int b = 2;
  cout << "a: " << a << " b: " << b << endl;
  swap(&a, &b);
  cout << "a: " << a << " b: " << b << endl;
  swap2(a, b);
  cout << "a: " << a << " b: " << b << endl;

  // On the stack
  cout << endl << "Stack:" << endl;
  Capsule c("Stack");

  // Pointers!
  cout << endl << "Heap:" << endl;
  Capsule* capsulePtr = new Capsule("Heap - Ptr");
  // If we have no space, an exception is thrown
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


  cout << endl << "Smart Pointers:" << endl;
  // Unique Pointers
  std::unique_ptr<Capsule> p1(new Capsule("Heap - UniquePtr"));
  // p1.get() gives us a good ol' fashioned pointer. Don't pass it around!
  cout << "My capsule pointer points to: " << p1.get() << endl;
  cout << "Following it gives us: " << p1->getData() << endl;
  // Our Unique Pointer will autodelete this when we reach end of scope, at the bottom


  // BONUS:
  // How do we use the heap in c?
  printf("\nC bonus!\n");
  int* cptr = (int*) malloc(sizeof(int));
  if (!cptr) {
    printf("We could not allocate memory!\n");
    return 1;
  }
  *cptr = 5;
  printf("%d\n", *cptr);
  free(cptr);

  cout << endl << "Ending Main" << endl;
}
