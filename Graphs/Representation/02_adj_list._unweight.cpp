#include<iostream>
#include<vector>
using namespace std;

int main(){
    int vertices,edges;
    cout<<"Enter n.o of vertices: ";
    cin>>vertices;
    cout<<"Enter n.o of edges: ";
    cin>>edges;

    vector<vector<int>>AdjList(vertices);

    int u,v;
    cout<<"Enter connected vertices: ";

    for(int i=0;i<edges;i++){
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    for(int i=0;i<vertices;i++){
        cout<<i<<"->";
        for(int j=0;j<AdjList[i].size();j++){
            cout<<AdjList[i][j]<<" ";
        }
            cout<<endl;
    }
}