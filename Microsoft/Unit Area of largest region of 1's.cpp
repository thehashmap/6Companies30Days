// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    int area(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& vis){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || vis[r][c] == true ||
        grid[r][c] == 0){
            return 0;
        }    
        vis[r][c] = true;
        return 1 + area(grid, r - 1, c, vis) + area(grid, r + 1, c, vis) + area(grid, r, c - 1, vis)
        + area(grid, r, c + 1, vis) + area(grid, r - 1, c - 1, vis) + area(grid, r - 1, c + 1, vis)
        + area(grid, r + 1, c - 1, vis) + area(grid, r + 1, c + 1, vis);
    }
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int ans = 0;
        int n = grid.size() , m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool> (m, false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                ans = max(ans , area(grid, i, j, vis));
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
