// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> a(26,0),b(26,0);
        for(char c :ransomNote ) a[c-'a']++;
        for(char c :magazine ) b[c-'a']++;
        bool ok = 1;
        for(int i =0;i<26;i++){
            ok &= b[i]>=a[i];
        }
        return ok;
    }
};