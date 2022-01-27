class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
        queue<int> q;
        vector<int> ans;
        vector<int> indegree(n , 0);
        vector<vector<int>> adj(n , vector<int>());
        for(auto p : preq){
           adj[p[1]].push_back(p[0]);
           indegree[p[0]]++;
        }
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            cnt++;
            for(auto u : adj[v]){
                indegree[u]--;
                if(indegree[u] == 0) q.push(u);
            }
            ans.push_back(v);
        }
        if(cnt != n) return {};
        return ans;
    }
};
