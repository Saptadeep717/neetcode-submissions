class Solution {
public:

    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<int>>&vis, int prev, int n, int m ){
        if(i<0 || i>=n || j<0 || j>=m ) return;
        if(vis[i][j] || heights[i][j] < prev) return;
        vis[i][j] = 1;
        int dx[4] = {-1,0,0,1}, dy[4] = {0,-1,1,0};

        for(int k = 0; k<4; k++){
            int ni = i+dx[k], nj= j+dy[k];

            dfs(ni,nj,heights,vis,heights[i][j],n,m);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>>pVis(n, vector<int>(m,0));
        vector<vector<int>>aVis(n, vector<int>(m,0));


        for(int j=0; j<m; j++){
            dfs(0,j,heights,pVis,-1,n,m);
            dfs(n-1,j,heights,aVis,-1,n,m);
        }

        for(int i=0; i<n; i++){
            dfs(i,0,heights,pVis,-1,n,m);
            dfs(i,m-1,heights,aVis,-1,n,m);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pVis[i][j] && aVis[i][j]) ans.push_back({i,j});
            }
        }
        return ans;

    }
};
