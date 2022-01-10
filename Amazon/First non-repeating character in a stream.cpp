// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans;
		    unordered_map<char,int> mp;
		    queue<char> st;
		    for(auto c : A){
		        mp[c]++;
		        if(mp[c] == 1) st.push(c);
		        while(!st.empty() && mp[st.front()] > 1){
		            st.pop();
		        }
		        if(!st.empty()) ans += st.front();
		        else ans += "#";
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
