class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int INF = 2147483647;
        queue<pair<int, int>> q;
        map<pair<int, int>, bool> visited;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            int sz = q.size();
            for(int k = 0; k < sz; k++){
                auto [i, j] = q.front(); q.pop();

                // Go Up
                if(i-1 >= 0 && grid[i-1][j] == INF && !visited[{i-1, j}]){
                    visited[{i-1, j}] = true;
                    q.push({i-1, j});
                    grid[i-1][j] = grid[i][j] + 1;
                }

                // Go down
                if(i+1 < grid.size() && grid[i+1][j] == INF && !visited[{i+1, j}]){
                    visited[{i+1, j}] = true;
                    q.push({i+1, j});
                    grid[i+1][j] = grid[i][j] + 1;
                }

                // Go right
                if(j+1 < grid[i].size() && grid[i][j+1] == INF && !visited[{i, j+1}]){
                    visited[{i, j+1}] = true;
                    q.push({i, j+1});
                    grid[i][j+1] = grid[i][j] + 1;
                }

                // Go left
                if(j-1 >= 0 && grid[i][j-1] == INF && !visited[{i, j-1}]){
                    visited[{i, j-1}] = true;
                    q.push({i, j-1});
                    grid[i][j-1] = grid[i][j] + 1;
                }
            }
        }
    }
};
