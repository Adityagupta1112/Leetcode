class Solution {
public:
    bool isPalindrome(int x) {
        string str=to_string(x);
        int n=str.size();
        int st=0;
        int en=n-1;
        while(st<en){
            if(str[st]==str[en]){
                st++;
                en--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};