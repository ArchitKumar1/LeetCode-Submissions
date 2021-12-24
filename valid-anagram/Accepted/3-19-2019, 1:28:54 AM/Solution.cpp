// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int a[128]={0},b[128]={0};
        for(int i=0;i<s.size();i++){
            a[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            b[t[i]]++;
        }
        for(int i=0;i<128;i++){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
};