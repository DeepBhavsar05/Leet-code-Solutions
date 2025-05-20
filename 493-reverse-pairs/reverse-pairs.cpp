class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp;
        int left = low;
        int right= mid+1;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }
    int countPairs(vector<int>& nums,int low,int mid,int high){
        int right = mid+1;
        int cnt =0;
        for(int i=low;i<=mid;i++){
            while(right<=high && (long long)nums[i] > 2LL*nums[right]) right++;
            cnt +=(right-(mid+1));
        }
        return cnt;
    }
    int mergeSort(vector<int>& nums, int low, int high){
        //base case
        int cnt = 0;
        if(low>=high) return cnt;
        int mid = (low+high)/2;
        //left half
        cnt += mergeSort(nums,low,mid);
        //right half
        cnt += mergeSort(nums,mid+1,high);
        cnt += countPairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        // this is a naive solution ---> O(n^2)
        int n = nums.size();
        // int count = 0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]>2*nums[j]) count++;
        //     }
        // }
        // return count;
        return mergeSort(nums,0,n-1);
    }
};