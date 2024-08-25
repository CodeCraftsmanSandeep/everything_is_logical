enum status{un_visited, visited, explored};

class Solution {
  public:
    bool explore(int u, vector <status>& vertices, vector <int> adj[]){
        vertices[u] = visited;
        for(auto v: adj[u]){
            if(vertices[v] == explored) continue;
            if(vertices[v] == visited) return true; // back edge detected
            if(explore(v, vertices, adj)) return true;
        }
        vertices[u] = explored;
        return false;
    }
    
    bool isCyclic(int n, vector<int> adj[]) {
        vector <status> vertices(n, un_visited);
        
        for(int u = 0; u < n; u++){
            if(vertices[u] == un_visited){
                if(explore(u, vertices, adj)) return true;
            }
        }
        return false;
    }
};
