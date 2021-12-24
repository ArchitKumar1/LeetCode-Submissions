// https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> a(26),b(26);
        for(int c : word1) a[c-'a']++;
        for(int c : word2) b[c-'a']++;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i =0;i<26;i++){
            if(a[i]!=b[i])return 0;
            
        }
        return 1;
    }
};