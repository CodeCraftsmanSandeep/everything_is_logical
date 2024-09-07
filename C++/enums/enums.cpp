#include <iostream>
using namespace std;

enum color{white = 1, grey, black = 2, orange = 1};
enum gender{male, female};
// enum water{high = 2.2, low = false}; // this is invalid as doubles cannot be used as values for enums

// If the following function is present, then there will be compile time error
// A enum value white is already present in this scope
// void white(){
//     // test
// }

int main(){
    cout << "white: " << white << "\n";
    cout << "grey: " << grey << "\n";
    cout << "black: " << black << "\n";
    cout << (grey == black) << "\n"; // output 1
    // notice that grey and black are equal here
    // be careful while using enums

    color x = white; // valid
    // color y = 1; // invaid (C++ enums are strongly typed, implicit type conversion is not possible)
    color y = (color)1; // this is valid because of explicit type conversion

    cout << "male: " << male << "\n";
    cout << "female: " << female << "\n"; // this has the integer value same as that of white
    cout << (female == orange) << "\n";  
    // compiler throws error because of above line
    // there is no error in above line
    // I think there should be a error in this line
    // But C++ does not enforce strict type checking between two different enum types
    // enum values are iomplicitly converted to integers
    // But this is weired, as integer is not implicitly converted to enum, but two different enums are implicitly converted
    // As the saying goes: Everything is fair in love, war in C (here C++) :-|
}