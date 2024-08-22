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

    // negative number
    cout <<"-10 2's complement representation: " << bitset <8>(-10).to_string() << "\n";

    // converting 2's complement 8-bit representation to correct decimal number
    std::bitset<8> bits("11111000");
    unsigned int temp = bits.to_ulong();
    signed int actual_number;
    if(bits.test(7)){
        actual_number = temp - (1 << 8);
    }else actual_number = temp;
    cout << actual_number << "\n";

    return 0;
}
