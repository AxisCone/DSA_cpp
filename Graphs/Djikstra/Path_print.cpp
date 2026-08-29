#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> Djikstra(
    int V,
    vector<vector<pair<int, int>>>& Adj,
    int src,
    int destination
) {
    vector<bool> explored(V, 0);
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);

    dist[src] = 0;

    // Min-heap: {distance, node}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    pq.push({0, src});

    while (!pq.empty()) {

        int node = pq.top().second;
        pq.pop();

        if (explored[node]) {
            continue;
        }

        explored[node] = 1;

        // We can stop once destination is finalized
        if (node == destination) {
            break;
        }

        for (int i = 0; i < Adj[node].size(); i++) {

            int neigh = Adj[node][i].first;
            int weight = Adj[node][i].second;

            if (!explored[neigh] &&
                dist[node] + weight < dist[neigh]) {

                dist[neigh] = dist[node] + weight;

                // Store where we came from
                parent[neigh] = node;

                pq.push({dist[neigh], neigh});
            }
        }
    }

    // No path exists
    if (dist[destination] == INT_MAX) {
        cout << "No path exists from "
             << src << " to " << destination << endl;

        return {};
    }

    // Print shortest distance
    cout << "Shortest distance from "
         << src << " to " << destination
         << " = " << dist[destination] << endl;

    // Construct path
    vector<int> path;

    int current = destination;

    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    // Print path
    cout << "Path: ";

    for (int i = 0; i < path.size(); i++) {
        cout << path[i];

        if (i != path.size() - 1) {
            cout << " -> ";
        }
    }

    cout << endl;

    return dist;
}


int main(){

    int V,E;
    cout<<"Enter n.o of vertices: ";
    cin>>V;

    cout<<"Enter n,o of Edges: ";
    cin>>E;

    vector<vector<pair<int,int>>>Adj(V);

    int u,v,w;
    cout<<"Enter edges and their weight: ";
    for(int i=0;i<E;i++){
        cin>>u>>v>>w;
        Adj[u].push_back({v,w});
        Adj[v].push_back({u,w});
    }

    for(int i=0;i<V;i++){
        cout<<i<<"-> ";
        for(int j=0;j<Adj[i].size();i++){
            cout << "("
             << Adj[i][j].first << ", "
             << Adj[i][j].second
             << ") ";
    }
        cout << endl;
        }

        int dest;
        cout<<"Enter destination node: ";
        cin>>dest;

        vector<int>dist = Djikstra(V,Adj,0,dest);

        cout<<"Shortest dist from source node: ";
        for(int i=0;i<dist.size();i++){
            cout<<i<<"->"<<dist[i]<<" ";
        }



}