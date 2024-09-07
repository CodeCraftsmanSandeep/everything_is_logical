#include <iostream>
#include <vector>
using namespace std;

void printOptimalSolution(const int& n, const int& W, const vector <int>& wt, const vector <int>& val){
    // dp[i][w] = maximum value obtained with knapsack with weight w and items wt[i:], val[i:]
    vector < vector<int> > dp(1+n, vector <int> (1+W, 0));
    for(int i = n-1; i >= 0; i--){
        for(int w = 0; w <= W; w++){
            dp[i][w] = dp[i+1][w]; // with same weight not including object i
            if(w >= wt[i]) dp[i][w] = max(dp[i][w], dp[i+1][w-wt[i]] + val[i]);
        }
    }
    int w = W;
    int i = 0;
    while(i < n){
        if(dp[i][w] != dp[i+1][w]){
            cout << "item " << i << " : " << "(w=" << wt[i] << ", v=" << val[i] << ")\n";
            w -= wt[i];
        }
        i++;
    }
    cout << "Maximum value: " << dp[0][W] << "\n";
}

int main(){
    int n;
    cin >> n;

    int W;
    cin >> W;

    vector <int> wt(n);
    for(int i = 0; i < n; i++) cin >> wt[i];

    vector <int> val(n);
    for(int i = 0; i < n; i++) cin >> val[i];

    printOptimalSolution(n, W, wt, val);
}