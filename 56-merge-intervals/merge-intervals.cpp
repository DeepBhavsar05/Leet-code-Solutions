class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //this one is *better or brute* solution with TC of nlogn + 2n (bcz I used break and continue keywords)
        // int n = intervals.size();
        // vector<vector<int>> ans;
        // sort(intervals.begin(),intervals.end());
        // for(int i=0;i<n;i++){
        //     int start = intervals[i][0];// first element of first row
        //     int end = intervals[i][1];//second element or last element of first row
        //     if(!ans.empty() && end <= ans.back()[1]) continue;
        //     for(int j= i+1;j<n;j++){
        //         //here I have used j=i+1 for next row in the array
        //         if(intervals[j][0] <= end)
        //         {
        //             end = max(end,intervals[j][1]);
        //         }
        //         else break;//this break will only executed when 2nd element of intervals(given array) is less than next element's first element
        //     }
        //     ans.push_back({start,end});
        // }
        // return ans;
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        //in optimal approach we can take first vector as a answer and then I will move in given array
        for(int i=0;i<n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
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