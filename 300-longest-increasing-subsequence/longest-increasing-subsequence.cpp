class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>result;
        for(int i=0;i<n;i++){
            if(result.size()==0){
                result.push_back(nums[i]);
            }
            else{
                bool fixed=false;
                for(int k=0;k<result.size();k++){
                    if(result[k]>=nums[i]){
                        result[k]=nums[i];
                        fixed=true;
                        break;
                    }
                }
                if(!fixed){
                    result.push_back(nums[i]);
                }
            }
        }
        return result.size();
    }
};