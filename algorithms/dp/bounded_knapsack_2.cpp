/*
Given N items, each item having a given weight Ci and a profit value Pi, 
the task is to maximize the profit by selecting a maximum of K items adding 
up to a maximum weight W.
*/
#include <iostream>
#include <vector>
using namespace std;

int findOptimalValue(int n, int W, int k, vector <int>& weight, vector <int>& value){
    vector <vector <vector <int> > > dp(1+W, vector <vector <int> > (1+k, vector <int> (1+n, 0)));
    // dp[w][j][i] = 
    // optimal value for knapsack capacity w, with at atmost k-j items, with items weight[i:], value[i:]
    
    // we can do space optimization: 
    // because each value dp[w][j][i] is dependent on only two values dp[w][j][i+1], dp[w-weight[i]][j+1][i+1]
    // note: i + 1 is same in above transition state
    for(int w = 1; w <= W; w++){
        for(int j = k-1; j >= 0; j--){
            for(int i = n-1; i >= 0; i--){
                dp[w][j][i] = dp[w][j][i+1];
                if(w >= weight[i]){
                    dp[w][j][i] = max(dp[w][j][i], value[i] + dp[w-weight[i]][j+1][i+1]);
                }
            }
        }
    }
    return dp[W][0][0];
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