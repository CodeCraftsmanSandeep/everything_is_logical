#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> dijktra(int n, vector <vector <pair <int, int>>>& adj, int s){
    vector <int> dis(n, INT_MAX);

    struct comp{
        bool operator() (const pair <int, int>& p1, const pair <int, int>& p2){
            return p1.second > p2.second;
        }
    };
    // min heap
    priority_queue <pair <int, int>, vector <pair <int, int>>, comp > minHeap;



    return dis;
}

int main(){
    int n, m;
    cin >> n >> m;

    // 0 based indexing graph
    vector <vector <pair <int, int>>> adj(n);
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source; cin >> source;

    vector <int> dis = dijktra(n, adj, source);
    for(int u = 0; u < n; u++){
        cout << "dis[" << u << "] = " << (dis[u] == INT_MAX ? "inf" : to_string(dis[u])) << "\n";
    }

    
}