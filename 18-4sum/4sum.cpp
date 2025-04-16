//this is a better solution which uses hashing to solve better then brute
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // int n = nums.size();
        // set<vector<int>> st;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         set<long long> hashst;//keep i and j constant and move k for checking
        //         for(int k=j+1;k<n;k++){
        //             long long sum = nums[i] + nums[j];
        //             sum = sum+nums[k];
        //             long long fourth = target - (sum);
        //             if(hashst.find(fourth)!= hashst.end()){
        //                 vector<int> temp = {nums[i],nums[j],nums[k],int(fourth)};
        //                 sort(temp.begin(),temp.end());
        //                 st.insert(temp);
        //             }
        //             hashst.insert(nums[k]);
        //         }
        //     }
        // }
        // vector<vector<int>> ans(st.begin(),st.end());
        // return ans;
        int n = nums.size();
        vector<vector<int>> ans;
        //set<int> st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j != i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1;
                int l = n-1;
                while(k<l){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        //this should definitely our answer
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]== nums[k-1])k++;//if after adding the elememnts to vector k is equal to last element we dont need to compare same elements so we just move ahead
                        while(k<l && nums[l]== nums[l+1])l--;//if after adding the elememnts to vector l is equal to last element
                    }
                    else if(sum<target) k++;
                    else l--;
                }

            }
        }
        return ans;
    }
};