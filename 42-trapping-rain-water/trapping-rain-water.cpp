class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int left_max=0;
        int right_max=0;
        int totalTrapWater=0;
        while(i<=j){
            if(left_max<right_max){
                left_max=max(left_max,height[i]);
                int curr=left_max-height[i];
                totalTrapWater+=curr;
                i++;
            }
            else{
                right_max=max(right_max,height[j]);
                int curr=right_max-height[j];
                totalTrapWater+=curr;
                j--;
            }
        }
        return totalTrapWater;
    }
};