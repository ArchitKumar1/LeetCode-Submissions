// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    struct trie{
        trie * child[26];
        int val = 0;
    };
    void add(string a,trie* root){
        for(char c : a){
            c = c-'a';
            if(root->child[c]){
                root = root->child[c];
               
            }else{
                root->child[c] = new trie();
                root = root->child[c];
            }
             root->val +=1;
        }
    }
    string maxans = "";
    int maxlen = 0;
    int n;
    void dfs(trie* root,string curr = ""){
        if(root->val == n){
            if(maxlen< curr.size()){
                maxlen = curr.size();
                maxans = curr;
            }
        }
        for(int i=0;i<26;i++){
            if(root->child[i]){
                char naya = 'a' + i;
                dfs(root->child[i],curr + naya);
                
            }
        }
    }
    string longestCommonPrefix(vector<string>& strs) {
        n = strs.size();
        trie * root = new trie();
        for(string x : strs){
            add(x,root);
        }
        
        dfs(root);
        return maxans;
        
    }
};