class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>freq;
        int sum=0;
        for(char ch:chars){
            if(freq.count(ch)){
                freq[ch]++;
            }
            else{
                freq[ch]=1;
            }
        }
        for(int i=0;i<words.size();i++){
            string str=words[i];
            bool good=true;
            unordered_map<char,int>mp=freq;
            for(char ch:str){
                if(!mp.count(ch) || mp[ch]<=0){
                    good=false;
                    break;
                }
                mp[ch]--;
            }
            if(good){
                sum+=str.size();
            }
        }
        return sum;
    }
};