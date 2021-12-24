// https://leetcode.com/problems/second-largest-digit-in-a-string

class Solution {
public:
    int secondHighest(string s) {
        
        vector<int> ans;
        map<int,int> m1;
        
        for(char c : s){
            if( c>='1'&& c<='9'){
                if(m1[c] == 0)
                    ans.push_back(c-'0');
                m1[c] = 1;
            }
        }
        sort(ans.begin(),ans.end());
        
        if(ans.size() <= 1){
            return -1;
        }
        return ans[1];
    }
};