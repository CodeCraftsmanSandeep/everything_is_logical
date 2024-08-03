// number of distinct sub-sequences

#include <bits/stdc++.h>
using namespace std;

int numberOfDistinctSubsequences(string str){
    // ending_with_char[i] = number of sub-sequences ending with char i
    vector <int> ending_with_char(26, 0);

    int ans = 1; // empty sub-sequnce
    for(auto ch: str){
        int past_seq = ans;
        ans = 2*ans - ending_with_char[ch-'a'];
        ending_with_char[ch-'a'] = past_seq;
    }

    return ans;
}

int main(){
    string str;
    cin >> str;

    cout << numberOfDistinctSubsequences(str) << "\n";
}
