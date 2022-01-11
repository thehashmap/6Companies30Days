class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size() , n = grid[0].size() , tot = 0 , cnt = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2){
                    q.push({i , j});
                }
            }
        }
        int ans = 0;
        int dir[5] = { 0 , 1 , 0 , - 1 , 0 };
        while(!q.empty()){
            int size = q.size();
            cnt += size;
            while(size--){
                auto [i , j] = q.front();
                q.pop();
                for(int l = 0;l<4;l++){
                    int r = i + dir[l] , c = j + dir[l + 1];
                    if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] != 1) continue; 
                    grid[r][c] = 2;
                    q.push({r , c});
                }
            }
            if(!q.empty()) ans++;
        }
        return (tot == cnt) ? ans : -1;
    }
};
