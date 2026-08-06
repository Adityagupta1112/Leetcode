class Solution {
public:
    bool helper(int n,int t){
        int product=1;
        while(n>0){
            int rem=n%10;
            n=n/10;
            product*=rem;
        }
        if(product%t==0){
            return true;
        }
        return false;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            if(helper(i,t)){
                return i;
            }
        }
        return -1;
    }
};