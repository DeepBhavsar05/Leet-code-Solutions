class Solution {
public:

    bool fun(vector<int>& position, int given_balls, int mid){
        int current_ball = position[0];
        int ball = 1;

        for(int i=1;i<position.size();i++){
            if(position[i]-current_ball >= mid){
                current_ball = position[i];
                ball++;
            }
            if(ball >= given_balls) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        // this is simmilar to aggresive cows problem
        // here we have to find max() of all the minimum posibility to put all the balls
        // first we sort the given positions so that we can get minimum values consequetly
        sort(position.begin(),position.end());
        //here we have to find minimum at every given position by putting balls one by one on that distance
        //first we start with first ball by putting it on the first position and then will put second ball on the next position

        int n = position.size();
        int low = 1;
        int high = *max_element(position.begin(),position.end());
        int ans = -1;

        while(low<=high){
            int mid = (low+high)/2;
            int isPossible = fun(position, m, mid);

            if(isPossible == true){
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