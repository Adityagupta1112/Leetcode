class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        stack<int>s;
        int count=0;
        int n=nums.size();
        for(int val:nums){
            while(s.size()>0 && s.top()==val){
                s.pop();
            }
            s.push(val);
        }
        for(int i=0;i<n;i++){
            nums.pop_back();
        }
        while(!s.empty()){
            nums.push_back(s.top());
            count++;
            s.pop();
        }
        sort(nums.begin(),nums.end());
        return count;
    }
};