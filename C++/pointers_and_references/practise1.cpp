#include <iostream>
using namespace std;

// the following does not work
// dangling references 
// dangling references lead to undefined behaviour
int& func(){
    int x = 100;
    return x; // x is local variable to func() and will be destroyed
}

int main(){
    int c = func(); 
}