class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        int count = 1;
        string ans = "";
        ans.push_back(s[0]);

        for(int i=1;i<n;i++){
            if(s[i] == s[i-1]){
               count++;
            }
            else{
                count = 1;
            }
            if(count<3) ans.push_back(s[i]);
        }
        return ans;
    }
};