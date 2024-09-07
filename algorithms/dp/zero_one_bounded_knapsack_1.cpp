/*
Given N items, each item having a given weight Ci and a profit value Pi, 
the task is to maximize the profit by selecting a maximum of K items adding 
up to a maximum weight W.
*/
#include <iostream>
#include <vector>
using namespace std;

int recurse(int w, int k, int i, vector <int>& weight, vector <int>& value, vector <vector <vector <int> > >& dp){
    if(k < 0 || i < 0) return 0;
    if(dp[i][k][w] != -1) return dp[i][k][w];
    if(w >= weight[i]) return dp[i][k][w] = max(value[i] + recurse(w - weight[i], k-1, i-1, weight, value, dp), recurse(w, k, i-1, weight, value, dp));
    return dp[i][k][w] = recurse(w, k, i-1, weight, value, dp);
}

int main(){
    int n, w, k;
    cin >> n >> w >> k;

    vector <int> weight(n);
    for(int i = 0; i < n; i++) cin >> weight[i];

    vector <int> value(n);
    for(int i = 0; i < n; i++) cin >> value[i];

    vector <vector <vector <int> > > dp(n, vector <vector <int> > (1+k, vector <int> (1+w, -1)));
    cout << recurse(w, k, n-1, weight, value, dp) << "\n";
}