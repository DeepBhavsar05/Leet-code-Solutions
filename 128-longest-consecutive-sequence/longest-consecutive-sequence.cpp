class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // int longest = 1;
        // int curr_cnt = 0;
        // int lastsmallest = INT_MIN;
        // for(int i=0;i<n;i++){
        //     if(nums[i]-1 == lastsmallest){
        //         curr_cnt = curr_cnt+1;
        //         lastsmallest = nums[i];
        //     }
        //     else if(nums[i] == lastsmallest) continue;
        //     else if(nums[i] != lastsmallest){
        //         curr_cnt = 1;
        //         lastsmallest = nums[i];
        //     }
        //     longest = max(longest,curr_cnt);
        // }
        // return longest;
        //this is optimal option
        unordered_set<int> st;
        int n = nums.size();
        if(n==0) return 0;
        int longest = 1;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it:st){
            if(st.find(it-1) == st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    x = x+1;
                    cnt = cnt + 1;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};