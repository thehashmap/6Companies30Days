// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        // code here 
        stack<int> st;
        string res = "";
        for (int i = 0; i <= s.length(); i++)
        {
            st.push(i + 1);

            if (i == s.length() || s[i] == 'I')
            {

                while (!st.empty())
                {
                    int k = st.top();
                    st.pop();
                    res += to_string(k);
                }
            }
        }
        return res;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
