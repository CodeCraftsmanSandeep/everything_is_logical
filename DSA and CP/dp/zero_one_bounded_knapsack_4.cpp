/*
You are given n types of items, you have ui items of ith type, 
and each item of ith type weighs wi and costs ci. 
What is the maximal cost you can get by picking some items weighing at most W 
in total?
*/
#include <iostream>
#include <vector>
using namespace std;

int findOptimalValue(int n, int W, vector <int>& u, vector <int>& weight, vector <int>& cost){
    // dp[i][w] = optimal value for weight w, with items weight[i:], cost[i:]
    vector <vector <int> > dp(1+n, vector <int> (W, 0));
    for(int i = n-1; i >= 0; i--){
        for(int w = 1; w <= W; w++){
            dp[i][w] = dp[i+1][w];
            for(int j = 1; j <= u[i] && w >= j*weight[i]; j++){
                dp[i][w] = max(dp[i][w], j*cost[i] + dp[i+1][w-j*weight[i]]);
            }
        }
    }
    return dp[0][W];
}

int main(){
    int n, W;
    cin >> n >> W;

    vector <int> u(n);
    for(int i = 0; i < n; i++) cin >> u[i];

    vector <int> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];

    vector <int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    cout << findOptimalValue(n, W, u, w, c) << "\n";
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