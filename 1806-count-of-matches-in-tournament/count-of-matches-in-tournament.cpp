class Solution {
public:
    int numberOfMatches(int n) {
        int no_of_matches=0;
        while(n>1){
            if(n%2==0){
                no_of_matches+=n/2;
                n=n/2;
            }
            else{
                no_of_matches+=(n-1)/2;
                n=(n-1)/2+1;
            }
        }
        return no_of_matches;
    }
};