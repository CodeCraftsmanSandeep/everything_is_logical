#include <iostream>
using namespace std;

class shallow{
public:
    int* data;

    shallow(int val){
        data = new int;
        *data = val;
        // you should not do data = &val, that will lead to undefined behaviour (dangling pointer)
    }
};

class deep{
public:
    int* data;

    deep() {}

    deep(int val){
        data = new int;
        *data = val;
    }

    deep(deep& other){
        cout << "Custom constructor called\n";
        data = new int;
        *data = *(other.data);
    }
};

int main(){
    cout << "shallow copy:\n";
    shallow obj1(10);
    shallow obj2 = obj1;
    *(obj2.data) = 100;
    cout << *(obj1.data) << "\n"; // this will output 100 because, default copy constructor and assignment does shallow copy
    cout << "\n";

    cout << "deep copy:\n";
    deep obj3(10);
    deep obj4 = obj3;
    *(obj4.data) = 100;
    cout << *(obj3.data) << "\n"; // output: 10, deep copy

    deep obj5(obj3);
    *(obj5.data) = 100;
    cout << *(obj3.data) << "\n"; // output: 10, deep copy

    deep obj6;
    obj6 = obj3;
    *(obj6.data) = 100;
    cout << *(obj3.data) << "\n"; // output: 100, shallow copy because of shallow copy performed by default assignment operator 
}