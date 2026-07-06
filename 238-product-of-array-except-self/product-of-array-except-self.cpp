class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int zero=0;
        vector<int>prefixProd(n,1);
        vector<int>suffixProd(n,1);

        for(int i=0;i<n;i++){
            if(i==0){
                prefixProd[i]=1;
                suffixProd[n-i-1]=1;
            }
            else{
                prefixProd[i]=prefixProd[i-1]*nums[i-1];
                suffixProd[n-1-i]=suffixProd[n-i]*nums[n-i];
            }
        }
        
        for(int i=0;i<n;i++){
            nums[i]=prefixProd[i]*suffixProd[i];
        }
        return nums;
    }
};