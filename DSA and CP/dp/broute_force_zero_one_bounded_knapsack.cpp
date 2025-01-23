/*
You are given n types of items, you have freq[i] items of ith type, 
and each item of ith type weighs wi and costs ci. 
What is the maximal cost you can get by picking some items weighing at most W 
in total?
*/
#include <iostream>
#include <vector>
using namespace std;

int findOptimalValue(const int i, const int W, vector <int>& freq, vector <int>& weight, vector <int>& cost){
    if(i < 0) return 0;
    int optimalValue = 0;
    for(int f = 0; f <= freq[i] && f*weight[i] <= W; f++){
        optimalValue = max(optimalValue, f*cost[i] + findOptimalValue(i-1, W - f*weight[i], freq, weight, cost));
    }
    return optimalValue;
}

int main(){
    int n, W;
    cin >> n >> W;

    vector <int> freq(n);
    for(int i = 0; i < n; i++) cin >> freq[i];

    vector <int> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];

    vector <int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    cout << findOptimalValue(n-1, W, freq, w, c) << "\n";
}

/*
Test case:
4 17
5 3 4 8 
6 1 2 8 
7 6 7 8

Output:
53

*/