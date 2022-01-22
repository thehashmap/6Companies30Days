class Solution {
public:
    bool isValid(vector<int>& weights, int days, int capacity){
        int weight = 0, day = 1;
        for(int i = 0;i<weights.size();i++){
            weight += weights[i];
            if(weight > capacity) {
                day++;
                weight = weights[i];
            }
            if(day > days) return false;
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0 , high = 0;
        for(auto w : weights){
            low = max(w , low);
            high += w;
        }
        while(low < high){
            int mid = low + (high - low)/2;
            if(isValid(weights,days,mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
