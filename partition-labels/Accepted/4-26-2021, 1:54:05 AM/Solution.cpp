// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        int  ans = 0,len = 0;
        vector<int> cnt(300);
        vector<int> res;
        for(char c : S){
            cnt[c]++;
        }
        set<char> s;
        
        for(char c : S){
            s.insert(c);
            cnt[c]--;
            if(cnt[c] == 0){
                s.erase(s.find(c));
            }
            len++;
            if(s.size() == 0){
                res.push_back(len);
                len = 0;
            }
        }
        return res;
    }
};