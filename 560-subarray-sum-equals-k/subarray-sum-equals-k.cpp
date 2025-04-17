class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //this one is brute force solution O(N^2)
        // int n = nums.size();
        // int count =0;
        // for(int i=0;i<n;i++){
        //     int sum =0;
        //     for(int j=i;j<n;j++){
        //         sum += nums[j];
        //         if(sum == k) count++;
        //     }
        // }
        // return count;
        int n = nums.size();
        int preSum = 0;
        int count = 0;
        map<int,int> mpp;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            preSum += nums[i];//adding elements to presum and next adding their counts in value pair in hash
            int remove = preSum - k;// if there is remove then there must be preSum in *hash or array*
            count = count + mpp[remove];//here I am adding +1 in counter where mpp[remove] is key and counter is it's value e.g. mpp[remove]---> count => key-->value pair
            mpp[preSum] +=1;// then I will increase count value of preSum in hash map
        }
        return count;

    }
};