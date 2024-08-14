#include <bits/stdc++.h>
using namespace std;

class features{
public:
    virtual string processor() = 0;
};

class dell: public features{
public:
    string processor() override {
        cout << __PRETTY_FUNCTION__ << "\n";
        string proc = "intel i7";
        return proc;
    }
};

class mac: public features{
public:
    string processor() override{
        cout << __PRETTY_FUNCTION__ << "\n";
        string proc = "M4";
        return proc;
    }
};

int main(){
    dell sandeep;
    features* ptr = &sandeep;
    cout << ptr->processor() << "\n";

    mac kumar;
    ptr = &kumar;
    cout << ptr->processor() << "\n";
}