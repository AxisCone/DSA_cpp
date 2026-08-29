#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

vector<int>Djikstra(int V,vector<vector<pair<int,int>>>&Adj,int src){ 

        vector<bool>explored(V,0);
        vector<int>dist(V,INT_MAX);
        dist[src]=0;

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;  //(MIN-HEAP) lower dist is always on top

        pq.push({0,src});

        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();

            if(explored[node]){  // for ignoring node which is already present 
                continue;        // with mimimum distance   
            }

            explored[node] = 1;

            for(int i=0;i<Adj[node].size();i++){
                int neigh = Adj[node][i].first;
                int weight = Adj[node][i].second;

                if(!explored[neigh] && dist[node]+weight<dist[neigh]){
                    dist[neigh] = dist[node]+weight;
                    pq.push({dist[neigh],neigh});
                }
            }
        }

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

        vector<int>dist = Djikstra(V,Adj,0);

        cout<<"Shortest dist from source node: ";
        for(int i=0;i<dist.size();i++){
            cout<<i<<"->"<<dist[i]<<" ";
        }



}