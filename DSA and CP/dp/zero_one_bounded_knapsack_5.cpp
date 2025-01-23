/*
You are given n types of items, you have ui items of ith type, 
and each item of ith type weighs wi and costs ci. 
What is the maximal cost you can get by picking some items weighing at most W 
in total?
*/
#include <iostream>
#include <vector>
using namespace std;

int zero_one_knapsack(const int n, const int W, const vector <int>& weight, vector <int>& cost){
    // dp[i][w] = optimal value where the knapsack capacity is w using items weight[i:], cost[i:]
    vector < vector <int> > dp(1+n, vector <int> (1+W, 0));
    for(int i = n-1; i >= 0; i--){
        for(int w = W; w >= 0; w--){
            dp[i][w] = dp[i+1][w];
            if(weight[i] <= w) dp[i][w] = max(dp[i][w], cost[i] + dp[i+1][w-weight[i]]);
        }
    }
    return dp[0][W];
}

int findOptimalValue(int n, int W, vector <int>& freq, vector <int>& weight, vector <int>& cost){
    vector <int> new_weights;
    vector <int> new_costs;
    int two_power, completed;
    for(int i = 0; i < n; i++){
        two_power = 0;
        completed = 0;
        while((1 << two_power) + completed <= freq[i]){
            completed += (1 << two_power);
            new_weights.push_back(weight[i]*(1 << two_power));
            new_costs.push_back(cost[i]*(1 << two_power));
            two_power++;
        }
        if(completed != freq[i]){
            new_weights.push_back((freq[i] - completed)*weight[i]);
            new_costs.push_back((freq[i] - completed)*cost[i]);
            completed += (freq[i] - completed);
        }
    }

    return zero_one_knapsack(new_weights.size(), W, new_weights, new_costs);
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

    cout << findOptimalValue(n, W, freq, w, c) << "\n";
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