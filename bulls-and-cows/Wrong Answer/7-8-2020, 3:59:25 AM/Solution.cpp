// https://leetcode.com/problems/bulls-and-cows

class Solution {
public:
    string getHint(string s, string g) {
        int x = 0;
        int y = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == g[i]){
                x += 1;
            }else{
                y++;
            }
        }
        string ans = to_string(x) + "A" + to_string(y) + "B";
        return ans;
    }
};