// Given a Carton mat[][], where each cell in the Carton can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell
// 1 : Cell have fresh oranges
// 2 : Cell have rotten oranges

// Determine the minimum time required so that all the oranges become rotten. A rotten orange at index (i, j) can rot other fresh orange at indexes (i-1, j), (i+1, j), (i, j-1), (i, j+1) (up, down, left and right) in a unit time.

// Note: If it is impossible to rot every orange then simply return -1.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int unit_time(vector<vector<int>>& Carton){

    int r = Carton.size();
    int c = Carton[0].size();

    queue<pair<int,int>> q;

    // Push all initially rotten oranges
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(Carton[i][j] == 2){
                q.push({i,j});
            }
        }
    }

    int timer = 0;

    while(!q.empty()){

        timer++;

        // Process only the oranges present at the
        // beginning of this time unit
        int rot_orange = q.size();

        while(rot_orange--){

            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            // 4 directions
            int row[4] = {-1, 1, 0, 0};
            int col[4] = {0, 0, -1, 1};

            for(int k = 0; k < 4; k++){

                int ni = i + row[k];
                int nj = j + col[k];

                // Check boundaries and fresh orange
                if(ni >= 0 && ni < r &&
                   nj >= 0 && nj < c &&
                   Carton[ni][nj] == 1){

                    Carton[ni][nj] = 2;
                    q.push({ni,nj});
                }
            }
        }
    }

    // Check if any fresh orange remains
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(Carton[i][j] == 1){
                return -1;
            }
        }
    }

    return timer - 1;
}


int main(){
    int rows,columns;
    cout<<"Enter n.o of rows: ";
    cin>>rows;
    cout<<"Enter n.o of columns: ";
    cin>>columns;

    vector<vector<int>>Carton(rows,vector<int>(columns));

    cout<<"Placed oranges in boxes(2->rotten , 1->fine , 0->empty)";
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cin>>Carton[i][j];
        }
    }

    int time = unit_time(Carton);

    if(time==-1){
        cout<<"Impossible to rot all oranges";
    }
    else{
        cout<<"All Oranges rotten in "<<time<<" unit time";
    }
}
