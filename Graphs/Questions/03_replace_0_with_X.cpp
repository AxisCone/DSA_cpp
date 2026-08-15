#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<char>> solve(vector<vector<char>> matrix){
    int r = matrix.size();
    int c = matrix[0].size();

    queue<pair<int,int>> q;

    // first row
    for(int i = 0; i < c; i++){
        if(matrix[0][i] == 'O'){
            q.push({0, i});
            matrix[0][i] = 'T';
        }
    }

    // first column
    for(int i = 1; i < r; i++){
        if(matrix[i][0] == 'O'){
            q.push({i, 0});
            matrix[i][0] = 'T';        
        }
    }

    // last row
    if(r > 1){
        for(int i = 1; i < c; i++){
            if(matrix[r-1][i] == 'O'){
                q.push({r-1, i});
                matrix[r-1][i] = 'T';
            }
        }
    }

    // last column
    if(c > 1){
        for(int i = 1; i < r-1; i++){
            if(matrix[i][c-1] == 'O'){
                q.push({i, c-1});
                matrix[i][c-1] = 'T';
            }
        }
    }

    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    // BFS from all border 'O's
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for(int k = 0; k < 4; k++){
            int ni = i + row[k];
            int nj = j + col[k];

            if(ni >= 0 && ni < r && nj >= 0 && nj < c && matrix[ni][nj] == 'O'){ // fixed: was '0'
                matrix[ni][nj] = 'T';   // fixed: was ==
                q.push({ni, nj});
            }
        }
    }

    // Replace all remaining 'O' with 'X' (surrounded)
    // Replace all 'T' with 'O' (border-connected, restore)
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(matrix[i][j] == 'O'){
                matrix[i][j] = 'X';     // fixed: was ==
            }
            else if(matrix[i][j] == 'T'){
                matrix[i][j] = 'O';     // fixed: was ==
            }
        }
    }

    return matrix;
}

void printMatrix(vector<vector<char>> matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    vector<vector<char>> matrix = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    vector<vector<char>> result = solve(matrix);

    cout << "\nAfter filling surrounded regions:\n";
    printMatrix(result);

    return 0;
}