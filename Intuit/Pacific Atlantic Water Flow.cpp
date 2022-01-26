class Solution {
public:
    void fill(vector<vector<int>>& g , int r , int c , vector<vector<bool>>& vis){
        if(r < 0 || c < 0 || r >= g.size() || c >= g[0].size() || vis[r][c] == true) return ;
        vis[r][c] = true;
        if(r > 0 && g[r - 1][c] >= g[r][c]) fill(g , r - 1 , c , vis);
        if(c > 0 && g[r][c - 1] >= g[r][c]) fill(g , r , c - 1, vis);
        if(r < g.size() - 1 && g[r + 1][c] >= g[r][c]) fill(g , r + 1 , c , vis);
        if(c < g[0].size() - 1 && g[r][c + 1] >= g[r][c]) fill(g , r , c + 1, vis);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m = h.size() , n = h[0].size();
        vector<vector<bool>> pacific(m , vector<bool>(n , false));
        vector<vector<bool>> atlantic(m , vector<bool>(n , false));
        for(int i = 0;i<m;i++){
            fill(h , i , 0 , pacific);
            fill(h , i , n - 1 , atlantic);
        }
        for(int j = 0;j<n;j++){
            fill(h , 0 , j , pacific);
            fill(h , m - 1 , j , atlantic);
        }
        vector<vector<int>> ans;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i , j});
            }
        }
        return ans;
    }
};
