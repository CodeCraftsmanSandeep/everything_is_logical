
class Solution {
  public:
    // khans algo
    string topological_sort(vector <vector <int>>& adj, int n){
        vector <int> in_degree(n, 0);
        for(int u = 0; u < n; u++){
            for(auto v: adj[u]) in_degree[v]++;
        }
        
        stack <int> zero_degree;
        for(int u = 0; u < n; u++) if(in_degree[u] == 0) zero_degree.push(u);
        
        string ans;
        while(!zero_degree.empty()){
            int u = zero_degree.top();
            ans += char(u + 'a');
            zero_degree.pop();
            for(auto v: adj[u]){
                in_degree[v]--;
                if(in_degree[v] == 0) zero_degree.push(v);
            }
        }
        
        if(ans.size() != n) return ""; // not a DAG
        return ans;
    }
    
    
    string findOrder(string dict[], int n, int k) {
        if(n == 1) return dict[0];
        vector <vector <int>> adj(k);
        for(int i = 1; i < n; i++){
            int j;
            for(j = 0; j < min(dict[i-1].size(), dict[i].size()); ++j){
                if(dict[i][j] != dict[i-1][j]) break;
            }
            if(j == min(dict[i-1].size(), dict[i].size())) continue;
            adj[dict[i-1][j] - 'a'].push_back(dict[i][j] - 'a');
        }
        return topological_sort(adj, k);
    }
};