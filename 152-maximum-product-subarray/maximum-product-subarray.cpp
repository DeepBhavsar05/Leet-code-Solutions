class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // //this is extream brute force O(n^3)
        // int n= nums.size();
        // int max_product = INT_MIN;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         int product = 1;
        //         for(int k=i;k<=j;k++){
        //             product = product*nums[k];
        //         }
        //         max_product = max(product,max_product);//this is here because we are taking every posible subarray here so if we can out this condition inside k loop then it will updates in every iteration after product = product*nums[k]; this condition which we alredy have counted separately
        //     }
        // }
        // return max_product;
        //now by the observation we can perform this thing in O(n^2)//little better
        int n= nums.size();
        int max_product = INT_MIN;
        for(int i=0;i<n;i++){
            int product = 1;
            for(int j=i;j<n;j++){
                product = product*nums[j];
                max_product = max(product,max_product);
            }
        }
        return max_product;
    }
};