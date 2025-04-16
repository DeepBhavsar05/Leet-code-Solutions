//#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                set<long long> hashst;//keep i and j constant and move k for checking
                for(int k=j+1;k<n;k++){
                    long long sum = nums[i] + nums[j];
                    sum = sum+nums[k];
                    long long fourth = target - (sum);
                    if(hashst.find(fourth)!= hashst.end()){
                        vector<int> temp = {nums[i],nums[j],nums[k],int(fourth)};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    hashst.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};