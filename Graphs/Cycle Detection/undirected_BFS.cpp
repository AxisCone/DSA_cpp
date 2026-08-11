// Cycle Detection in undirected graph using BFS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;


bool BFS_Cycle(int node,vector<vector<int>>&Adj, vector<bool>&visited){

    queue<pair<int,int>>q;
    visited[node]=1;
    q.push({0,-1});

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;

        for(int i = 0; i < Adj[node].size(); i++){
    
            if(parent == Adj[node][i]){
                continue;
            }    
    
         
            if(visited[Adj[node][i]]){
                return 1;
            }
    
            visited[Adj[node][i]] = 1;
            q.push({Adj[node][i],node});
            
            }
        }
    
        // No cycle found through this node
        return 0;
    }
    
    


bool Is_Cycle(int V, vector<vector<int>>&Adj){

    
    vector<bool> visited(V, 0);

   
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            
            if(BFS_Cycle(i,Adj,visited)){
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