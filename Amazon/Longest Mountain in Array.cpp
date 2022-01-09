class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size() < 3) return 0;
        int start = 0 , end = 0, ans = 0, n = arr.size();
        while(start < n){
            end = start;
            if(end + 1 < n && arr[end] < arr[end + 1]) {
                while(end + 1 < n && arr[end] < arr[end + 1]) end++;
                if(end + 1 < n && arr[end] > arr[end + 1]){
                    while(end + 1 < n && arr[end] > arr[end + 1]) end++;
                    ans = max(ans , end - start + 1);
                }
            }
            start = max(start + 1, end);
        }
        return ans;
    }
};
