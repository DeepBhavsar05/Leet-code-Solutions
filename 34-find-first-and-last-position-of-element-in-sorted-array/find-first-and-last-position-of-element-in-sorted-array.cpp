class Solution {
public:
    int lb(vector<int>& nums,int target,int n){
        //implementation of lower bound
        int low = 0;
        int high = n-1;
        int first = -1;

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid] == target){
                first = mid;
                high = mid-1;//move left
            }
            else if(nums[mid]<target){
                //mid value is smaller so i have to go on right to find targeted value
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return first;
    }
    int ub(vector<int>& nums,int target,int n){
        //implementation of upper bound
        int low = 0;
        int high = n-1;
        int last = -1;

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid] == target){
                last = mid;
                low = mid+1;//move right
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return last;
    }
    // pair<int,int> firstLast(vector<int>& nums,int target,int n){
    //     int first = lb(nums,target,n);
    //     if(first == -1) return {-1,-1};
    //     int last = ub(nums,target,n);
    //     return {first,last};
    // }

    vector<int> searchRange(vector<int>& nums, int target) {
        //first I will write my code for brute force O(N)
        // int first = -1;
        // int last = -1;
        int n = nums.size();
        // for(int i =0;i<n;i++){
        //     if(nums[i] == target){
        //         if(first == -1) first = i;
        //         last = i;
        //     }
        // }
        // return{first,last};
        //here i will use lower bound and upper bound concept for logn solution
        //returning values of first and last from firstLast() fun
        int first = lb(nums,target,n);
        if(first == -1) return {-1,-1};
        int last = ub(nums,target,n);
        return {first,last};
    }
};