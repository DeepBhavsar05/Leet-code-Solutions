class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> intervals_final;
        // I can also use same vector(intervals in this case) and simply append/push_back newInterval to that and then so on...
        //intervals.push_back(newInterval);//then direct go to the sort line 9
        intervals_final = intervals;
        intervals_final.push_back(newInterval);
        sort(intervals_final.begin(),intervals_final.end());//<----------here
        int n = intervals_final.size();
        vector<vector<int>> ans;
        //in optimal approach we can take first vector as a answer and then I will move in given array
        for(int i=0;i<n;i++){
            int start = intervals_final[i][0];
            int end = intervals_final[i][1];
            if(ans.empty()) ans.push_back({start,end});// || intervals[i][0] > ans.back()[1] if I have only one element in my ans and the condition fulfilled so it will created new vector in ans 
            else if(!ans.empty() && start <= ans.back()[1]){
                ans.back()[1] = max(end,ans.back()[1]);
            }
            else{
                ans.push_back({start,end});
            }
        }
        return ans;
    }
};