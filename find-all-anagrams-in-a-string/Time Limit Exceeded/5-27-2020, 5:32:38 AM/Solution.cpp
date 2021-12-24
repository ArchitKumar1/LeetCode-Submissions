// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();
        
        sort(p.begin(),p.end());
        for(int i =0;i+m-1<n;i++){
            string t = s.substr(i,m);
            sort(t.begin(),t.end());
            if(t == p)ans.push_back(i);
        }
        return ans;
    }
};