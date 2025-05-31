class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //here there is also one solution which is O(N) linear search
        //since it is same as the previous one leetcode: 33, we can use same logic with little tweak in searching algo
        // use this case: [3,1,2,3,3,3,3]--> in this case we can not use that(lc33) logic 
        //why? --> here, nums[low] == nums[mid] == nums[high] so how will algorithm knows that the target lies on sorted part 
        //or unsorted part?
        //for this we have to reduce the search space from both the ends(low,high)
        //low--- low-1 & high-1<--- high
        //(one step -->in<-- from both the ends and continue this process untill we can find either of low and high  unique)
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return true;
            if(nums[low]==nums[mid] && nums[mid]== nums[high]){
                low = low +1;
                high = high-1;
                continue;
            }

            //outer if else only checks that which sub-array is sorted
            //inner if else checks that target is lies inside of any of sub-arrays
            if(nums[low]<= nums[mid]){
                //means left half is sorted
                //now chceck for the target if it is lies inside/between low-->mid
                if(nums[low]<=target && target<=nums[mid]){
                    high = mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                //means right half is sorted
                //now chceck for the target if it is lies inside/between mid-->high
                if(nums[mid]<=target && target<=nums[high]){
                    low = mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};