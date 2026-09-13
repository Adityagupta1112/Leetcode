class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        sort(begin(nums),end(nums));
        int n=nums.size();
        for(int i=0;i<n;i+=3){
            vector<int>temp;
            temp.push_back(nums[i]);
            for(int j=1;j<3;j++){
                int diff=nums[i+j]-temp[0];
                if(diff<=k){
                    temp.push_back(nums[i+j]);
                }
            }
            if(temp.size()==3){
                ans.push_back(temp);
            }
            else{
                return {} ;
            }
        }
        return ans;
    }
};