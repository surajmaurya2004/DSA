class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    vector<pair<int,int>> directions = {{-1,1}, {0,1}, {1,1}};

    int dfs(int row, int col, vector<vector<int>> &grid) {
        
        if (dp[row][col] != -1) return dp[row][col];

        int maxMoves = 0;
        for (auto [dr, dc] : directions) {
            int newRow = row + dr;
            int newCol = col + dc;

            
            if (newRow >= 0 && newRow < m && newCol < n && grid[newRow][newCol] > grid[row][col]) {
                maxMoves = max(maxMoves, 1 + dfs(newRow, newCol, grid));
            }
        }

        dp[row][col] = maxMoves;
        return dp[row][col];
    }

    int maxMoves(vector<vector<int>> &grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<int>(n, -1));

        int result = 0;
        for (int row = 0; row < m; row++) {
            result = max(result, dfs(row, 0, grid));
        }

        return result;
    }
};

