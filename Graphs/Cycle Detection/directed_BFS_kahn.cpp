#include<iostream> 
#include<vector> 
#include<queue> 
using namespace std; 
 
// Function to detect cycle in a DIRECTED graph
// using BFS (Kahn's Algorithm / Topological Sort)
bool Is_cycle_BFS(vector<vector<int>>& Adj){ 
 
    int count = 0;                    // Counts how many vertices are processed
    int V = Adj.size();               // Number of vertices

    vector<int> Indeg(V, 0);          // Stores indegree of every vertex
    queue<int> q;                     // Queue for vertices having indegree 0
 
    // Calculate the indegree of every vertex
    // For every edge: i -> Adj[i][j]
    // increase the indegree of the destination vertex
    for(int i = 0; i < Adj.size(); i++){ 
        for(int j = 0; j < Adj[i].size(); j++){ 
            Indeg[Adj[i][j]]++; 
        } 
    } 
 
    // Put all vertices having indegree 0 into the queue
    // These vertices can be processed first
    for(int i = 0; i < V; i++){ 
        if(!Indeg[i]){ 
            q.push(i); 
        } 
    } 
 
    // BFS using Kahn's Algorithm
    while(!q.empty()){ 

        // One vertex is successfully processed
        count++; 

        // Remove the front vertex from the queue
        int node = q.front(); 
        q.pop(); 
 
        // Process all neighbours of the current vertex
        for(int i = 0; i < Adj[node].size(); i++){ 

            // Remove the edge:
            // node -> Adj[node][i]
            // Therefore, decrease the neighbour's indegree
            Indeg[Adj[node][i]]--; 
 
            // If indegree becomes 0,
            // the vertex is now ready to be processed
            if(!Indeg[Adj[node][i]]){ 
                q.push(Adj[node][i]); 
            } 
        } 
    } 
 
    // If all vertices were processed,
    // there is NO cycle
    //
    // If some vertices could not be processed,
    // they are part of a cycle
    if(count != V){ 
        return 1;       // Cycle is present
    } 
    else{ 
        return 0;       // Cycle is NOT present
    } 
 
} 
 
int main(){ 

    int vertices, edges; 

    // Take number of vertices from the user
    cout << "Enter number of vertices: "; 
    cin >> vertices; 

    // Take number of edges from the user
    cout << "Enter number of edges: "; 
    cin >> edges; 
 
    // Adjacency list representation of the graph
    vector<vector<int>> Adj(vertices); 
 
    int u, v; 

    cout << "Enter the structure of graph: "; 

    // Take edges as input
    for(int i = 0; i < edges; i++){ 

        cin >> u >> v; 

        // Since the graph is DIRECTED,
      
        // u -> v
        Adj[u].push_back(v); 

    } 
 
    // Print the adjacency list
    // for visualization/debugging
    for(int i = 0; i < vertices; i++){ 

        cout << i << "-> "; 

        for(int j = 0; j < Adj[i].size(); j++){ 
            cout << Adj[i][j] << " "; 
        } 

        cout << endl; 
    } 
 
    // Call the cycle detection function
    if(Is_cycle_BFS(Adj)){ 
        cout << "Cycle present in directed graph"; 
    } 
    else{ 
        cout << "Cycle NOT present in directed graph"; 
    } 
 
}