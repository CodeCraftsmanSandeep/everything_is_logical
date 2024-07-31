#include <iostream>
#include <string>
using namespace std;

int main(){
    // conversion of binary format of a number to its decimal format
    string binaryString1 = "010110";
    cout << "Binary to Decimal : " << stoi(binaryString1, nullptr, 2) << "\n";

    // conversion of octal format of a number to its decimal format
    string octalString = "771";
    cout << "Octal to Decimal : " << stoi(octalString, nullptr, 8)  << "\n";

    string hexString = "FFFFFFFFF";
    // the following will give a run time error of out_of_range
    // cout << "Hexa to Decimal : " << stoi(hexString, nullptr, 16) << "\n";

    // to avoid out_od_range we can use stol, stoll
    cout << "Hexa to Decimal(long long int) : "  << stoll(hexString, nullptr, 16) << "\n";

    // use of pos pointer (which will help to process left-out string)
    size_t pos;
    string binaryString = "1019100";
    cout << "Valid number : " << stoi(binaryString, &pos, 2) << "\n";        // 101 is converted and position of 9 is stored in pos
    cout << "Invalid part : " << binaryString.substr(pos) << "\n";           // priting remaining string
    // note
        // if above binaryString is starting with invalid part, then no one can save us from run-time error
}
