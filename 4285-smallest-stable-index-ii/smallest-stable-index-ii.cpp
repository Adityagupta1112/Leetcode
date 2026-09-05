class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>temp(n);
        temp[n-1]=nums[n-1];
        int max_val=INT_MIN;
        for(int i=n-2;i>=0;i--){
            temp[i]=min(temp[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            max_val=max(max_val,nums[i]);
            if(max_val-temp[i]<=k){
                return i;
            }
        }
        return -1;
    }
};