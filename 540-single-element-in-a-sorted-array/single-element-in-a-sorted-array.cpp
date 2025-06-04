class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //first i will use O(N) approach
        // int n = nums.size();
        //if(n==1) return arr[0];
        // for(int i=0;i<n;i++){
        //     if(i == 0){
        //         if(nums[i] != nums[i+1]) return nums[0];
        //     }
        //     else if(i == n-1){
        //         if(nums[i] != nums[i-1]) return nums[i];
        //     }
        //     else{
        //         if(nums[i] != nums[i-1] && nums[i] != nums[i+1]) return nums[i];
        //     }
        // }
        // return -1;
        int n = nums.size();

        if( n == 1) return nums[0];
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(mid == 0){
                //edge case for starting of the array where it don't have left
                if(nums[mid]!=nums[mid+1]) return nums[mid];
            }
            if(mid == n-1){
                //edge case for ending of the array where it don't have right
                if(nums[mid]!=nums[mid-1]) return nums[mid];
            }
            //now we will check for the mid(pointer) either it is on left or on right
            //first for left--> according to observation we find that (even,odd)-->both are same then
            //we are currently on left side of array and our answer will be on right side so eliminate
            //left side if we couldn't find our answer
            //left side there is 2 posibilities:
            //1. mid(pointer) should on *even index
            //OR
            //2. pointer should on *odd index

            //this is for our answer or single element
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];

            //pointer at left-half
            if(mid%2 == 0 && nums[mid] == nums[mid+1] || mid%2 == 1 && nums[mid] == nums[mid-1]){
                //i am on left side
                //if this condition is fulfilled then answer is not in left side so eliminate this part
                low = mid + 1;
            }

            //pointer at right-half
            else{
                //we are on right
                //if this condition is fulfilled then answer is not in right side so eliminate this
                high = mid-1;
            }
        }
        return -1;
    }
};