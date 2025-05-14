class Solution {
public:
    int maxArea(vector<int>& height) {
        //using basic math formula Lenght*Width
        //here we need min otherwise water might overflow
        //brute-force approach
        // int n = height.size();
        // int max_hight = INT_MIN;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int contain = min(height[i],height[j])*(j-i);
        //         max_hight = max(max_hight,contain);
        //     }
        // }
        // return max_hight;
        //Optimal approach ---- Two pointer
        int n = height.size();
        int left = 0;
        int right = n-1;
        int max_area = INT_MIN;
        while(left<right){
            int min_height = min(height[left],height[right]);
            int width = right - left;
            int area = min_height*width;
            max_area = max(max_area,area);
            if(height[left]<height[right]){
                left++;//as we are depending on minimum so we need to move our minimum ahead to find next minimum
            }
            else{
                right--;//else means height[left]>height[right] or both are equal
            }
        }
        return max_area;
    }
};