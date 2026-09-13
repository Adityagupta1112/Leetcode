class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int>s;
        for(int val:nums){
            s.insert(val);
        }
        for(int i=0;i<=s.size();i++){
            if(!s.count(i)){
                return i;
            }
        }
        return -1;
    }
};