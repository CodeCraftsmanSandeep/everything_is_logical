// JUST FIND Z
#include <bits/stdc++.h>
using namespace std;

vector <int> findZFunction(const int n, const string s){
    vector <int> z(n, 0);
    int l = 0;
    int r = 0;
    for(int i = 1; i <= n-1; i++){
        if(i < r){
            // s[i-l : r - l) = s[i : r)
            z[i] = min(z[i - l], r-i);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main(){
    string s;
    cin >> s;

    vector <int> z = findZFunction(s.size(), s);
    for(auto ele: z) cout << ele <<  " ";
    cout << "\n";
}