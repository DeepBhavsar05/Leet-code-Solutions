class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++){
            int start = intervals[i][0];// first element of first row
            int end = intervals[i][1];//second element or last element of first row
            if(!ans.empty() && end <= ans.back()[1]) continue;
            for(int j= i+1;j<n;j++){
                //here I have used j=i+1 for next row in the array
                if(intervals[j][0] <= end)
                {
                    end = max(end,intervals[j][1]);
                }
                else break;//this break will only executed when 2nd element of intervals(given array) is less than next element's first element
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};