/*
merge 
    - by default uses < operator
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void experiment1(){
    pair <int,int> left[] = {make_pair(100, 100), make_pair(105, 200), make_pair(900, 100)};
    int n = sizeof(left)/sizeof(left[0]);
    pair<int,int> right[] = {make_pair(70, 105), make_pair(100, 100), make_pair(100, 101), make_pair(900, 900)};
    int m = sizeof(right)/sizeof(right[0]);

    pair <int,int> arr[n+m];
    merge(left, left + n, right, right + m, arr);
    for(int i = 0; i < n + m; i++) cout << "("<< arr[i].first << "," << arr[i].second << ")\n";
    cout << "\n";

    vector <pair<int,int>> comb(n+m);
    merge(left, left +n, right, right + m, comb.begin());
    for(auto it: comb) cout << "(" << it.first << "," << it.second << ")\n";
    cout << "\n";

    vector<pair <int,int>> copy;
    merge(left, left+n, right, right + m, back_inserter(copy));
    for(auto it: copy) cout << "(" << it.first << "," << it.second << ")\n";
    cout << "\n";
    cout << "-------------------\n";
}

void experiment2(){
    // elements in descending order
    vector <pair <int,int>> left = {make_pair(200, 200), make_pair(190, 200), make_pair(190, 199), make_pair(100, 100)};
    vector <pair <int,int>> right = {make_pair(200, 150), make_pair(150, 100), make_pair(100, 20000)};
    vector <pair <int,int>> arr;
    merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(arr), greater <pair<int,int>>());
    for(auto it: arr) cout << "(" << it.first << ", " << it.second << ")\n";
    cout << "\n";

    // only comparing first element of the pair
    merge(left.begin(), left.end(), right.begin(), right.end(), arr.begin(), [](const pair <int,int>& p1, const pair <int,int>& p2){
        return (p1.first >= p2.first);
    });
    for(auto it: arr) cout << "(" << it.first << ", " << it.second << ")\n";
    cout << "\n";
}


int main(){
    experiment1();

    // custom operator
    experiment2();
}