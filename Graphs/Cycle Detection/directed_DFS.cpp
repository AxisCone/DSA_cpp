// Cycle Detection in directed graph using DFS
#include<iostream>
#include<vector>

using namespace std;

// Performs DFS from 'node' to detect a cycle in a directed graph.
// Adj      : adjacency list of the graph
// path     : tracks nodes on the CURRENT recursion stack (true = currently being visited)
// visited  : tracks nodes whose entire subtree has already been fully explored (no cycle found there)
bool Detect_Cycle(int node, vector<vector<int>> &Adj, vector<bool> &path, vector<bool> &visited){

    // Mark this node as part of the current DFS path (recursion stack)
    path[node] = 1;

    // Explore all neighbors of the current node
    for(int i = 0; i < Adj[node].size(); i++){

        // If the neighbor is already on the current path, we found a back edge -> cycle
        if(path[Adj[node][i]]){
            return 1;
        }

        // If the neighbor's subtree was already fully explored earlier
        // (and no cycle was found), skip re-exploring it
        if(visited[Adj[node][i]]){
            continue;
        }

        // Recursively explore the neighbor; propagate true if a cycle is found downstream
        if(Detect_Cycle(Adj[node][i], Adj, path, visited)){
            return 1;
        }
    }

    // Done exploring this node's subtree with no cycle found:
    // remove it from the current path (backtrack)
    path[node] = 0;

    return 0;
}

// Checks if the given directed graph (adjacency list) contains a cycle.
// Runs DFS from every unvisited node to handle disconnected components.
bool Is_Cyclic(vector<vector<int>> &Adj){
    int V = Adj.size();

    vector<bool> path(V, 0);     // recursion-stack tracker, shared across all DFS calls
    vector<bool> visited(V, 0);  // fully-processed tracker, shared across all DFS calls

    for(int i = 0; i < Adj.size(); i++){
        if(Detect_Cycle(i, Adj, path, visited)){
            return 1;  // cycle found starting from node i
        }
    }

    return 0;  // no cycles found in any component
}

int main(){
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;

    // Adjacency list representation of the graph
    vector<vector<int>> Adj(vertices);

    int u, v;
    cout << "Enter the structure of graph: ";
    for(int i = 0; i < edges; i++){
        cin >> u >> v;
        // Since the graph is undirected, add the edge both ways
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    // Print the adjacency list for visualization/debugging
    for(int i = 0; i < vertices; i++){
        cout << i << "-> ";
        for(int j = 0; j < Adj[i].size(); j++){
            cout << Adj[i][j] << " ";
        }
        cout << endl;
    }

    // Check and report whether the graph has a cycle
    Is_Cyclic(Adj);

}