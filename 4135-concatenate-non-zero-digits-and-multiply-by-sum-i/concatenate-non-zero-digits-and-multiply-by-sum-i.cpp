class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int>arr;
        while(n>0){
            int rem=n%10;
            n=n/10;
            arr.push_back(rem);
        }
        // int rem=n%10;
        // n=n/10;
        // arr.push_back(rem);
        // arr.push_back(n);
        reverse(arr.begin(),arr.end());
        long long x=0;
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                continue;
            }
            sum+=arr[i];
            x*=10;
            x+=arr[i];
        }
        return x*sum;
    }
};