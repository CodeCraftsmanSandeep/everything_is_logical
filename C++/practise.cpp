#include <iostream>
using namespace std;

template <typename T>
int countSetBits(T n){
    return __builtin_popcount(n);
}

int main(){
    unsigned long long int a;
    cin >> a;
    cout << countSetBits <unsigned long long int> (a) << "\n";
}