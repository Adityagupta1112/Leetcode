class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        vector<char>temp;
        int i=0;
        while(i<n){
            char ch=chars[i];
            int j=i+1;
            while(j<n && chars[j]==ch){
                j++;
            }
            int diff=j-i;
            if(diff>1){
                string str=to_string(diff);
                temp.push_back(ch);
                for(char s:str){
                    temp.push_back(s);
                }
            }
            else{
                temp.push_back(ch);
            }
            i=j;
        }
        chars=temp;
        return chars.size();
    }
};