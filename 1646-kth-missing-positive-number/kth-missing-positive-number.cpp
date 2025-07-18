class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // positive integers
        // sorted
        //increasing order
        // let say 
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=k) k++;
            else break;
        }
        return k;
        //lets do this in logN
        // using bs on answers
        int low =0;
        int high = arr.size()-1;

        while(low<=high){
            int mid = (low+high)/2;
            int current_missing = arr[mid] -(mid+1);//give us actual missing values till current element

            if(current_missing < k){
                low = mid+1;
            }
            else{
                high = mid - 1;
            }

            return high+1+k;//low+k
        }
    }
};