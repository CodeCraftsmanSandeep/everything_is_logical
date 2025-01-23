// solution to find all bridges:
// question: https://leetcode.com/problems/critical-connections-in-a-network/description/

// time: O(n + m) for one and only dfs
// space: O(n) auxiallry space for storing time
//        O(n) for recursive stack

class Solution {
public:
    void dfs(int u, int p, vector <vector <int>>& adj, vector <int>& start_time, int& time, vector <vector <int>>& bridge_edges){
        int min_time = start_time[u] = time++;
        for(int v: adj[u]){
            if(v != p){
                if(start_time[v] == -1) dfs(v, u, adj, start_time, time, bridge_edges);
                if(start_time[v] > start_time[u]) bridge_edges.push_back({u, v});
                min_time = min(min_time, start_time[v]);
            }
        }
        start_time[u] = min_time;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector <vector <int>> adj(n);
        for(int i = 0; i < connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector <vector <int>> bridge_edges;
        vector <int> start_time(n, -1);
        int initial_time = 0;

        for(int u = 0; u < n; u++){
            if(start_time[u] == -1){
                dfs(u, -1, adj, start_time, initial_time, bridge_edges);
            }
        }

        return bridge_edges;
    }
};
