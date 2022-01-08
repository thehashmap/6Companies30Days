class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX , n = nums.size();
        int left = 0 , right = 0 , res = 0;
        int sum = accumulate(nums.begin() , nums.end() , 0);
        if(sum < target) return 0;
        while(left < n && right < n){
            res += nums[right];
            if(res >= target){
                ans = min(ans , right - left + 1);
                while(res >= target){
                    ans = min(ans , right - left + 1);
                    res -= nums[left];
                    left++;
                }
            }
            right++;
        }
        return ans;
    }
};
