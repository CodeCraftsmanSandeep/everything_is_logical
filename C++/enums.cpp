#include <bits/stdc++.h>
using namespace std;

enum color{white = 10, grey, black = 11 };

int main(){
    cout << white << "\n";
    cout << grey << "\n";
    cout << black << "\n";
    cout << (grey == black) << "\n"; // output 1
    // notice that grey and black are equal here
    // be careful while using enums

    color x = white; // valid
    // color y = 10; // invaid 
}