#include<iostream>
#include<vector>
using namespace std;

bool Check(int node, vector<vector<int>>& Adj, vector<int>& color){ 
    
    for(int i = 0; i < Adj[node].size(); i++){
        int nei = Adj[node][i];

        if(color[nei] == -1){
            // Not visited yet -> assign opposite color and recurse into it
            color[nei] = 1 - color[node];
            if(!Check(nei, Adj, color)) return false;  // propagate failure immediately
        }
        else if(color[nei] == color[node]){
            // Already visited and same color as current node -> conflict
            return false;
        }
        // else: already visited with correct opposite color, nothing to do
    }
    return true;  // all neighbors checked out fine
}

bool Is_Bipartite(vector<vector<int>>& Adj){
    int V = Adj.size();
    vector<int> color(V, -1);

    for(int i = 0; i < V; i++){
        if(color[i] == -1){
            color[i] = 0;              // color the starting node of this component
            if(!Check(i, Adj, color)) return false;
        }
    }
    return true;
}

int main() {

    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> Adj(vertices);

    int u, v;

    cout << "Enter the edges (u v): " << endl;

    for (int i = 0; i < edges; i++) {
        cin >> u >> v;

        // Directed graph
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    // Print adjacency list
    cout << "\nAdjacency List:\n";

    for (int i = 0; i < vertices; i++) {

        cout << i << " -> ";

        for (int j = 0; j < Adj[i].size(); j++) {
            cout << Adj[i][j] << " ";
        }

        cout << endl;
    }

    
    return 0;
}