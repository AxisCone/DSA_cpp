#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void DFS(int node,vector<vector<int>>&Adj,vector<bool>&visited,vector<int>&ans){
    int V = Adj.size();

    visited[node] = 1;
    ans.push_back(node);

    for(int i=0;i<Adj[node].size();i++){
        if(!visited[Adj[node][i]]){
            DFS(Adj[node][i],Adj,visited,ans);
        }
    }


}


int main(){
    int vertices,edges;
    cout<<"Enter number of vertices: ";
    cin>>vertices;
    cout<<"Enter number of edges: ";
    cin>>edges;

    vector<vector<int>>Adj(vertices);
    

    int u,v;
    cout<<"Enter the structure of graph: ";
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    for(int i=0;i<vertices;i++){
        cout<<i<<"-> ";
        for(int j=0;j<Adj[i].size();j++){
            cout<<Adj[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<int>ans;
    vector<bool>visited(vertices,0);

    for(int i=0;i<vertices;i++){
        if(!visited[i]){
            DFS(i,Adj,visited,ans);
        }
    }

    cout<<"DFS Traversal: "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}