// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string s)
{     
  //Your code here 
  string ans;
  int cnt = 1;
  int i;
  for(i = 0;i<s.size()-1;i++){
      if(s[i] == s[i + 1]){
          cnt++;
      }
      else{
          ans += s[i] + to_string(cnt);
          cnt = 1;
      }
  }
  ans += s[i] + to_string(cnt);
  return ans;
}     
 
