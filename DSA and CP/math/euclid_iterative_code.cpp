#include <iostream>
using namespace std;

// iterative code
long long int gcd(long long int a, long long int b){
    long long int temp;
    while(b != 0){
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

int main(){
    long long int a,b;
    cin >> a >> b;
    cout << "Gcd: " << gcd(a, b) << "\n";
}
