class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m-1;
        int right = 0;
        while(left > 0 && right < n-1){
            if(nums1[left]>nums2[right]){
                swap(nums1[left],nums2[right]);
                left--;
                right++;
            }
            else break;
        }
        // if(n!=0){
        //     for(int i=n;i<nums1.size();i++){
        //         nums1[i] = nums2[i-m];
        //     }
        // }
        int it=0;
        while(it<nums2.size()){
            nums1[m++] = nums2[it++];
        }
        sort(nums1.begin(),nums1.end());
    }
};