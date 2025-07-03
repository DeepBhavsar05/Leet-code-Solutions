class Solution {
public:
    bool totalQuantity(int mid,vector<int>& quantities,int shop){
        int totalShop = 0;
        for(int i=0;i<quantities.size();i++){
            totalShop = totalShop + ceil(double(quantities[i])/double(mid));
        }
        if(totalShop<=shop) return true;
        else return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        //here n = total shops
        //we need total(ceil(quantities[i]/x)<=n//here x is value of quantity of product
        int m = quantities.size();//total products ---> pro0, pro1, pro2....proN
        //using binary search
        int low = 1;
        int high = *max_element(quantities.begin(),quantities.end());
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2; //x
            int totalQuant = totalQuantity(mid,quantities,n);

            if(totalQuant == true){
                ans = mid;// it might be our answer
                high = mid-1;// lets check if we can find smaller as asked in question  **minimum possible x**
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};