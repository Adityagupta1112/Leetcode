class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                int s1=arr1.size();
                int s2=arr2.size();
                if(s1==0){
                    arr1.push_back(nums[i]);
                }
                else{
                    if(arr1[s1-1]>arr2[s2-1]){
                        arr1.push_back(nums[i]);
                    }
                    else{
                        arr2.push_back(nums[i]);
                    }
                }
            }
            else{
                int s1=arr1.size();
                int s2=arr2.size();
                if(s2==0){
                    arr2.push_back(nums[i]);
                }
                else{
                    if(arr2[s2-1]>arr1[s1-1]){
                        arr2.push_back(nums[i]);
                    }
                    else{
                        arr1.push_back(nums[i]);
                    }
                }
            }
        }
        vector<int>ans;
        for(int v:arr1){
            ans.push_back(v);
        }
        for(int v:arr2){
            ans.push_back(v);
        }
        return ans;
    }
};