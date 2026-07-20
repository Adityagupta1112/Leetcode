class Solution {
public:
    int n;
    void solve(int idx,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        ans.push_back(temp);
        for(int i=idx;i<n;i++){
            temp.push_back(nums[i]);
            solve(i+1,nums,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,nums,temp,ans);
        return ans;
    }
};