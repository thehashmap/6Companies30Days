// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *ans = new int[2];

        set<int> s;
        int duc = -1;
        for (int i = 0; i < n; i++)
        {
            if (s.find(arr[i]) != s.end())
            {
                duc = arr[i];
            }
    
            s.insert(arr[i]);
        }
    
        int miss = -1;
        for (int i = 1; i <= n; i++)
        {
            if (s.find(i) == s.end())
            {
                miss = i;
                break;
            }
        }
        ans[0] = duc;
        ans[1] = miss;
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
