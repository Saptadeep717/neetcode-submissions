class Solution {
public:
 void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>&visited, int n, int m){
        visited[i][j] = true;

        int dx[4] = {-1,0,0,+1}, dy[4] = {0,-1,+1,0};

        for(int k = 0; k<4; k++){
            int ni = i+dx[k], nj= j+dy[k];

            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]=='O' && visited[ni][nj]==false){
                dfs(grid,ni,nj,visited,n,m);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
         int n = board.size(), m = board[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0; j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O' && visited[i][j]==false){
                    dfs(board, i,j, visited,n ,m);
                    
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0; j<m;j++){
                if(board[i][j]=='O' && visited[i][j]==false){
                    board[i][j]='X';
                    
                }
            }
        }
       
    }
};
