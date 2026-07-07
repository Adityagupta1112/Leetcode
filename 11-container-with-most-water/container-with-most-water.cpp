class Solution {
public:
    int ans=0;
    int leftmax=0;
    int rightmax=0;
    void helper(int leftIdx,int rightIdx){
        if(leftIdx!=-1 && rightIdx!=-1){
            int breath=min(leftmax,rightmax);
            int length=rightIdx-leftIdx;
            int area=breath*length;
            ans=max(ans,area);
        }
    }
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int leftmaxIdx=-1;
        int rightmaxIdx=-1;
        while(i<=j){
            if(leftmax<rightmax){
                if(leftmax<height[i]){
                    leftmax=height[i];
                    leftmaxIdx=i;
                }
                helper(leftmaxIdx,rightmaxIdx);
                i++;
            }
            else{
                if(rightmax<height[j]){
                    rightmax=height[j];
                    rightmaxIdx=j;
                }
                helper(leftmaxIdx,rightmaxIdx);
                j--;
            }
        }
        return ans;
    }
};