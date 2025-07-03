// class Solution {
// public:
//     int smallestDivisor(vector<int>& nums, int threshold) {
//         int n = nums.size();
//         //here we have to find the minimum or small number by dividing the nums
//         //we will get the *total individual sum <= threshold (6 in this case)
//         int maxi = *max_element(nums.begin(),nums.end());
//         for(int d=1;d<=maxi;d++){
    // we can also write this function in seperate function
//             int total = 0;
//             for(int i=0;i<n;i++){
//                 total = total + ceil(double(nums[i])/double(d));// to follow ceil we have to convert
//                 //this value in double
//             }
//             if(total<=threshold) return d;
//         }
//         return -1;
//     }
// };
// now we will use binary search to optimize this solution
class Solution {
public:
    int findTotal(int d,vector<int>& nums,int threshold){
        int n = nums.size();
        int total = 0;
        for(int i=0;i<n;i++){
            total = total + ceil(double(nums[i])/double(d));// to follow ceil we have to convert
            //this value in double
        }
        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        //here we have to find the minimum or small number by dividing the nums
        //we will get the *total individual sum <= threshold (6 in this case)
        int maxi = *max_element(nums.begin(),nums.end());
        int ans= -1;
        int low = 1;
        int high = maxi;
        while(low<=high){
            int mid = (low + high)/2;
            int total = findTotal(mid,nums,threshold);

            if(total<= threshold){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};