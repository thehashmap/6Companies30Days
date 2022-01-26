class Solution {
public:
    void dfs(vector<vector<int>>& c , int i , vector<bool>& vis){
        vis[i] = true;
        for(int j = 0;j<vis.size();j++){
            if(i != j && c[i][j] == 1 && !vis[j]) dfs(c , j , vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& c) {
        int n = c.size();
        int ans = 0;
        vector<bool> vis(n , false);
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(c , i , vis);
            }
        }
        return ans;
    }
};
