#include<iostream>
#include<vector>
using namespace std;

int main(){
    int vertices,edges;
    cout<<"Enter n.o of vertices: ";
    cin>>vertices;
    cout<<"Enter n.o of edges: ";
    cin>>edges;

    vector<vector<pair<int,int>>> AdjList(vertices);

    int u,v,w;
    cout<<"Enter connected vertices(with weights): ";

    for(int i=0;i<edges;i++){
        cin>>u>>v>>w;
        AdjList[u].push_back(make_pair(v,w)); // methood 1
        AdjList[v].push_back({u,w});   // methood 2(recommended)
    }

    for(int i = 0; i < vertices; i++) {
    cout << i << " -> ";
    for(int j = 0; j < AdjList[i].size(); j++) {
        cout << "("
             << AdjList[i][j].first << ", "
             << AdjList[i][j].second
             << ") ";
    }
    cout << endl;
}


}