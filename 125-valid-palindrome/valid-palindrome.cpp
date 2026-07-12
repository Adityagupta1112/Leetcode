class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(char ch:s){
            if(!isalnum(ch)){
                continue;
            }
            ch=tolower(ch);
            str.push_back(ch);
        }
        int i=0;
        int j=str.size()-1;

        while(i<=j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};