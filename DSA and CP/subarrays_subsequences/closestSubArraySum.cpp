// Given an array A, which can be positive, negative (or) zero.
// Find the sub-array whoose sum is as close as to k

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int goal;
    cin >> goal;

    vector <int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int start_index = -1;
    int len = -1;

    int min_diff = INT_MAX;
    map <int, int> pref;
    pref[0] = -1;
    int curr = 0;

    for(int i = 0; i < n; i++){
        curr += arr[i];
        pref[curr] = i;

        auto it = pref.lower_bound(curr - goal);
        if(it == pref.end()){
            it--;
            {
                int p = it->first;
                int j = it->second;
                int subarray = curr - p;
                if(abs(subarray - goal) < min_diff){
                    start_index = j + 1;
                    len = i - (j + 1) + 1;
                    min_diff = abs(subarray - goal);
                }
            }
        }else{
            {
                int p = it->first;
                int j = it->second;
                int subarray = curr - p;
                if(abs(subarray - goal) < min_diff){
                    start_index = j + 1;
                    len = i - (j + 1) + 1;
                    min_diff = abs(subarray - goal);
                }
            }
            if(it != pref.begin()){
                it--;
                {
                    int p = it->first;
                    int j = it->second;
                    int subarray = curr - p;
                    if(abs(subarray - goal) < min_diff){
                        start_index = j + 1;
                        len = i - (j + 1) + 1;
                        min_diff = abs(subarray - goal);
                    }
                }
            }
        }
    }

    cout << min_diff << "\n";
    cout << start_index << " " << len << "\n";
}

/*
Test cases:

Input:
    4 10
    -2 -3 -4 5
Output:
    5
    3 1
------------------
Input:
    4 10
    -2 -3 -4 -5
Output:
    10
    1 0
------------------
Input:
    4 -10
    -15 -2 -3 -4
Output:
    1
    1 3

*/