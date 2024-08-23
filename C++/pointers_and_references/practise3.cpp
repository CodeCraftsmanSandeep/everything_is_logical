#include <iostream>
using namespace std;

// static variables
int& func(){
    static int x = 100;
    x++;
    return x; // x is local variable to func() and will be destroyed
}

int main(){
    cout << "Note the difference:\n";
    int& c = func();
    int d = func();
    func();
    c += 10;
    d += 10;
    int& e = func();
    cout << c << "\n";
    cout << d << "\n";
    cout << e << "\n";

    cout << &c << ", " << &d << ", " << &e << "\n"; // c and e represents same mem location

    c = 1000;
    cout << c << "\n";
    cout << d << "\n";
    cout << e << "\n";
}
