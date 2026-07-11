class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n=nums.size();
        int flip=k;
        int ans=0;
        while(j<n){
            if(nums[j]==0){
                flip--;
            }
            while(flip<0 && nums[j]==0){
                ans=max(ans,j-i);
                if(nums[i]==0){
                    flip++;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};