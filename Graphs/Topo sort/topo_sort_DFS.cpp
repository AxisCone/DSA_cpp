#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topo_sort(int node,
               vector<vector<int>>& Adj,
               vector<bool>& visited,
               stack<int>& s) {

    visited[node] = 1;

    for (int i = 0; i < Adj[node].size(); i++) {

        int neighbour = Adj[node][i];

        if (!visited[neighbour]) {
            topo_sort(neighbour, Adj, visited, s);
        }
    }

    s.push(node);
}

vector<int> result(vector<vector<int>>& Adj) {

    stack<int> s;

    vector<bool> visited(Adj.size(), 0);

    for (int i = 0; i < Adj.size(); i++) {

        if (!visited[i]) {
            topo_sort(i, Adj, visited, s);
        }
    }

    vector<int> ans;

    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
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

    vector<int> topo_order = result(Adj);

    cout << "\nTopological Ordering: ";

    for (int i = 0; i < topo_order.size(); i++) {
        cout << topo_order[i] << " ";
    }

    return 0;
}