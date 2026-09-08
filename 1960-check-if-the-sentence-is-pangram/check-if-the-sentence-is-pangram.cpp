class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool>visited(26,false);
        for(char ch:sentence){
            int idx=ch-'a';
            if(!visited[idx]){
                visited[idx]=true;
            }
        }
        for(int i=0;i<26;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};