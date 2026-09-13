class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        for(int i=0;i<n;i+=3){
            int count=0;
            for(int j=0;j<3;j++){
                int diff=nums[i+j]-nums[i];
                if(diff<=k){
                    count++;
                }
            }
            if(count<3){
                return {} ;
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i+=3){
            vector<int>temp;
            for(int j=0;j<3;j++){
                temp.push_back(nums[i+j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};