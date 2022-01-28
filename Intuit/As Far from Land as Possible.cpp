class Solution {
public:
    void dfs(vector<vector<int>>& grid , int r , int c , int dist){
        int n = grid.size() , m = grid[0].size();
        if(r < 0 || c < 0 || r >= n || c >= m || (grid[r][c] != 0 && grid[r][c] <= dist)) return ;
        grid[r][c] = dist;
        dfs(grid , r - 1 , c , dist + 1);
        dfs(grid , r + 1 , c , dist + 1);
        dfs(grid , r , c - 1 , dist + 1);
        dfs(grid , r , c + 1 , dist + 1);
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int ans = -1 , cnt = 0;
        int n = grid.size() , m = grid[0].size();
        //BFS
//         queue<pair<int,int>>q;
//         vector<vector<int>> dist(n , vector<int>(m , INT_MAX));
//         for(int i = 0;i<grid.size();i++){
//             for(int j = 0;j<grid[0].size();j++){
//                 if(grid[i][j] == 1){
//                     q.push({i , j});
//                     dist[i][j] = 0;
//                 }
//             }
//         }
        
//         if(q.empty() || q.size() == n * m) return -1;
//         int dir[] = {0 , 1 , 0 , -1 , 0};
//         int d = 0;
//         while(!q.empty()){
//             int x = q.front().first;
//             int y = q.front().second;
//             d++;
//             for(int i = 0;i<4;i++){
//                 int r = x + dir[i] , c = y + dir[i + 1];
//                 if(r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 1) continue;
//                 dist[r][c] = min(dist[r][c] , d);
//                 q.push({r , c});
//             }
//         }
//         for(int i = 0;i<n;i++){
//             for(int j = 0;j<m;j++){
//                 ans = max(ans , dist[i][j]);
//             }
//         }
//         return ans;
        
        //DFS
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    dfs(grid , i , j , 1);
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] > 1) ans = max(ans , grid[i][j] - 1);
            }
        }
        return ans;
    }
};
