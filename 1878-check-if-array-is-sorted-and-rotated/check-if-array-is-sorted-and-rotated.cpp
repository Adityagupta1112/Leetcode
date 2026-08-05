class Solution {
public:
    bool isSorted(vector<int>&nums){
        int prev=-1;
        for(int v:nums){
            if(prev>v){
                return false;
            }
            prev=v;
        }
        return true;
    }
    bool check(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(isSorted(nums)){
                return true;
            }
            int st=nums[0];
            for(int j=0;j<n-1;j++){
                nums[j]=nums[j+1];
            }
            nums[n-1]=st;
        }
        return false;
    }
};