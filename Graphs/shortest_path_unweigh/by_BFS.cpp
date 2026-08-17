#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {

    // Create adjacency list
    vector<vector<int>> adj(V);

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Distance array
    vector<int> dist(V, -1);

    // Visited array
    vector<bool> visited(V, false);

    queue<int> q;

    visited[src] = true;
    dist[src] = 0;
    q.push(src);

    // BFS
    while(!q.empty()) {

        int node = q.front();
        q.pop();

        for(int i = 0; i < adj[node].size(); i++) {

            int neigh = adj[node][i];

            if(!visited[neigh]) {

                visited[neigh] = true;

                dist[neigh] = dist[node] + 1;

                q.push(neigh);
            }
        }
    }

    return dist[dest];
}

int main() {

    int V = 6;

    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 3},
        {3, 4},
        {4, 5}
    };

    int src = 0;
    int dest = 5;

    cout << shortestPath(V, edges, src, dest);

    return 0;
}