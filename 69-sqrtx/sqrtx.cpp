class Solution {
public:
    
    int mySqrt(int x) {
        // int ans = 1;
        // for(int i=0;i<=x;i++){
        //     if(i*i <= x){
        //         ans = i;
        //     }
        //     else break;
        // }
        // return ans;
        int low = 0;
        int high = x;
        int ans = 1;
        while(low<=high){
            long long mid = (low + high)/2;
            if(mid*mid <= x ){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};