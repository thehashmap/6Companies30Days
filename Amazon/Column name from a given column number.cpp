// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int columnNumber)
    {
        // your code here
        string s="";
        while(columnNumber > 0){
            columnNumber--;
            int c = columnNumber%26;
            columnNumber/=26;
            s += char(c+'A');
        }
        reverse(s.begin(),s.end());
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends
