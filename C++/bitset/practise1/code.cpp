#include <cmath>
#include <bitset>
#include <string> 
#include <iostream>
using namespace std;

string decimalToBinary(int number){
	if(number == 0) return "0";
	return bitset <64> (number).to_string().substr(64 - (int(log2(number)) + 1));
}

int main(){
    // decimal to binary
    int number = 9;
    cout << number << " in binary format " << decimalToBinary(number) << "\n";

    // binary to decimal
    string secondNumber = "111";
    unsigned long decimalNumber = bitset <16> (secondNumber).to_ulong();
    cout << secondNumber << " in decimal format " << decimalNumber << "\n";

    return 0;
}
