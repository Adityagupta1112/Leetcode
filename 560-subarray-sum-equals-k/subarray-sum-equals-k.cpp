class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix(n);
        int count=0;
        unordered_map<int,int>m;
        m[0]=1;
        for(int i=0;i<n;i++){
            if(i==0){
                prefix[i]=nums[i];
            }
            else{
                prefix[i]=prefix[i-1]+nums[i];
            }
        }
        
        for(int i=0;i<n;i++){
            int need=prefix[i]-k;
            if(m.count(need)){
                count+=m[need];
            }
            m[prefix[i]]++;
        }
        return count;
    }
};