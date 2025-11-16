class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<vector<int>> seen(m, vector<int>(n, 0));
        
       
        for (auto &g : guards) {
            grid[g[0]][g[1]] = 1;
        }
        
        
        for (auto &w : walls) {
            grid[w[0]][w[1]] = 2;
        }
        
        
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        
        
        for (auto &g : guards) {
            int r = g[0];
            int c = g[1];
            
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                
                // Keep moving in same direction
                while (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    
                    // Stop if we hit a wall or another guard
                    if (grid[nr][nc] == 1 || grid[nr][nc] == 2) 
                        break;
                    
                    
                    seen[nr][nc] = 1;
                    
                    nr += dr[d];
                    nc += dc[d];
                }
            }
        }
        
        
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
        
                if (grid[i][j] == 0 && seen[i][j] == 0) {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};
