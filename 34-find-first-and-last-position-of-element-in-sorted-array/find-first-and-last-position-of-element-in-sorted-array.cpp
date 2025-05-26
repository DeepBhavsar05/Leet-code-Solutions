class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //first I will write my code for brute force O(N)
        int first = -1;
        int last = -1;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(nums[i] == target){
                if(first == -1) first = i;
                last = i;
                // return {first,last};
            }
        }
        return{first,last};
    }
};