class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        //if(n==1) return 0;
        //if( arr[0] > arr[1]) return 0;
        //if(arr[n-1] > arr[n-2]) return n-1;
        int low = 1;
        int high = n-2;
        while(low<=high){
            int mid = (low+high)/2;
            // if mid value is our answer
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
            // if mid is at left side --> nums[mid]>nums[mid-1] then its in increasing curve on graph
            // so our posibilty is on right side for peak element
            if(arr[mid] >arr[mid-1]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    return -1;
    }
};