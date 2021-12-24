// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m1;
        vector<vector<string>> ans;
        for(string s : strs){
            string t = s;
            sort(t.begin(),t.end());
            m1[t].push_back(s);
        }
        for(auto x : m1){
            if(x.second.size()){
                ans.push_back(x.second);
            }
        }
        return ans;
    }
};