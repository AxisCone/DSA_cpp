#include<iostream>
#include<vector>
using namespace std;

int main(){
    int vertex,edges;
    cout<<"Enter n.o of vertices: ";
    cin>>vertex;
    cout<<"Enter n.o of edges: ";
    cin>>edges;

    vector<vector<bool>>AdjMat(vertex,vector<bool>(vertex,0));

    int u,v;
    
    cout<<"Enter connected vertices: ";
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        AdjMat[u][v] = 1;
        AdjMat[v][u] = 1;
    }

    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout<<AdjMat[i][j]<<" ";
        }
        cout<<endl;
    }

}