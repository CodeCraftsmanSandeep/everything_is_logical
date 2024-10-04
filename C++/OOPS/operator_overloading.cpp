#include <iostream>
using namespace std;

class baseClass{
private:
    int x = 100;
protected:
    int y = 10;
public:
    int z = 100;

    virtual void function(){ // remove virtual word and try
        cout << "baseClass\n";
    }
};

class childClass: public baseClass{
public:
    int a = 20;
    void func(int a){
        // cout << x << "\n"; is error because x is private
    }

    void function(){
        cout << "childClass\n";
    }

    // overloading + operator
    childClass operator+(childClass const& obj){
        childClass new_obj;
        new_obj.a += this->a;
        return new_obj;
    }

    // overloading - operator
    childClass operator-(childClass const& obj){
        childClass new_obj;
        new_obj.a -= this->a;
        return new_obj;
    }
};

int main(){
    childClass c;
    baseClass *base_ptr = &c;
    base_ptr->function();

    childClass d;
    childClass e = c + d;
    cout << e.a << "\n";

    childClass f = c - d;
    cout << f.a << "\n";
}