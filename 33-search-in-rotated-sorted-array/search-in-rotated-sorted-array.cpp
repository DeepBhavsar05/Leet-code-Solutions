class Solution {
public:
    int search(vector<int>& nums, int target) {
        //here i can see that they mentioned that array is sorted and we need to do searching
        //binary search is best option for this example
        //brute force approach is coming with O(N) time complexity
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     if(nums[i]==target){
        //         return i;
        //     }
        // }
        // return -1;
        //now for binary search
        //1. apply same binary search logic
        //2. in this case we can not directly eliminate left or right
        //3. we have to check either left or right of mid is sorted
        //4. for that we will easily check from the values of left---> nums[mid]
        //which means if the left sub-array of mid is sorted then 
        //it must be lesser value than nums[mid]: nums[left]<nums[mid]
        //or the nums[mid]------>right
        //which means if the right side sub-array has to be sorted than: nums[mid]<nums[high]
        int n= nums.size();
        int low = 0; int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid]==target) return mid;
            if(nums[low]<= nums[mid]){
                //left sub-array is sorted
                if(nums[low]<=target && target<=nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid+1;
                }

            }
            else{
                //right sub-array is sorted
                if(nums[mid]<=target && target<=nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }

            }
        }
        return -1;
    }
};