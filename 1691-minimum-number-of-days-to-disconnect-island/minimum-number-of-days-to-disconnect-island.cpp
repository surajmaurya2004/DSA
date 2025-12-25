class Solution {
public:
 int n,m;
 vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
 void dfs(int i, int j,vector<vector<int>>& grid, vector<vector<bool>> & vis){
    vis[i][j] = true;
    for(auto &d : dirs){
        int ni = i+d[0];
        int nj = j+d[1];
        if(ni>=0 && nj >= 0 && ni<n && nj<m && grid[ni][nj] == 1 && !vis[ni][nj]){
            dfs(ni,nj,grid,vis);
        }

    }
 }
 int countIslands(vector<vector<int>>& grid){
    vector<vector<bool>> vis(n, vector<bool>(m,false));
    int islands = 0;
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1 && !vis[i][j]){
                islands++;
                dfs(i,j,grid,vis);
            }
        }
    }
    return islands;
 }
    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if(countIslands(grid) != 1)
        return 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    if(countIslands(grid) != 1)
                    return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};