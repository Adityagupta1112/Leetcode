class Node{
public:
    unordered_map<char,Node*>children;
    int freq;
    bool endOfWord;
    Node(){
        endOfWord=false;
    }
};
class Trie{
public:
    Node*root;

    Trie(){
        root=new Node();
        root->freq=-1;
    }
    void insert(string key){
        Node*temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]=new Node();
                temp->children[key[i]]->freq=1;
            }
            else{
                temp->children[key[i]]->freq++;
            }
            temp=temp->children[key[i]];
        }
        temp->endOfWord=true;
    }
    string countPref(Node*root,string&ans,int n){
        for(auto child:root->children){
            if(child.second->freq==n){
                ans+=child.first;
                countPref(child.second,ans,n);
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        Trie trie;
        for(int i=0;i<n;i++){
            trie.insert(strs[i]);
        }
        Node*root=trie.root;
        return trie.countPref(root,ans,n);
    }
};