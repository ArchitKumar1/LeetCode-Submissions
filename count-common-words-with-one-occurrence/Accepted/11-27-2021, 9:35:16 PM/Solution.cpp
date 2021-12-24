// https://leetcode.com/problems/count-common-words-with-one-occurrence

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string,pair<int,int>> m1;
        for(string s : words1) m1[s].first++;
         for(string s : words2) m1[s].second++;
        int ans = 0;
        for(auto[k,v]:m1){
            ans += (v.first == 1 && v.second == 1);
        }
        return ans;
    }
};