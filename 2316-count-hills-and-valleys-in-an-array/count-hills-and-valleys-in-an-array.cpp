class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n =  nums.size();
        int left = nums[0];
        int cnt = 0;
        for(int i=1;i<n-1;i++){
            // if(nums[i] == nums[i+1]) continue;
            // //if it a hill
            // else if(nums[i] != nums[i+1] && nums[i]>nums[i+1] && nums[i]>nums[i-1]) cnt++;
            // else if(nums[i]<nums[i+1]) cnt++;
            if(nums[i]>left && nums[i]>nums[i+1] || nums[i]<left && nums[i]<nums[i+1]){
                cnt++;
                left = nums[i];
            }
        }
        return cnt;
    }
};