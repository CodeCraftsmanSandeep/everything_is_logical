/*
Given N items, each item having a given weight Ci and a profit value Pi, 
the task is to maximize the profit by selecting a maximum of K items adding 
up to a maximum weight W.
*/
#include <iostream>
#include <vector>
using namespace std;

int findOptimalValue(int n, int W, int k, vector <int>& weight, vector <int>& value){
    vector <vector <int> > dp(1+k, vector <int> (1+W, 0));
    for(int i = 0; i < n; i++){
        for(int j = k; j >= 1; j--){
            for(int w = W; w >= 0; w--){
                if(w >= weight[i]) dp[j][w] = max(dp[j][w], value[i] + dp[j-1][w - weight[i]]);
            }
        }
    }
    return dp[k][W];
}

int main(){
    int n, W, k;
    cin >> n >> W >> k;

    vector <int> weight(n);
    for(int i = 0; i < n; i++) cin >> weight[i];

    vector <int> value(n);
    for(int i = 0; i < n; i++) cin >> value[i];

    cout << findOptimalValue(n, W, k, weight, value) << "\n";
}