#include <bits/stdc++.h>
using namespace std;

int extended_euclid(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1;
    int y1;
    int g = extended_euclid(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return g;
}

int modInverse(int a, int m){
    if(m == 1) return -1;
    
    int x;
    int y;
    int g;
    g = extended_euclid(a, m, x, y);
    if(g != 1) return -1;
    else return (x%m + m)%m;
}
