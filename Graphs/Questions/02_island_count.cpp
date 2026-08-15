#include <bits/stdc++.h>
using namespace std;

int countIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;

    int r = grid.size();
    int c = grid[0].size();

    queue<pair<int,int>> q;
    int count = 0;

    int row[8] = {-1,-1,-1,1,1,1,0,0};
    int col[8] = {-1,0,1,-1,0,1,-1,1};

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {

            // Start BFS only when we find an unvisited island cell
            if (grid[i][j] == 'L') {

                count++;

                grid[i][j] = 'W';
                q.push({i, j});

                while (!q.empty()) {

                    int ni = q.front().first;
                    int nj = q.front().second;
                    q.pop();

                    for (int k = 0; k < 8; k++) {

                        int new_i = ni + row[k];
                        int new_j = nj + col[k];

                        if (new_i >= 0 && new_i < r &&
                            new_j >= 0 && new_j < c &&
                            grid[new_i][new_j] == 'L') {

                            grid[new_i][new_j] = 'W';
                            q.push({new_i, new_j});
                        }
                    }
                }
            }
        }
    }

    return count;
}

int main() {
    // Example grid: 'L' = Land, 'W' = Water
    vector<vector<char>> grid = {
        {'L','L','W','W','W'},
        {'L','W','W','L','L'},
        {'W','W','L','L','W'},
        {'W','W','W','W','W'},
        {'L','W','L','W','L'}
    };

    int result = countIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}