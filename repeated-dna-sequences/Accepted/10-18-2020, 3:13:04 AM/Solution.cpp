// https://leetcode.com/problems/repeated-dna-sequences

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        map<string,int> m1;
        vector<string> ans;
        for(int i = 0;i+9<n;i++){
            string t = s.substr(i,10);
            m1[t]++;
        }
        for(auto x : m1){
            if(x.second > 1) ans.push_back(x.first);
        }
        return ans;
    }
};