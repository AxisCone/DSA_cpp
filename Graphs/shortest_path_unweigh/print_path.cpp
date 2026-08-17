#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Function to find the shortest path using BFS
vector<int> shortestPath(vector<pair<int,int>> edges, int N, int M, int src, int dest) {

    // Create adjacency list for the graph
    vector<vector<int>> adj(N);

    // Store all edges in the adjacency list
    for(int i = 0; i < M; i++) {

        int u = edges[i].first;
        int v = edges[i].second;

        // Convert vertices from 1-based to 0-based
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    // dist[i] stores the distance of node i from source
    // Initially, -1 means the node has not been reached
    vector<int> dist(N, -1);

    // visited[i] tells whether node i has already been visited
    vector<bool> visited(N, false);

    // parent[i] stores the previous node from which we reached i
    // This will help us reconstruct the shortest path
    vector<int> parent(N, -1);

    // Convert source and destination from 1-based to 0-based
    src--;
    dest--;

    // Queue is used for BFS
    queue<int> q;

    // Start BFS from the source
    visited[src] = true;
    dist[src] = 0;
    q.push(src);

    // ---------------- BFS ----------------
    while(!q.empty()) {

        // Get the first node from the queue
        int node = q.front();
        q.pop();

        // Visit all neighbours of the current node
        for(int i = 0; i < adj[node].size(); i++) {

            int neigh = adj[node][i];

            // If neighbour has not been visited
            if(!visited[neigh]) {

                // Mark it as visited
                visited[neigh] = true;

                // Distance of neighbour is one more than current node
                dist[neigh] = dist[node] + 1;

                // Store current node as the parent of neighbour
                parent[neigh] = node;

                // Add neighbour to the queue
                q.push(neigh);
            }
        }
    }

    // Vector to store the final shortest path
    vector<int> path;

    // If destination was never visited, there is no path
    if(!visited[dest]) {
        return path;
    }

    // -------- Reconstruct the shortest path --------
    // Start from destination and move backwards using parent[]
    while(dest != -1) {

        // Add current node to the path
        path.push_back(dest);

        // Move to its parent
        dest = parent[dest];
    }

    // Currently path is destination -> source
    // Reverse it to get source -> destination
    reverse(path.begin(), path.end());

    // Convert nodes back from 0-based to 1-based
    for(int i = 0; i < path.size(); i++) {
        path[i]++;
    }

    // Return the shortest path
    return path;
}


int main() {

    int N, M;

    // Take number of vertices
    cout << "Enter number of vertices: ";
    cin >> N;

    // Take number of edges
    cout << "Enter number of edges: ";
    cin >> M;

    // Vector to store all edges
    vector<pair<int,int>> edges;

    // Take all edges as input
    cout << "Enter edges:\n";

    for(int i = 0; i < M; i++) {

        int u, v;
        cin >> u >> v;

        // Store the edge (u, v)
        edges.push_back({u, v});
    }

    int src, dest;

    // Take source vertex
    cout << "Enter source: ";
    cin >> src;

    // Take destination vertex
    cout << "Enter destination: ";
    cin >> dest;

    // Find the shortest path
    vector<int> path = shortestPath(edges, N, M, src, dest);

    // If path is empty, destination cannot be reached
    if(path.empty()) {

        cout << "No path exists.\n";
    }
    else {

        cout << "Shortest path: ";

        // Print the shortest path
        for(int i = 0; i < path.size(); i++) {

            cout << path[i];

            // Print arrow between vertices
            if(i != path.size() - 1) {
                cout << " -> ";
            }
        }

        cout << endl;
    }

    return 0;
}