// Cycle Detection in undirected graph using DFS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// DFS function to detect a cycle starting from 'node'
// 'parent' is the node we came from (needed because in an undirected graph,
// the edge back to the parent is NOT a cycle, it's just the same edge)
bool DFS_Cycle(int node, int parent, vector<vector<int>>&Adj, vector<bool>&visited){

    // Mark the current node as visited
    visited[node] = 1;
    
    // Explore all neighbors of the current node
    for(int i = 0; i < Adj[node].size(); i++){

        // Skip the edge that leads back to the parent
        // (since it's the same edge we used to arrive here, not a cycle)
        if(parent == Adj[node][i]){
            continue;
        }    

        // If the neighbor is already visited (and it's not the parent),
        // it means we've reached an already-visited node via a different path
        // -> that means there's a cycle
        if(visited[Adj[node][i]]){
            return 1;
        }

        // Recursively visit the neighbor, passing current node as its parent
        // If a cycle is found deeper in the DFS, propagate that result up
        if(DFS_Cycle(Adj[node][i], node, Adj, visited)){
            return 1;
        }
    }

    // No cycle found through this node
    return 0;
}

// Wrapper function to check for a cycle across the entire graph
// (handles disconnected components too)
bool Is_Cycle(int V, vector<vector<int>>&Adj){

    // Keep track of visited nodes across all DFS calls
    vector<bool> visited(V, 0);

    // Try starting DFS from every unvisited node
    // (needed in case the graph has multiple disconnected components)
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            // let parent of 1st node in this DFS tree be -1 (no parent)
            if(DFS_Cycle(i, -1, Adj, visited)){
                return 1;
            }  
        }
    }

    // No cycle found in any component
    return 0;
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

    // Check if the graph contains a cycle and print the result
    if(Is_Cycle(vertices, Adj)){
        cout << "Cycle is present";
    }
    else{
        cout << "Cycle is not present";
    }

}