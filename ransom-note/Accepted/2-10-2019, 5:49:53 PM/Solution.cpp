// https://leetcode.com/problems/ransom-note

#include <map>
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[128]={0};
        if(ransomNote.size()>magazine.size()) return false;
        
        for(int i=0;i<magazine.size();i++) count[magazine[i]]++;
        for(int i=0;i<ransomNote.size();i++) count[ransomNote[i]]--;
        for(int i=0;i<128;i++) if(count[i]<0) return false;
        return true;
    }
};