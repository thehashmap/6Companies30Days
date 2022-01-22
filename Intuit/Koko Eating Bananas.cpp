class Solution {
public:
    bool isFeasible(vector<int>& piles , int h , int k){
        int hours = 0;
        for(auto banana : piles) hours += (banana-1)/k+1;
        return hours <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        long sum = 0 ;
        for(auto banana : piles){
            sum+= banana;
        }
        // search space : (((sum-1)/h)+1,sum);
        long left = ((sum-1)/h)+1;
        long right = sum;
        while(left < right){
            long mid = left + (right - left)/2;
            if(isFeasible(piles,h,mid)) right = mid;
            else left = mid+1;
        }
        return (int)left;
    }
};
