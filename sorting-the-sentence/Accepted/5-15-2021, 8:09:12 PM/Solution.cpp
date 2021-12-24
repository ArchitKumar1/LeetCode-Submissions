// https://leetcode.com/problems/sorting-the-sentence

class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        string word;
        vector<string> v;
        while (ss >> word) {
            v.push_back(word);
        }
        sort(v.begin(),v.end(),[&](string &a,string &b){
            return a.back() < b.back();
        });
        string ans;
        for(string x : v){
            x.pop_back();
            ans += x;
            ans += " ";
        }
        ans.pop_back();
        return ans;

    }
};