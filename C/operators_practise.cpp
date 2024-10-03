#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int b = 6;

    a += b += a += a += b;
    printf("%d %d\n", a, b);

    int x = 10;
    int y = ~x + 1; // 2's complement
    int z = !x + 1; // !x is 1 only when x is zero
    cout << x << ", " << y << ", " << z << "\n";
}