// https://leetcode.com/problems/count-items-matching-a-rule

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0;
        
        vector<string> v = {"type", "color",  "name"};
        
        for(auto x : items){
            for(int i = 0;i<3;i++){
                if(ruleKey == v[i] && x[i] == ruleValue){
                    ans++;
                }
            }
        }
        return ans;
    }
};