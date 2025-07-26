// this question is same as painter's patitions in BS on answers
class Solution {
public:
    bool fun(vector<int>& nums, int k, int maxSumAllowed){
        int current_sum = 0;
        int count = 1;// it means that we have start checking with k=1
        for(int i=0;i<nums.size();i++){
            current_sum = current_sum + nums[i];// here if new element comes and exceeded the mid value then we will start next current_sum from there and increase the value of count or k
            if(current_sum<=maxSumAllowed) continue;
            else{
                current_sum = nums[i];
                count++;
            }
        }
        if(count <= k) return true;
        else return false;
    }

    int splitArray(vector<int>& nums, int k)
    {
    //     int n = nums.size();
    //     // here we have to find largest sum 
    //     // from every posibilities, we have to find minimum value of maximum
    //     //min(max)
    //     // if we have infinite subarrays and and k=1 then my maximum split answer should be total of given nums in given array, here total = 32
    //     // if k=5 then maximum should be largest in given array here,largest in array = 10
    //     int low = *max_element(nums.begin(),nums.end());
    //     int high = accumulate(nums.begin(),nums.end(), 0);

    //     for(int i=low; i<=high;i++){
            
    //         int currentTotal = 0;
    //         int count = 1;
    //         for(int j=0;j<n;j++){
    //             currentTotal = currentTotal + nums[j];
            
    //             if(currentTotal <= i) continue;
    //             else{
    //                 currentTotal = nums[j];
    //                 count++;// will keep track of k's value
    //             }
    //         }
    //         if(count <= k) return i;
    //     }
    //     return -1;
    // }
    //now using binary search
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(), 0);
        int ans = -1;

        while(low<=high){
            int mid = (low+high)/2;
            
            bool isSplitPossible = fun(nums,k,mid);

            if(isSplitPossible == true){
                ans = mid; // might be our answer but we will look for smaller then this
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};