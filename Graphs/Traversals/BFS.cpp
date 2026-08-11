#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>BFS(vector<vector<int>>&Adj){
    int V = Adj.size();

    vector<int>ans;
    vector<bool>visited(V,0);
    queue<int>q;

    q.push(0);
    visited[0]=1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(int i=0;i<Adj[node].size();i++){
            int neigh = Adj[node][i];
            if(!visited[neigh]){
                visited[neigh] = 1;
                q.push(neigh);
            }
        }
    }

    return ans;

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

    vector<int>BFS_traversal = BFS(Adj);

    cout<<"BFS Traversal: "<<endl;
    for(int i=0;i<BFS_traversal.size();i++){
        cout<<BFS_traversal[i]<<" ";
    }

}