class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int n = nums.size();
        int sum = 0;
        int curr_sum =0;
        for(int i=0;i<n;i++){
            sum = sum + nums[i];
        }
        for(int i=0;i<n;i++){
            curr_sum = curr_sum + nums[i];
            ans.push_back(nums[i]);

            int remaining_sum = sum - curr_sum;
            if(curr_sum > remaining_sum){
                break;
            }
        }
        return ans;
    }
};