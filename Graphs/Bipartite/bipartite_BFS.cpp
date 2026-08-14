#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Checks if the connected component containing 'start' is bipartite.
// A graph is bipartite if we can color it using 2 colors such that
// no two adjacent nodes have the same color.
// We use BFS (level order) and alternate colors as we move to neighbors.
bool Check(int start, vector<vector<int>>& Adj, vector<int>& color){
    queue<int> q;

    // Start BFS from 'start', give it color 0 (arbitrary choice)
    q.push(start);
    color[start] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        // Visit all neighbors of current node
        for(int i = 0; i < Adj[node].size(); i++){
            int nei = Adj[node][i];

            if(color[nei] == -1){
                // Neighbor not colored yet -> assign it the OPPOSITE color
                // This is the core bipartite rule: adjacent nodes must differ
                color[nei] = 1 - color[node]; // if node = 0 , nei = 1 & vice-versa 
                q.push(nei);                  // add to queue to explore its neighbors later
            }
            else if(color[nei] == color[node]){
                // Neighbor already colored AND has the SAME color as current node
                // -> two adjacent nodes have the same color -> contradiction -> NOT bipartite
                return false;
            }
            // (implicit else: neighbor already has the correct opposite color, nothing to do)
        }
    }

    // Finished BFS without finding any same-color adjacent pair
    // -> this component is bipartite
    return true;
}

// Checks if the ENTIRE graph is bipartite, including disconnected components.
bool Is_Bipartite(vector<vector<int>>& Adj){
    int V = Adj.size();

    // color[i] = -1 means node i is not yet visited/colored
    // color[i] = 0 or 1 represents which "side" the node belongs to
    // This array is SHARED across all BFS calls so we never recolor
    // a node that was already colored in an earlier component.
    vector<int> color(V, -1);

    // Loop over every vertex to handle disconnected graphs
    // (a single BFS from one node won't reach nodes in other components)
    for(int i = 0; i < V; i++){
        if(color[i] == -1){          
            // Only start a new BFS if this node hasn't been visited yet.
            // This avoids redoing work on components we've already checked.
            if(!Check(i, Adj, color)) return false;
        }
    }

    // All components checked and none violated the bipartite condition
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

        // Bipartite checking conceptually assumes an UNDIRECTED graph
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    // Print adjacency list (just for visualization/debugging)
    cout << "\nAdjacency List:\n";

    for (int i = 0; i < vertices; i++) {

        cout << i << " -> ";

        for (int j = 0; j < Adj[i].size(); j++) {
            cout << Adj[i][j] << " ";
        }

        cout << endl;
    }

    
    if(Is_Bipartite(Adj)){
        cout<<"Graph is bipartite";
    }
    else{
        cout<<"Graph is not bipartite";
    }


    return 0;
}