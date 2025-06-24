class Solution {
public:
    long long fun(vector<int>& piles, int atAtimeBanana){
        long long totalTime = 0;
        for(int i = 0;i < piles.size();i++){
            totalTime = totalTime + (long long)(ceil(double(piles[i])/double(atAtimeBanana)));
            // totalTime is a value which will give us
            // total of bananas per given hour 
        }
        return totalTime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(),piles.end());
        int low = 1;
        int high = maxi;
        int ans = INT_MAX;
        while(low<=high){
            int mid = low+(high-low)/2;
            long long TotalperHrBanana = fun(piles,mid);
            if(TotalperHrBanana<=h){
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};