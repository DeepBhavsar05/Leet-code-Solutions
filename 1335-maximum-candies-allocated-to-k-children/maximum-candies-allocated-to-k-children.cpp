class Solution {
public:

    long long totalChild(int mid,vector<int>& candies){
        long long total_child = 0;// total_child_after_giving_candies
        for(int i=0;i<candies.size();i++){
            total_child = total_child + candies[i]/mid;// it must be less or eqaul to k in this 1st case: <=3
        }
        return total_child;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        //here we have given 5,8,6 which are piles of candies 
        // k is students available
        // we need x which is the total maximun candies per student candies/student
        int ans = 0;
        long long maxi = *max_element(candies.begin(),candies.end());
        int low = 1;
        int high = maxi;
        // que ask us to find the maximum number of candies by which we can give equal number of candies
        // to every given child
        // so we can use maximum piles as it might be our answer but 
        //side by side we also have to take care of the thing that we also fulfill all children(k)
        //our goal is to find that number by which we can give equal candies to ebery child
        while(low<=high){
            int mid = low + (high -low)/2;

            long long total_child = totalChild(mid,candies);

            if(total_child >= k){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }

        }
        return ans;
    }
};