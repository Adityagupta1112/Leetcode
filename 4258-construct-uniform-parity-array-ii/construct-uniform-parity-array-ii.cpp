class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int min_odd=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums1[i]%2!=0){
                min_odd=min(nums1[i],min_odd);
            }
        }
        for(int i=0;i<n;i++){
            if(min_odd!=INT_MAX && nums1[i]%2==0 && (nums1[i]-min_odd)<1){
                return false;
            }
        }
        return true;
    }
};