// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
  
    bool subsetsum(int arr[] , int n , int sum){
        bool dp[n + 1][sum + 1];
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=sum;j++){
                if(i == 0) dp[i][j] = false;
                if(j == 0) dp[i][j] = true;
                
            }
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=sum;j++){
                if(arr[i - 1] <= j) dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
    
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    if(n == 1) return arr[0];
	    int sum = 0;
	    for(int i = 0;i<n;i++) sum += arr[i];
	   // if(sum % 2 == 0) return 0;
	    int ans = sum;
	    for(int i = sum / 2;i >= 0;i--){
	        if(subsetsum(arr , n , i)) {
	            ans = (sum - i) - i;
	            break;
	        }
	    }
	    return ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
