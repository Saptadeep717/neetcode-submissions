class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        queue<tuple<int,int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                    vis[i][j]=1;
                } 
            }
        }

        int tm=0;

        while(!q.empty()){
            auto [row,col,time] = q.front();
            q.pop();

            tm = max(tm,time);

            int dx[4] = {-1,0,0,1}, dy[4]={0,1,-1,0};

            for(int k=0; k<4; k++){
                int ni = row+dx[k], nj = col+dy[k];

                if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && grid[ni][nj]==1){
                    q.push({ni,nj,time+1});
                    vis[ni][nj]=1;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]) return -1;
            }
        }
        return tm;
       
    }
};
