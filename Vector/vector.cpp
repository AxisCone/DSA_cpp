#include<iostream>
#include<vector>
using namespace std;

int main(){

vector<int>arr(5,0);

for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";
}

    cout<<endl;


int vertex = 5;
vector<vector<bool>>Adj(vertex,vector<bool>(vertex,0));
//    <<data type >>name(size ,what each row will contain)

for(int i=0;i<Adj.size();i++){
    for(int j=0;j<Adj.size();j++){
        cout<<Adj[i][j]<<" ";
    }
        cout<<endl;
}

}