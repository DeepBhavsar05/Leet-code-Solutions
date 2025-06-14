class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low<=high){
            int mid = (low+high)/2;
            if(nums[low]<= nums[high]){
                mini = min(mini,nums[low]);
                break;//do not need to check further for next halves
            }
            if(nums[low]<=nums[mid]){
                //left-half is sorted
                mini = min(mini,nums[low]);
                low = mid+1;
            }
            else if(nums[mid] <= nums[high]){
                //right-half is sorted
                mini = min(mini,nums[mid]);
                high = mid-1;
            }
        }
        return mini;
    }
};