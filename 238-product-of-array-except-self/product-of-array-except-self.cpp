class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct=1;
        int n=nums.size();
        int zero=0;
        vector<int>result(n,0);
        for(int num:nums){
            if(num==0){
                zero++;
                continue;
            }
            totalProduct*=num;
        }
        for(int i=0;i<n;i++){
            if(zero>1){
                return result;
            }
            if(zero==1){
                if(nums[i]==0){
                    result[i]=totalProduct;
                }
                else{
                    result[i]=0;
                }
            }
            else{
                result[i]=totalProduct/nums[i];
            }
        }
        return result;
    }
};