class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //this is optimal approach with sc=O(1)
    //     int left = m-1;
    //     int right = 0;
    //     while(left > 0 && right < n-1){
    //         if(nums1[left]>nums2[right]){
    //             swap(nums1[left],nums2[right]);
    //             left--;
    //             right++;
    //         }
    //         else break;
    //     }
    //     int it=0;
    //     while(it<nums2.size()){
    //         nums1[m++] = nums2[it++];
    //     }
    //     sort(nums1.begin(),nums1.end());
    // }
    //chatgpt approach
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // Copy remaining elements of nums2 (if any)
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    //Follow up: Can you come up with an algorithm that runs in O(m + n) time?
        // int i=0;
        // int j=0;
        // int index=0;
        // vector<int> nums3(m+n);
        // while(i<m && j<n){
        //     if(nums1[i]<=nums2[j]){
        //         nums3[index]=nums1[i];
        //         i++;
        //         index++;
        //     }
        //     else{
        //         nums3[index]=nums2[j];
        //         j++;
        //         index++;
        //     }
        // }
        // //if there is still some elements in nums1
        // while(i<m){
        //     nums3[index++]=nums1[i++];
        // }
        // //if there is still some elements in nums2
        // while(j<n){
        //     nums3[index++]=nums2[j++];
        // }
        // for(int i=0;i<nums1.size();i++){
        //     nums1[i]= nums3[i];
        // }
    }
};