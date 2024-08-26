class Solution {
public:
    bool explore(int u, vector <vector <int>>& adj, vector <bool>& ancestor, vector <bool>& explored){
        ancestor[u] = true;
        for(auto v: adj[u]){
            if(ancestor[v]) return true;
            if(explored[v]) continue;
            if(explore(v, adj, ancestor, explored)) return true;
        }
        ancestor[u] = false;
        explored[u] = true;
        return false;
    }

    bool isCycle(int n, vector <vector <int>>& adj){
        vector <bool> explored(n, false);
        vector <bool> ancestor(n, false);
        for(int u = 0; u < n; u++){
            if(!explored[u]){
                if(explore(u, adj, ancestor, explored)) return true;
            }
        }
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        // just detect cycle in directed graph
        vector <vector <int>> adj(numCourses);
        for(auto edge: prerequisites){
            int ai = edge[0];
            int bi = edge[1];

            adj[bi].push_back(ai);
        }

        for(int i = 0; i < numCourses; i++){
            cout << i << " : ";
            for(auto ele: adj[i]) cout << ele << " ";
            cout << "\n";
        }

        return !isCycle(numCourses, adj);
    }
};