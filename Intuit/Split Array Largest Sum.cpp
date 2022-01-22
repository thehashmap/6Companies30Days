class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low < high){
            int mid = low + (high - low) / 2;
            if(check(nums, m, mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
    
    bool check(vector<int>& nums, int m, int mid){
        int sum = 0, cnt = 1;
        for(auto n : nums){
            if(sum + n > mid){
                sum = n;
                cnt++;
            }
            else {
                sum += n;
            }
        }
        return cnt <= m;
    }
};
