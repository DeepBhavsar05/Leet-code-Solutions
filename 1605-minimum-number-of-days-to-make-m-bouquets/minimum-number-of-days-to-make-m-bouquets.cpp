class Solution {
public:
    //here we check which which adjucent bouquets are bloomed and check with m
    bool flowerBloomOrNot(vector<int>& bloomDay, int NoofBouqets, int OneBatchflowerpots, int day){
        //here the taken day is a day which i am looking for
        int cnt = 0;
        int n = bloomDay.size();
        int noOfbouq = 0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day){
                cnt = cnt+1;
            }
            else{
                noOfbouq += (cnt/OneBatchflowerpots);//this is number of consequtive flower bouquet to check that k=3(OneBatchflowerpots) condition
                //by dividing with k(OneBatchflowerpots) we will get how many no of bouquets we should create
                cnt = 0;// this is point where flower is not bloomed so counter should again be zero
            }
        }
        //this is because we need to check again after cnt=0 so we already have no of bouq from previous count and here we will add new counter value if it exists
        noOfbouq +=(cnt/OneBatchflowerpots); // here noOfbouq is the counted by using this fun
        if(noOfbouq >= NoofBouqets) return true; //NoofBouqets is m here
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        //here m = total numbers of adjacent bouquets
        //k = required flower in 1 batch of flower pot
        long long total = 1LL * m * k;
        if (bloomDay.size() < total) return -1; //Not enough flowers

        int mini = *min_element(bloomDay.begin(),bloomDay.end());
        int maxi = *max_element(bloomDay.begin(),bloomDay.end());

        //we start from minimum day and end to last day(max day) 
        //where all the flowers will be bloomed --> Maximum_value(highest day)
        // for(int i=mini;i<=maxi;i++)
        int low = mini;
        int high = maxi;
        int ans = -1;

        while(low<=high){
            int mid = (low+high)/2;
            bool Flower_bloom = flowerBloomOrNot(bloomDay,m,k,mid);
            //it will return true or false in given range of days
            if(Flower_bloom == true){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};