#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // DFS to perform Topological Sort
    void DFS(int node,
             vector<vector<pair<int, int>>> &Adj,
             stack<int> &s1,
             vector<bool> &visited) {

        // Mark current node as visited
        visited[node] = true;

        // Visit all adjacent nodes
        for (int i = 0; i < Adj[node].size(); i++) {

            int neigh = Adj[node][i].first;

            // If neighbour is not visited, visit it
            if (!visited[neigh]) {
                DFS(neigh, Adj, s1, visited);
            }
        }

        // Add node to stack after visiting all its neighbours
        s1.push(node);
    }

    vector<int> shortestPath(int V, vector<vector<int>> &edges) {

        int M = edges.size();

        // --------------------------------------------------
        // STEP 1: Create the adjacency list
        // Adj[u] contains {v, weight}
        // meaning there is an edge u -> v with given weight
        // --------------------------------------------------

        vector<vector<pair<int, int>>> Adj(V);

        for (int i = 0; i < M; i++) {

            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];

            // Directed edge: u -> v
            Adj[u].push_back({v, weight});
        }

        // --------------------------------------------------
        // STEP 2: Find Topological Ordering using DFS
        // --------------------------------------------------

        stack<int> s1;

        vector<bool> visited(V, false);

        // Start DFS from source node 0
        DFS(0, Adj, s1, visited);

        // --------------------------------------------------
        // STEP 3: Initialize distance array
        // --------------------------------------------------

        vector<int> dist(V, INT_MAX);

        // Distance from source (0) to itself is 0
        dist[0] = 0;

        // --------------------------------------------------
        // STEP 4: Process nodes in Topological Order
        // --------------------------------------------------

        while (!s1.empty()) {

            // Get the next node in topological order
            int node = s1.top();
            s1.pop();

            // Relax all outgoing edges of this node
            for (int i = 0; i < Adj[node].size(); i++) {

                int neigh = Adj[node][i].first;
                int weight = Adj[node][i].second;

                // Only calculate if current node is reachable
                if (dist[node] != INT_MAX) {

                    // Relaxation
                    dist[neigh] = min(
                        dist[neigh],
                        dist[node] + weight
                    );
                }
            }
        }

        // --------------------------------------------------
        // STEP 5: Replace unreachable nodes with -1
        // --------------------------------------------------

        for (int i = 0; i < V; i++) {

            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }

        // Return shortest distances from node 0
        return dist;
    }
};


// --------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------

int main() {

    // Number of vertices
    int V = 6;

    // Each edge is {source, destination, weight}
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {1, 2, 3},
        {4, 2, 2},
        {2, 3, 6},
        {4, 5, 4},
        {5, 3, 1}
    };

    Solution obj;

    // Find shortest paths from source node 0
    vector<int> result = obj.shortestPath(V, edges);

    // Print the result
    cout << "Shortest distances from node 0:\n";

    for (int i = 0; i < V; i++) {
        cout << "0 -> " << i << " = " << result[i] << endl;
    }

    return 0;
}