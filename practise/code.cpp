#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "101";

    cout << stol(s, nullptr, 10) << "\n";  // outputs 101
    cout << stol(s, nullptr, 2) << "\n";   // outputs 5
    cout << stol(s, nullptr, 3) << "\n";   // outputs 10
}