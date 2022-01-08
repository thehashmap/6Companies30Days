// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<char> st;

        string res = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ']')
            {
                string k = "";
                while (!st.empty() && st.top() != '[')
                {
                    k = st.top() + k;
                    st.pop();
                }

                st.pop();

                string num = "";
                while (!st.empty() && st.top() >= 48 && st.top() <= 57)
                {
                    num = st.top() + num;
                    st.pop();
                }

                int n = stoi(num);

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < k.length(); j++)
                    {
                        st.push(k[j]);
                    }
                }
            }
            else
            {
                st.push(s[i]);
            }
        }

        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
