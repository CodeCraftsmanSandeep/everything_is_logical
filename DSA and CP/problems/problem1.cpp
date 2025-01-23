// problem: https://www.geeksforgeeks.org/swap-characters-in-a-string/
// effecient approach is nice food for thought
// time: O(N)
// space: O(N)

#include <bits/stdc++.h>
using namespace std;

string left_rotate(string str, int rotate){
    int n = str.size();
    rotate %= n;
    return str.substr(rotate, n-rotate) + str.substr(0, rotate);
}

string solve(string str, int N, int B, int C){
    C %= N; // if C > N, then taking C%N
    if(C == 0) return str;

    int f = B/N;
    int r = B%N;

    int first_part_rotation = ((N%C)*f)%C;
    string part1 = left_rotate(str.substr(0, C), first_part_rotation);

    int right_part_rotation = (C*f)%(N-C);
    string part2 = left_rotate(str.substr(C), right_part_rotation);

    str = part1 + part2;

    // naive approach for remaining r
    for(int i = 0; i < r; i++){
        swap(str[i], str[(i + C)%N]);
    }

    return str;
}

int main(){
    int N, B, C;
    cin >> N >> B >> C;

    string str;
    cin >> str;

    string ans = solve(str, N, B, C);
    cout << ans << "\n";
}
