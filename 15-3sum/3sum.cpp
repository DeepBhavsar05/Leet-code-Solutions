//here in question they mentioned that output should be vector<vector<int>>, we will store vector
//============brute============:
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // int n= nums.size();
        // set<vector<int>> st;//adding vector in set data structure so that unique values should be added
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k = j+1; k<n;k++){
        //             if(nums[i]+nums[j]+nums[k] == 0){
        //                 vector<int> temp = {nums[i],nums[j],nums[k]};
        //                 sort(temp.begin(),temp.end());
        //                 st.insert(temp);
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> ans(st.begin(),st.end());//ans will store start to end of st set watch stl video or read it because vector is initialized like this: vector<int> v(1,1) //op:{1,1}
        // return ans;
//========better============hashing=======:
        // int n= nums.size();
        // set<vector<int>> st;
        // for(int i=0;i<n;i++){
        //     set<int> hashset;//using this for storing elements from i ---> j //not i and j in hashset
        //     for(int j=i+1;j<n;j++){
        //         int k = -(nums[i]+nums[j]);
        //         if(hashset.find(k)!= hashset.end()){
        //             vector<int> temp = {nums[i],nums[j],k};//same as above i have to find k(third element) in set and add that into the temp
        //             sort(temp.begin(),temp.end());
        //             st.insert(temp);
        //         }
        //         hashset.insert(nums[j]);//why? because we need inbetween elements of i and j in set to conduct serach for k(third element)
        //     }
        // }
        // vector<vector<int>> ans(st.begin(),st.end());// st is the answer but we are returning it in vector as they might be multiple and also op in question also mentioned this thing
        // return ans;
        int n= nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;//continue means do not go down increase the for loop's i and go on
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+ nums[j]+nums[k];
                if(sum<0) j++;
                else if(sum>0) k--;
                else{
                    vector<int> temp ={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);//already sorted so dont need to sort like other 2 solutions
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++;//this is because if there are 2 elements(j-1,j so to maintain this error) 
                    while(j<k && nums[k] == nums[k+1]) k--;//this is because if there are 2 elements(j-1,j so to maintain this error) 
                }
            }
        }
        return ans;
    }
};