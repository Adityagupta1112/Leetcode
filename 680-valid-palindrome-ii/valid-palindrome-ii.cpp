class Solution {
public:
    bool helper(int i,int j,string &s){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return helper(i+1,j,s) || helper(i,j-1,s);
            }
            i++;
            j--;
        }
        return true;
    }
};