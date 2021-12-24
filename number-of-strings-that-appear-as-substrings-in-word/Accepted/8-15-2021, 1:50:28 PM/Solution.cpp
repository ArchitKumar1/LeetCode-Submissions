// https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        int n = word.size();
        for(string p : patterns){
            bool done = 0;
            for(int i = 0;i < n;i++){
                for(int j = i;j < n;j++){
                    if(p == word.substr(i,j-i+1) && !done){
                        ans += 1;
                        done = 1;
                    }
                }
            }
        }
        return ans;
    }
};