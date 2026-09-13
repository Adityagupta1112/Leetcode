class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        if(nums[0]!=0){
            return 0;
        }
        if(nums[n-1]!=n){
            return n;
        }
        for(int i=0;i<n-1;i++){
            int diff=nums[i+1]-nums[i];
            if(diff>1){
                return nums[i]+1;
            }
        }
        return -1;
    }
};