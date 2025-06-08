class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //int n = nums.size();
        // TC : O(N)
        //if the array only has 1 element so it will be ---> -infi< 1 element> -infi
        // if( n == 1) return nums[0];
        // //edge case 1: -infi <if nums[0]> nums[1] 
        // if(nums[0] > nums[1]) return nums[0];
        // //edge case 2:  nums[n-2] <nums[n-1]> - infi
        // if(nums[n-1]>nums[n-2]) return nums[n-1];
        // //starting from i = 1 to n-2
        // int low = 1;
        // int high = n-2;
        // for(int i=0;i<n;i++){
        //     if(i == 0 && nums[i]> nums[i+1] ) return 0;
        //     // here I did seperate checking for edge cases
        //     else if(i == n-1 && nums[i]> nums[i-1] ) return i;
        //     //here I check for i is grater than 0 and less than n-1 then only
        //     // check for the condition for rest of the values
        //     else if(i>0 && i<n-1 && nums[i-1]<nums[i] && nums[i]>nums[i+1]) return i;
        // }
        // return -1;

        //lets optimize it for TC: logN solution
        // just think the left and right cases from where the peak element divid the array
        // Think this in graph ---> either the peak is left of the current mid or may be on right
        //using binary search:
        // first we should use our logic for edge cases
        int n = nums.size();
        if(n==1) return 0;
        if( nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        int low = 1;
        int high = n-2;
        while(low<=high){
            int mid = (low+high)/2;
            // if mid value is our answer
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            // if mid is at left side --> nums[mid]>nums[mid-1] then its in increasing curve on graph
            // so our posibilty is on right side for peak element
            if(nums[mid] >nums[mid-1]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    return -1;
    }
};