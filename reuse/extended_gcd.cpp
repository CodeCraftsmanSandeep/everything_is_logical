#include <bits/stdc++.h>
using namespace std;

long long int extended_gcd(long long int a, long long int b, long long int& x, long long int& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    long long int x1, y1;
    long long int g = extended_gcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return g;
}

int main(){
    long long int a, b;
    cin >> a >> b;
    long long int x, y;
    long long int g = extended_gcd(a, b, x, y);
    cout << a << "*(" << x << ") + " << b << "*(" << y << ") = " << g << "\n";
}
