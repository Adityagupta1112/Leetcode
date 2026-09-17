class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0;
        int sum=0;
        vector<int>minLength(n,INT_MAX);
        int bestminLen=INT_MAX;

        int ans=INT_MAX;

        for(int j=0;j<n;j++){
            sum+=arr[j];
            while(sum>target){
                sum-=arr[i];
                i++;
            }
            if(sum==target){
                int len=j-i+1;
                if(i>0 && minLength[i-1]!=INT_MAX){
                    ans=min(ans,len+minLength[i-1]);
                }
                bestminLen=min(bestminLen,len);
            }
            minLength[j]=bestminLen;
        }
        return ans==INT_MAX?-1:ans;
    }
};