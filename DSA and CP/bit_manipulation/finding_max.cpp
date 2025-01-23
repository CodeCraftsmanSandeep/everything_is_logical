#include <iostream>
using namespace std;

int find_max(int a, int b){
    int z = (a - b);
    int i = (z >> 31)&1;
    // if i = 1, b is greater
    // if i = 0, a is greater
    int max = a - i*z;
    return max;
}

int main(){
    int a, b;
    cin >> a >> b;

    cout << find_max(a, b) << "\n";
}