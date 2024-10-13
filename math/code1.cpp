#include <iostream>
#include <cmath>
using namespace std;

int binaryStringLength(int num){
	if (num == 0) return 1;
	return int(log2(num)) + 1;
}

int main(){
	cout << binaryStringLength(10) << "\n";
	cout << binaryStringLength(2) << "\n";
	
	return 0;
}
