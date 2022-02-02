// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        vector<vector<int>> dp(a + 1 , vector<int> (b + 1, -1));
        return solve(a - 1, b - 1, dp);
    }
    
    int solve(int a, int b, vector<vector<int>>& dp){
        if(a < 0 || b < 0) return dp[a][b] = 0;
        if(a == 0 || b == 0) return dp[a][b] = 1;
        if(dp[a][b] != -1) return dp[a][b];
        return dp[a][b] = solve(a - 1, b, dp) + solve(a, b - 1, dp);
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends
