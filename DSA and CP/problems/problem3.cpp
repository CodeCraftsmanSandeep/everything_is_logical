#include <bits/stdc++.h>
using namespace std;

void print_gray_codes(int n, string str, bool first_zero){
    if(n == 0){
        cout << str << "\n";
        return;
    }
    if(first_zero){
        print_gray_codes(n-1, str + "0", true);
        print_gray_codes(n-1, str + "1", false);
        return;
    }
    print_gray_codes(n-1, str + "1", true);
    print_gray_codes(n-1, str + "0", false);
}

int main(){
    int n;
    cin >> n;

    print_gray_codes(n, "", true);    // adding first zero in the recursion
}
