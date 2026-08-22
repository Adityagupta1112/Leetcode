class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int m=n;
        while(n>0){
            int rem=n%10;
            n=n/10;
            sum+=rem;
            product*=rem;
        }
        int finalSum=sum+product;
        if(m%finalSum==0){
            return true;
        }
        return false;
    }
};