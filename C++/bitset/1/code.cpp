#include <bitset>
#include <string> 
#include <iostream>
using namespace std;

int main(){
    // decimal to binary
    int number = 10;
    string binaryString = bitset <16> (number).to_string() ; // 16 bit representation of number
    cout << number << " in binary format " << binaryString << "\n";

    // binary to decimal
    string secondNumber = "111";
    unsigned long decimalNumber = bitset <16> (secondNumber).to_ulong();
    cout << secondNumber << " in decimal format " << decimalNumber << "\n";

    return 0;
}