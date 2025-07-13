class Solution {
public:
// this is brute force code by doing linear search in mini --> maxi
// implementing function in public
    int findDays(int capacity,vector<int>& weights){
        int total_days = 1;
        int total_load_capacity = 0;

        for(int i=0;i<weights.size();i++){
            int check_load = total_load_capacity + weights[i];
            if(check_load > capacity){
                // total_load_capacity exceeded on working day then we will m ove to next day
                total_days += 1;
                // and for next day we will start from the current capacity
                total_load_capacity = weights[i];  
            }
            else{
                // if i am in the capacity then i will load the weight on same day
                total_load_capacity += weights[i];
            }
        }
        return total_days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        //here we have to find maximum capacity of ship
        //which is total of all weight
        //minimum should be = max of given weights
        //if in 1 day he will ship 10 kg
        //then it will take 1+2+3+4(10kg) = day1
        //5kg = day2 // we can not execed 10kg, if we do (5+6) which exceeded 10kg
        //6kg = day3
        //7kg = day4
        //8kg = day5 // but we have to ship in 5 days(given in quetion)
        //9kg = day6
        //10kg = day7 = total days
        //now we need to increase weight to ship in given days(TO DECREASE THE DAYS FOR SHIPPING)
        // first of all we have to find minimum value of weight to be delivered
        // which is 10 otherwise not all of the items delivered
        // the maximum items(weights) to be delivered is total of all the items and which will be 
        // delivered in just 1 days as capacity is full
        // here we have to find that capacity as minimum as we can whitin given days( here days = 5)

        //using BS on answers as we have to find linearly in sorted manner
        // defining range for binary search on answers
        // here we have to find that capacity as minimum as we can whitin given days( here days = 5)
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2; // always use bracket here 
            int daysReq = findDays(mid,weights);// calling function for days
            
            if(daysReq <= days){
                // que: Return the least weight capacity, so we will check for more smaller capacity
                // days is low then capacity should be high
                // days should high then capacity should be low
                ans = mid; // Possible answer, try to minimize
                high = mid -1;
            }
            else{
                low = mid +1;
                // in else: we are using more days than the given days so if we will increase the capacity 
                // that would be decrease the days
            }
        }
        return ans;
        // this for loop is for counting days using minimum weight and maximum weight
        //our answer lies b/w mini to maxi for sure
        // by using this values we can check for every posible values in-between
        // for(int i = mini; i<= total;i++){
        //     // here i  =  capacity of ship
        //     int daysReq = findDays(i,weights);// calling function for days
        //     if(daysReq <= days){
        //         return i;
        //     }
        // }
        // return -1;
    }
};