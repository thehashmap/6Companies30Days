// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n = board.size(), m = board[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(solve(board, word, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool solve(vector<vector<char>>& board, string word, int pos, int r, int c){
        int n = board.size(), m = board[0].size();
        if(pos >= word.size()) return true;
        if(r >= n || c >= m || r < 0 || c < 0) return false;
        if(word[pos] != board[r][c]) return false;
        char ch = board[r][c];
        board[r][c] = '*';
        bool isFound = solve(board, word, pos + 1, r - 1, c) || solve(board, word,pos + 1, r, c - 1)
        || solve(board, word,pos + 1, r, c + 1) || solve(board, word,pos + 1, r + 1, c);
        board[r][c] = ch;
        return isFound;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
