class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int ans=0;
        int leftmax=0;
        int rightmax=0;
        while(i<=j){
            leftmax=max(leftmax,height[i]);
            rightmax=max(rightmax,height[j]);
            if(leftmax<rightmax){
                ans=max(ans,leftmax*(j-i));
                i++;
            }
            else{
                ans=max(ans,rightmax*(j-i));
                j--;
            }
        }
        return ans;
    }
};