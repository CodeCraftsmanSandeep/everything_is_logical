#include <bits/stdc++.h>
using namespace std;

class Base{
public:
    virtual void sayHello(){
        cout << "Hello from Base class\n";
        return;
    }
    void sayBye(){
        cout << "Bye from Base class\n";
        return;
    }
};

class Child : public Base{
public:
    void sayHello(){
        cout << "Hello from Child class\n";
        return;
    }
    void sayBye(){
        cout << "Bye from Child class\n";
        return;
    }
};

int main(){
    Child c;
    Base* base_ptr = &c;

    c.sayHello();
    c.sayBye();
    cout << "\n";
    
    base_ptr->sayHello();
    base_ptr->sayBye();
}