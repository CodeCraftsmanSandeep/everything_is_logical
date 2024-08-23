#include <iostream>
using namespace std;

// the following works well
// by allocating memeory in heap
int* func() {
    int* x = new int(100); // Allocate memory on the heap
    return x;
}

int main() {
    int* c = func(); // c points to the dynamically allocated int
    cout << *c << endl; // Outputs 100
    delete c; // Free the allocated memory
}
