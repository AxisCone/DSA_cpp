#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// Performs topological sort using Kahn's Algorithm (BFS-based approach)
// Adj: adjacency list representation of a Directed Acyclic Graph (DAG)
//      Adj[i] contains all nodes that node i points to (i -> Adj[i][j])
vector<int> topo_sort(vector<vector<int>> &Adj) {
    int V = Adj.size();          // total number of vertices
    vector<int> Indeg(V, 0);     // Indeg[i] = number of incoming edges to node i

    // -------- Step 1: Calculate in-degree of every node --------
    // For every edge (i -> Adj[i][j]), increment the in-degree of the destination node
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < Adj[i].size(); j++) {
            Indeg[Adj[i][j]]++;
        }
    }

    // -------- Step 2: Push all nodes with in-degree 0 into the queue --------
    // These are the nodes with no dependencies, so they can come first in the ordering
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (!Indeg[i]) {
            q.push(i);
        }
    }

    vector<int> ans;   // will store the final topological order

    // -------- Step 3: Standard BFS using the queue --------
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);   // this node is finalized in the topological order

        // "Remove" this node from the graph by decreasing in-degree of its neighbors
        for (int i = 0; i < Adj[node].size(); i++) {
            Indeg[Adj[node][i]]--;

            // If a neighbor's in-degree becomes 0, all its dependencies are
            // satisfied, so it can now be added to the queue
            if (Indeg[Adj[node][i]] == 0) {
                q.push(Adj[node][i]);   // FIXED: push the actual node, not a bool
            }
        }
    }

    // If ans.size() < V at this point, the graph has a cycle
    // (not handled here, but useful to remember)
    return ans;
}


int main() {

    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    // Adjacency list: Adj[i] = list of nodes that i has a directed edge to
    vector<vector<int>> Adj(vertices);

    int u, v;

    cout << "Enter the edges (u v): " << endl;

    // Read all edges and build the adjacency list
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;

        // Directed graph: edge goes from u -> v only (not v -> u)
        Adj[u].push_back(v);
    }

    // Print adjacency list for verification
    cout << "\nAdjacency List:\n";

    for (int i = 0; i < vertices; i++) {

        cout << i << " -> ";

        for (int j = 0; j < Adj[i].size(); j++) {
            cout << Adj[i][j] << " ";
        }

        cout << endl;
    }

    cout << "Topological Order by kahn algo(BFS): ";

    // Run Kahn's algorithm to get one valid topological ordering
    vector<int> ans = topo_sort(Adj);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}