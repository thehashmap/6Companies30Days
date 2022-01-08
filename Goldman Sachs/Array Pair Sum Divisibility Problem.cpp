// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();

        if (n % 2 != 0)
        {
            return false;
        }

        unordered_map<int, int> m;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            int rem = nums[i] % k;

            if (rem == 0)
            {
                if (m.find(0) != m.end() && m[0] > 0)
                {
                    count++;
                    m[0]--;
                    m[0]--;
                }
            }
            else
            {
                int val = k - rem;

                if (m.find(val) != m.end() && m[val] > 0)
                {
                    count++;
                    m[rem]--;
                    m[val]--;
                }
            }
            m[rem]++;
        }

        if (count == n / 2)
        {
            return true;
        }

        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends
