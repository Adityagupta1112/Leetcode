class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int val1=nums[0]*nums[1];
        int val2=nums[n-2]*nums[n-1];
        return val2-val1;
    }
};