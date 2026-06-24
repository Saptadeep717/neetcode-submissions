class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>&visited, int n, int m){
        visited[i][j] = true;

        int dx[4] = {-1,0,0,+1}, dy[4] = {0,-1,+1,0};

        for(int k = 0; k<4; k++){
            int ni = i+dx[k], nj= j+dy[k];

            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]=='1' && visited[ni][nj]==false){
                dfs(grid,ni,nj,visited,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m,false));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0; j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==false){
                    dfs(grid, i,j, visited,n ,m);
                    ans++;
                }
            }
        }
        return ans;
    }
};
