class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low<=high){
            int mid = (low+high)/2;
            if(nums[low]< nums[high]){
                // why = is not in consideration here
                //because it gives wrong answer for this: [3,4,1,2,3]
                //just for little optimization
                mini = min(mini,nums[low]);
                break;//do not need to check further for next halves
            }
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                //cases like [1] low,mid,high could be same so thats why 
                //we will check low --->mid--->high
                mini = min(mini, nums[low]);
                low = low+1;
                high = high -1;
                //continue;
            }
            else if(nums[low]<=nums[mid]){
                //left-half is sorted
                //why we use else if here?
                //because if i use 'if' here then for the case such as [1]
                //might go here for consideration
                //even it takes mini = 1 
                //it will increase the value of low ---> low+1 
                //which would be wrong for [1]
                mini = min(mini,nums[low]);
                low = mid+1;
            }
            else if(nums[mid] <= nums[high]){
                //right-half is sorted
                mini = min(mini,nums[mid]);
                high = mid;
            }
        }
        return mini;
    }
};