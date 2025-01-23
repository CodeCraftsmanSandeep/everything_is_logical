#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

void bottom_to_top(int u, int p, vector <int>& sub_ans, vector <int>& count, vector <vector <int>>& adj){
    
        if(v == p) continue;
        bottom_to_top(v, u, sub_ans, count, adj);
        sub_ans[u] += sub_ans[v] + count[v];
        vertices += count[v];
    }
    count[u] = vertices;
}

void top_to_bottom(int u, int p, vector <int>& sub_ans, vector <int>& count, vector <vector <int>>& adj, int n){
    if(p != -1) sub_ans[u] = (sub_ans[p] - sub_ans[u] - count[u]) + (n - count[u]) + sub_ans[u];
    for(int v: adj[u]){
        if(v == p) continue;
        top_to_bottom(v, u, sub_ans, count, adj, n);
    }
}

void solve(){
    int n;
    cin >> n;

    vector <vector <int>> adj(n);
    for(int i = 1; i <= n-1; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector <int> sub_ans(n, 0), count(n, 0);
    bottom_to_top(0, -1, sub_ans, count, adj);
    top_to_bottom(0, -1, sub_ans, count, adj, n);

    for(int u = 0; u < n; u++) cout << sub_ans[u] << " ";
    cout << "\n";
}

int main(){
    int t = 1;
    // cin >> t;

    while(t--) solve();
}