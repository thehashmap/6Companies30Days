// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        int r[9][9], c[9][9], s[3][3][9];
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        memset(s, 0, sizeof(s));
        int number;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (mat[i][j] > 0 && mat[i][j] <= 9) {
                    number = mat[i][j] - 1;
                    if (r[i][number]) 
                        return 0;
                    r[i][number] = 1;
                    if (c[j][number]) 
                        return 0;
                    c[j][number] = 1;
                    // checking if same box have repeated value except for 0
                    if (s[i / 3][j / 3][number]) 
                        return 0;
                    s[i / 3][j / 3][number] = 1;
                }
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
